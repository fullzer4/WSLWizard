#include "tensor.h"

Napi::FunctionReference TensorBase::constructor;

TensorBase::TensorBase(const Napi::CallbackInfo& info) : Napi::ObjectWrap<TensorBase>(info) {
    // TensorBase data here
}

Napi::Object TensorBase::Init(Napi::Env env, Napi::Object exports) {
    Napi::Function func = DefineClass(env, "TensorBase", {});

    constructor = Napi::Persistent(func);

    exports.Set("TensorBase", func);

    return exports;
}

Napi::Object DoubleTensor::Init(Napi::Env env, Napi::Object exports) {
    Napi::Function func = DefineClass(env, "DoubleTensor", {});
    constructor = Napi::Persistent(func);
    exports.Set("DoubleTensor", func);

    return exports;
}

Napi::Object FloatTensor::Init(Napi::Env env, Napi::Object exports) {
    Napi::Function func = DefineClass(env, "FloatTensor", {});
    constructor = Napi::Persistent(func);
    exports.Set("FloatTensor", func);

    return exports;
}

Napi::Object HalfTensor::Init(Napi::Env env, Napi::Object exports) {
    Napi::Function func = DefineClass(env, "HalfTensor", {});
    constructor = Napi::Persistent(func);
    exports.Set("HalfTensor", func);

    return exports;
}

DoubleTensor::DoubleTensor(const Napi::CallbackInfo& info) : TensorBase(info) {
    if (info.Length() < 1 || !info[0].IsArray()) {
        Napi::TypeError::New(info.Env(), "Array expected").ThrowAsJavaScriptException();
        return;
    }

    Napi::Array dataArray = info[0].As<Napi::Array>();
    int64_t dataLength = dataArray.Length();
    std::vector<double> data;
    data.reserve(dataLength);

    for (int64_t i = 0; i < dataLength; i++) {
        data.push_back(dataArray.Get(i).ToNumber().DoubleValue());
    }

    _value = torch::from_blob(data.data(), {dataLength}, torch::kDouble);
}

FloatTensor::FloatTensor(const Napi::CallbackInfo& info) : TensorBase(info) {
    if (info.Length() < 1 || !info[0].IsArray()) {
        Napi::TypeError::New(info.Env(), "Array expected").ThrowAsJavaScriptException();
        return;
    }

    Napi::Array dataArray = info[0].As<Napi::Array>();
    int64_t dataLength = dataArray.Length();
    std::vector<float> data;
    data.reserve(dataLength);

    for (int64_t i = 0; i < dataLength; i++) {
        data.push_back(static_cast<float>(dataArray.Get(i).ToNumber().DoubleValue()));
    }

    _value = torch::from_blob(data.data(), {dataLength}, torch::kFloat);
}

HalfTensor::HalfTensor(const Napi::CallbackInfo& info) : TensorBase(info) {
    if (info.Length() < 1 || !info[0].IsArray()) {
        Napi::TypeError::New(info.Env(), "Array expected").ThrowAsJavaScriptException();
        return;
    }

    Napi::Array dataArray = info[0].As<Napi::Array>();
    int64_t dataLength = dataArray.Length();
    std::vector<at::Half> data;
    data.reserve(dataLength);

    for (int64_t i = 0; i < dataLength; i++) {
        data.push_back(static_cast<at::Half>(dataArray.Get(i).ToNumber().DoubleValue()));
    }

    _value = torch::from_blob(data.data(), {dataLength}, torch::kHalf);
}

Napi::Value DoubleTensor::data(const Napi::CallbackInfo& info) {
    Napi::Array dataArr = Napi::Array::New(info.Env(), _value.numel());
    for (int i = 0; i < _value.numel(); i++) {
        dataArr.Set(i, Napi::Number::New(info.Env(), _value[i].item<double>()));
    }
    return dataArr;
}

Napi::Value FloatTensor::data(const Napi::CallbackInfo& info) {
    Napi::Array dataArr = Napi::Array::New(info.Env(), _value.numel());
    for (int i = 0; i < _value.numel(); i++) {
        dataArr.Set(i, Napi::Number::New(info.Env(), _value[i].item<float>()));
    }
    return dataArr;
}

Napi::Value HalfTensor::data(const Napi::CallbackInfo& info) {
    Napi::Array dataArr = Napi::Array::New(info.Env(), _value.numel());
    for (int i = 0; i < _value.numel(); i++) {
        dataArr.Set(i, Napi::Number::New(info.Env(), static_cast<double>(_value[i].item<at::Half>())));
    }
    return dataArr;
}