#pragma once

#include <napi.h>
#include <torch/torch.h>

class ShortTensor : public Napi::ObjectWrap<ShortTensor> {
    public:
        static Napi::Object Init(Napi::Env env, Napi::Object exports);
        ShortTensor(const Napi::CallbackInfo &);

    private:
        static Napi::FunctionReference constructor;

        Napi::Value data(const Napi::CallbackInfo &);
};