#pragma once

#include <napi.h>
#include <torch/torch.h>

class ShortTensor : public Napi::ObjectWrap<ShortTensor> {
public:
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
    ShortTensor(const Napi::CallbackInfo& info);
    Napi::Value GetTensor(const Napi::CallbackInfo& info);

private:
    torch::Tensor tensor;
};