#pragma once

#include <napi.h>
#include <torch/torch.h>

class HalfTensor : public Napi::ObjectWrap<HalfTensor> {
public:
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
    HalfTensor(const Napi::CallbackInfo& info);
    Napi::Value GetTensor(const Napi::CallbackInfo& info);

private:
    torch::Tensor tensor;
};