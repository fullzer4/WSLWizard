#include "IntTensor.h"

Napi::FunctionReference IntTensor::constructor;

Napi::Object IntTensor::Init(Napi::Env env, Napi::Object exports) {
    Napi::Function func = DefineClass(env, "IntTensor", {
        InstanceMethod("data", &IntTensor::data),
    });

    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();
    exports.Set("IntTensor", func);

    return exports;
}

IntTensor::IntTensor(const Napi::CallbackInfo& info) : Napi::ObjectWrap<IntTensor>(info) {
    // Construir o tensor aqui com base nos argumentos passados para o construtor (se houver)
}

Napi::Value IntTensor::data(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    return Napi::Number::New(env, 42); // Teste
}
