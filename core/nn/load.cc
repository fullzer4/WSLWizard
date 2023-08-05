#include "load.h"
#include <torch/script.h>

Napi::Value LoadModel(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() != 1 || !info[0].IsString()) {
        Napi::TypeError::New(env, "Expected a string as an argument for the model path.").ThrowAsJavaScriptException();
        return env.Null();
    }

    std::string modelPath = info[0].As<Napi::String>().Utf8Value();

    try {
        torch::jit::script::Module module = torch::jit::load(modelPath);


    } catch (const c10::Error& e) {
        Napi::Error::New(env, "Error loading the model: " + std::string(e.msg())).ThrowAsJavaScriptException();
        return env.Null();
    }

    return env.Null();
}