#pragma once

#include <napi.h>
#include <torch/torch.h>

class DoubleTensor : public Napi::ObjectWrap<DoubleTensor> {
    public:
        static Napi::Object Init(Napi::Env env, Napi::Object exports);
        DoubleTensor(const Napi::CallbackInfo &);

    private:
        static Napi::FunctionReference constructor;
        torch::Tensor tensor_;

        Napi::Value data(const Napi::CallbackInfo &);
};