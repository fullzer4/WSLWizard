#include "ByteTensor.h"

Napi::FunctionReference ByteTensor::constructor;

Napi::Object ByteTensor::Init(Napi::Env env, Napi::Object exports) {
    Napi::Function func = DefineClass(env, "ByteTensor", {
        InstanceMethod("data", &ByteTensor::data),
    });

    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();
    exports.Set("ByteTensor", func);

    return exports;
}

ByteTensor::ByteTensor(const Napi::CallbackInfo& info) : Napi::ObjectWrap<ByteTensor>(info) {
    Napi::Env env = info.Env();

    if (info.Length() == 0 || !info[0].IsArray()) {
        Napi::TypeError::New(env, "Um array de números é esperado como argumento").ThrowAsJavaScriptException();
        return;
    }

    Napi::Array dataArray = info[0].As<Napi::Array>();
    size_t size = dataArray.Length();

    torch::TensorOptions options = torch::TensorOptions().dtype(torch::kUInt8);
    tensor_ = torch::empty({static_cast<long>(size)}, options);

    for (size_t i = 0; i < size; i++) {
        tensor_[i] = static_cast<uint8_t>(dataArray.Get(i).ToNumber().Uint32Value());
    }
}

Napi::Value ByteTensor::data(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    
    torch::Tensor tensor = this->tensor_;
    size_t size = tensor.numel();

    Napi::Array dataArray = Napi::Array::New(env, size);

    for (size_t i = 0; i < size; i++) {
        dataArray.Set(i, Napi::Number::New(env, static_cast<double>(tensor[i].item<uint8_t>())));
    }

    return dataArray;
}