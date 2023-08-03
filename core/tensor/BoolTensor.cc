#include "BoolTensor.h"

Napi::FunctionReference BoolTensor::constructor;

Napi::Object BoolTensor::Init(Napi::Env env, Napi::Object exports) {
    Napi::Function func = DefineClass(env, "BoolTensor", {
        InstanceMethod("data", &BoolTensor::data),
    });

    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();
    exports.Set("BoolTensor", func);

    return exports;
}

BoolTensor::BoolTensor(const Napi::CallbackInfo& info) : Napi::ObjectWrap<BoolTensor>(info) {
    // Construir o tensor aqui com base nos argumentos passados para o construtor (se houver)
}

Napi::Value BoolTensor::data(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    return Napi::Number::New(env, 42); // Teste
}
