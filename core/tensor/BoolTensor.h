#pragma once

#include <napi.h>
#include <torch/torch.h>

class BoolTensor : public Napi::ObjectWrap<BoolTensor> {
public:
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
    BoolTensor(const Napi::CallbackInfo& info);
    Napi::Value GetTensor(const Napi::CallbackInfo& info);

private:
    torch::Tensor tensor;
};