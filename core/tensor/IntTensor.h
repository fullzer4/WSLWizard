#pragma once

#include <napi.h>
#include <torch/torch.h>

class IntTensor : public Napi::ObjectWrap<IntTensor> {
public:
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
    IntTensor(const Napi::CallbackInfo& info);
    Napi::Value GetTensor(const Napi::CallbackInfo& info);

private:
    torch::Tensor tensor;
};