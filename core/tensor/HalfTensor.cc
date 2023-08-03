#include "HalfTensor.h"

Napi::Object HalfTensor::Init(Napi::Env env, Napi::Object exports) {
    Napi::Function func = DefineClass(env, "HalfTensor", {
        InstanceMethod("getTensor", &HalfTensor::GetTensor)
    });
    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();
    exports.Set("HalfTensor", func);
    return exports;
}

HalfTensor::DoubleTensor(const Napi::CallbackInfo& info) : Napi::ObjectWrap<HalfTensor>(info) {
    // Construir o tensor aqui com base nos argumentos passados para o construtor (se houver)
}

Napi::Value HalfTensor::GetTensor(const Napi::CallbackInfo& info) {
    // Implementar a lógica para retornar o tensor como um valor Napi aqui
}