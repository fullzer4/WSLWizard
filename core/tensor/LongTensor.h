#pragma once

#include <napi.h>
#include <torch/torch.h>

class LongTensor : public Napi::ObjectWrap<LongTensor> {
public:
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
    LongTensor(const Napi::CallbackInfo& info);
    Napi::Value GetTensor(const Napi::CallbackInfo& info);

private:
    torch::Tensor tensor;
};