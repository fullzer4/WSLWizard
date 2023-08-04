#include "HalfTensor.h"

Napi::FunctionReference HalfTensor::constructor;

Napi::Object HalfTensor::Init(Napi::Env env, Napi::Object exports) {
    Napi::Function func = DefineClass(env, "HalfTensor", {
        InstanceMethod("data", &HalfTensor::data),
    });

    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();
    exports.Set("HalfTensor", func);

    return exports;
}

HalfTensor::HalfTensor(const Napi::CallbackInfo& info) : Napi::ObjectWrap<HalfTensor>(info) {
    Napi::Env env = info.Env();

    if (info.Length() == 0 || !info[0].IsArray()) {
        Napi::TypeError::New(env, "Um array de números é esperado como argumento").ThrowAsJavaScriptException();
        return;
    }

    Napi::Array dataArray = info[0].As<Napi::Array>();
    size_t size = dataArray.Length();

    torch::TensorOptions options = torch::TensorOptions().dtype(torch::kFloat16);
    tensor_ = torch::empty({static_cast<long>(size)}, options);

    for (size_t i = 0; i < size; i++) {
        tensor_[i] = dataArray.Get(i).ToNumber().FloatValue();
    }
}

Napi::Value HalfTensor::data(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    torch::Tensor tensor = this->tensor_;
    size_t size = tensor.numel();

    Napi::Array dataArray = Napi::Array::New(env, size);

    for (size_t i = 0; i < size; i++) {
        dataArray.Set(i, Napi::Number::New(env, tensor[i].item<float>()));
    }

    return dataArray;
}