#pragma once

#include <napi.h>
#include <cstdint>
#include <memory>
#include <torch/torch.h>

class TensorBase : public Napi::ObjectWrap<TensorBase> {
public:
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
    static Napi::FunctionReference constructor;

    TensorBase(const Napi::CallbackInfo& info);
    virtual ~TensorBase() = default;
    
    virtual Napi::Value data(const Napi::CallbackInfo& info);
    
protected:
    torch::Tensor _value;
};

class DoubleTensor : public TensorBase {
public:
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
    DoubleTensor(const Napi::CallbackInfo& info);
    Napi::Value data(const Napi::CallbackInfo& info) override;
};

class FloatTensor : public TensorBase {
public:
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
    FloatTensor(const Napi::CallbackInfo& info);
    Napi::Value data(const Napi::CallbackInfo& info) override;
};

class HalfTensor : public TensorBase {
public:
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
    HalfTensor(const Napi::CallbackInfo& info);
    Napi::Value data(const Napi::CallbackInfo& info) override;
};
