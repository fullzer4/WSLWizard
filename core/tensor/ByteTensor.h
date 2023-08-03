#pragma once

#include <napi.h>
#include <torch/torch.h>

class ByteTensor : public Napi::ObjectWrap<ByteTensor> {
public:
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
    ByteTensor(const Napi::CallbackInfo& info);
    Napi::Value GetTensor(const Napi::CallbackInfo& info);

private:
    torch::Tensor tensor;
};