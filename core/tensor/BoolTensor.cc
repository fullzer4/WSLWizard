#include "BoolTensor.h"

Napi::FunctionReference BoolTensor::constructor;

Napi::Object BoolTensor::Init(Napi::Env env, Napi::Object exports) {
    Napi::Function func = DefineClass(env, "BoolTensor", {
        InstanceMethod("data", &BoolTensor::data),
    });

    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();
    exports.Set("BoolTensor", func);

    return exports;
}

BoolTensor::BoolTensor(const Napi::CallbackInfo& info) : Napi::ObjectWrap<BoolTensor>(info) {
    Napi::Env env = info.Env();

    if (info.Length() == 0 || !info[0].IsArray()) {
        Napi::TypeError::New(env, "Um array de booleanos é esperado como argumento").ThrowAsJavaScriptException();
        return;
    }

    Napi::Array dataArray = info[0].As<Napi::Array>();
    size_t size = dataArray.Length();

    torch::TensorOptions options = torch::TensorOptions().dtype(torch::kByte);
    tensor_ = torch::empty({static_cast<long>(size)}, options);

    for (size_t i = 0; i < size; i++) {
        bool value = dataArray.Get(i).ToBoolean();
        tensor_[i] = static_cast<uint8_t>(value);
    }
}

Napi::Value BoolTensor::data(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    torch::Tensor tensor = this->tensor_;
    size_t size = tensor.numel();

    Napi::Array dataArray = Napi::Array::New(env, size);

    for (size_t i = 0; i < size; i++) {
        dataArray.Set(i, Napi::Boolean::New(env, tensor[i].item<uint8_t>() != 0));
    }

    return dataArray;
}

