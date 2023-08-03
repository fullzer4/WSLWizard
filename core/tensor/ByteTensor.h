#pragma once

#include <napi.h>
#include <torch/torch.h>

class ByteTensor : public Napi::ObjectWrap<ByteTensor> {
    public:
        static Napi::Object Init(Napi::Env env, Napi::Object exports);
        ByteTensor(const Napi::CallbackInfo &);

    private:
        static Napi::FunctionReference constructor;

        Napi::Value data(const Napi::CallbackInfo &);
};