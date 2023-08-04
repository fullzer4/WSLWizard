#include "CharTensor.h"

Napi::FunctionReference CharTensor::constructor;

Napi::Object CharTensor::Init(Napi::Env env, Napi::Object exports) {
    Napi::Function func = DefineClass(env, "CharTensor", {
        InstanceMethod("data", &CharTensor::data),
    });

    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();
    exports.Set("CharTensor", func);

    return exports;
}

CharTensor::CharTensor(const Napi::CallbackInfo& info) : Napi::ObjectWrap<CharTensor>(info) {
    Napi::Env env = info.Env();

    if (info.Length() == 0 || !info[0].IsArray()) {
        Napi::TypeError::New(env, "Um array de caracteres é esperado como argumento").ThrowAsJavaScriptException();
        return;
    }

    Napi::Array dataArray = info[0].As<Napi::Array>();
    size_t size = dataArray.Length();

    torch::TensorOptions options = torch::TensorOptions().dtype(torch::kUInt8);
    tensor_ = torch::empty({static_cast<long>(size)}, options);

    for (size_t i = 0; i < size; i++) {
        std::string str = dataArray.Get(i).ToString().Utf8Value();
        tensor_[i] = static_cast<uint8_t>(str[0]);
    }
}

Napi::Value CharTensor::data(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    torch::Tensor tensor = this->tensor_;
    size_t size = tensor.numel();

    Napi::Array dataArray = Napi::Array::New(env, size);

    for (size_t i = 0; i < size; i++) {
        dataArray.Set(i, Napi::String::New(env, std::string(1, static_cast<char>(tensor[i].item<uint8_t>()))));
    }

    return dataArray;
}