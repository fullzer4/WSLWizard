#include "IntTensor.h"

Napi::Object IntTensor::Init(Napi::Env env, Napi::Object exports) {
    Napi::Function func = DefineClass(env, "IntTensor", {
        InstanceMethod("getTensor", &IntTensor::GetTensor)
    });
    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();
    exports.Set("IntTensor", func);
    return exports;
}

IntTensor::DoubleTensor(const Napi::CallbackInfo& info) : Napi::ObjectWrap<IntTensor>(info) {
    // Construir o tensor aqui com base nos argumentos passados para o construtor (se houver)
}

Napi::Value IntTensor::GetTensor(const Napi::CallbackInfo& info) {
    // Implementar a lógica para retornar o tensor como um valor Napi aqui
}