#pragma once

#include <napi.h>
#include <torch/torch.h>

class HalfTensor : public Napi::ObjectWrap<HalfTensor> {
    public:
        static Napi::Object Init(Napi::Env env, Napi::Object exports);
        HalfTensor(const Napi::CallbackInfo &);

    private:
        static Napi::FunctionReference constructor;
        torch::Tensor tensor_;
        
        Napi::Value data(const Napi::CallbackInfo &);
};