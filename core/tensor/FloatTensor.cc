#include "FloatTensor.h"

Napi::FunctionReference FloatTensor::constructor;

Napi::Object FloatTensor::Init(Napi::Env env, Napi::Object exports) {
    Napi::Function func = DefineClass(env, "FloatTensor", {
        InstanceMethod("data", &FloatTensor::data),
    });

    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();
    exports.Set("FloatTensor", func);

    return exports;
}

FloatTensor::FloatTensor(const Napi::CallbackInfo& info) : Napi::ObjectWrap<FloatTensor>(info) {
    Napi::Env env = info.Env();

    if (info.Length() == 0 || !info[0].IsArray()) {
        Napi::TypeError::New(env, "Um array de números é esperado como argumento").ThrowAsJavaScriptException();
        return;
    }

    Napi::Array dataArray = info[0].As<Napi::Array>();
    size_t size = dataArray.Length();

    torch::TensorOptions options = torch::TensorOptions().dtype(torch::kFloat32);
    tensor_ = torch::empty({static_cast<long>(size)}, options);

    for (size_t i = 0; i < size; i++) {
        tensor_[i] = dataArray.Get(i).ToNumber().FloatValue();
    }
}

Napi::Value FloatTensor::data(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    
    torch::Tensor tensor = this->tensor_;
    size_t size = tensor.numel();

    Napi::Array dataArray = Napi::Array::New(env, size);

    for (size_t i = 0; i < size; i++) {
        dataArray.Set(i, Napi::Number::New(env, tensor[i].item<float>()));
    }

    return dataArray;
}