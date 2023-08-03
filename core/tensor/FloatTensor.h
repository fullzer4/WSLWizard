#pragma once

#include <napi.h>
#include <torch/torch.h>

class FloatTensor : public Napi::ObjectWrap<FloatTensor> {
public:
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
    FloatTensor(const Napi::CallbackInfo& info);
    Napi::Value GetTensor(const Napi::CallbackInfo& info);

private:
    torch::Tensor tensor;
};