#include "BFloat16Tensor.h"

Napi::FunctionReference BFloat16Tensor::constructor;

Napi::Object BFloat16Tensor::Init(Napi::Env env, Napi::Object exports) {
    Napi::Function func = DefineClass(env, "BFloat16Tensor", {
        InstanceMethod("data", &BFloat16Tensor::data),
    });

    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();
    exports.Set("BFloat16Tensor", func);

    return exports;
}

BFloat16Tensor::BFloat16Tensor(const Napi::CallbackInfo& info) : Napi::ObjectWrap<BFloat16Tensor>(info) {
    // Construir o tensor aqui com base nos argumentos passados para o construtor (se houver)
}

Napi::Value BFloat16Tensor::data(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    return Napi::Number::New(env, 42); // Teste
}
