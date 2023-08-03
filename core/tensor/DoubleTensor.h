#pragma once

#include <napi.h>
#include <torch/torch.h>

class DoubleTensor : public Napi::ObjectWrap<DoubleTensor> {
public:
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
    DoubleTensor(const Napi::CallbackInfo& info);
    Napi::Value GetTensor(const Napi::CallbackInfo& info);

private:
    torch::Tensor tensor;
};