#include "DoubleTensor.h"

Napi::Object DoubleTensor::Init(Napi::Env env, Napi::Object exports) {
    Napi::Function func = DefineClass(env, "DoubleTensor", {
        InstanceMethod("getTensor", &DoubleTensor::GetTensor)
    });
    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();
    exports.Set("DoubleTensor", func);
    return exports;
}

DoubleTensor::DoubleTensor(const Napi::CallbackInfo& info) : Napi::ObjectWrap<DoubleTensor>(info) {
    // Construir o tensor aqui com base nos argumentos passados para o construtor (se houver)
}

Napi::Value DoubleTensor::GetTensor(const Napi::CallbackInfo& info) {
    // Implementar a lógica para retornar o tensor como um valor Napi aqui
}