#include "FloatTensor.h"

Napi::FunctionReference FloatTensor::constructor;

Napi::Object FloatTensor::Init(Napi::Env env, Napi::Object exports) {
    Napi::Function func = DefineClass(env, "FloatTensor", {
        InstanceMethod("data", &FloatTensor::data),
    });

    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();
    exports.Set("FloatTensor", func);

    return exports;
}

FloatTensor::FloatTensor(const Napi::CallbackInfo& info) : Napi::ObjectWrap<FloatTensor>(info) {
    // Construir o tensor aqui com base nos argumentos passados para o construtor (se houver)
}

Napi::Value FloatTensor::data(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    return Napi::Number::New(env, 42); // Teste
}
