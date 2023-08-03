#pragma once

#include <napi.h>
#include <torch/torch.h>

class CharTensor : public Napi::ObjectWrap<CharTensor> {
public:
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
    CharTensor(const Napi::CallbackInfo& info);
    Napi::Value GetTensor(const Napi::CallbackInfo& info);

private:
    torch::Tensor tensor;
};