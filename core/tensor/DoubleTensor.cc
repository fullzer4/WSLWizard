#include "DoubleTensor.h"

Napi::FunctionReference DoubleTensor::constructor;

Napi::Object DoubleTensor::Init(Napi::Env env, Napi::Object exports) {
    Napi::Function func = DefineClass(env, "DoubleTensor", {
        InstanceMethod("data", &DoubleTensor::data),
    });

    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();
    exports.Set("DoubleTensor", func);

    return exports;
}

DoubleTensor::DoubleTensor(const Napi::CallbackInfo& info) : Napi::ObjectWrap<DoubleTensor>(info) {
    // Construir o tensor aqui com base nos argumentos passados para o construtor (se houver)
}

Napi::Value DoubleTensor::data(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    return Napi::Number::New(env, 42); // Teste
}
