#include "HalfTensor.h"

Napi::FunctionReference HalfTensor::constructor;

Napi::Object HalfTensor::Init(Napi::Env env, Napi::Object exports) {
    Napi::Function func = DefineClass(env, "HalfTensor", {
        InstanceMethod("data", &HalfTensor::data),
    });

    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();
    exports.Set("HalfTensor", func);

    return exports;
}

HalfTensor::HalfTensor(const Napi::CallbackInfo& info) : Napi::ObjectWrap<HalfTensor>(info) {
    // Construir o tensor aqui com base nos argumentos passados para o construtor (se houver)
}

Napi::Value HalfTensor::data(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    return Napi::Number::New(env, 42); // Teste
}
