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
    Napi::Function func = DefineClass(env, "DoubleTensor", {
        InstanceMethod("data", &DoubleTensor::data)
    });

    Napi::FunctionReference* constructor = new Napi::FunctionReference();
    *constructor = Napi::Persistent(func);
    exports.Set("DoubleTensor", func);

    return exports;
}

Napi::Object FloatTensor::Init(Napi::Env env, Napi::Object exports) {
    Napi::Function func = DefineClass(env, "FloatTensor", {
        InstanceMethod("getData", &FloatTensor::data)
    });

    Napi::FunctionReference* constructor = new Napi::FunctionReference();
    *constructor = Napi::Persistent(func);
    exports.Set("FloatTensor", func);

    return exports;
}

Napi::Object HalfTensor::Init(Napi::Env env, Napi::Object exports) {
    Napi::Function func = DefineClass(env, "HalfTensor", {
        InstanceMethod("getData", &HalfTensor::data)
    });

    Napi::FunctionReference* constructor = new Napi::FunctionReference();
    *constructor = Napi::Persistent(func);
    exports.Set("HalfTensor", func);

    return exports;
}

DoubleTensor::DoubleTensor(const Napi::CallbackInfo& info) : TensorBase(info) {
    if (info.Length() < 1 || !info[0].IsArray()) {
        Napi::TypeError::New(info.Env(), "Array expected").ThrowAsJavaScriptException();
        return;
    }

    Napi::Array dataArray = info[0].As<Napi::Array>();
    size_t dataLength = dataArray.Length();
    std::vector<double> data;
    data.reserve(dataLength);

    for (size_t i = 0; i < dataLength; i++) {
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
    size_t dataLength = dataArray.Length();
    std::vector<float> data;
    data.reserve(dataLength);

    for (size_t i = 0; i < dataLength; i++) {
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
    size_t dataLength = dataArray.Length();
    std::vector<at::Half> data;
    data.reserve(dataLength);

    for (size_t i = 0; i < dataLength; i++) {
        data.push_back(static_cast<at::Half>(dataArray.Get(i).ToNumber().DoubleValue()));
    }

    _value = torch::from_blob(data.data(), {dataLength}, torch::kHalf);
}

// botar isso em /tensor

Napi::Value DoubleTensor::data(const Napi::CallbackInfo& info) {
    std::vector<double> data(_value.data<double>(), _value.data<double>() + _value.numel());
    Napi::Array dataArray = Napi::Array::New(info.Env(), data.size());

    for (size_t i = 0; i < data.size(); i++) {
        dataArray.Set(i, data[i]);
    }

    return dataArray;
}

Napi::Value FloatTensor::data(const Napi::CallbackInfo& info) {
    std::vector<float> data(_value.data<float>(), _value.data<float>() + _value.numel());
    Napi::Array dataArray = Napi::Array::New(info.Env(), data.size());

    for (size_t i = 0; i < data.size(); i++) {
        dataArray.Set(i, static_cast<double>(data[i]));
    }

    return dataArray;
}

Napi::Value HalfTensor::data(const Napi::CallbackInfo& info) {
    std::vector<at::Half> data(_value.data<at::Half>(), _value.data<at::Half>() + _value.numel());
    Napi::Array dataArray = Napi::Array::New(info.Env(), data.size());

    for (size_t i = 0; i < data.size(); i++) {
        dataArray.Set(i, static_cast<double>(data[i]));
    }

    return dataArray;
}