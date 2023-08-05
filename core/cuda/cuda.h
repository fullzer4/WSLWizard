#include <napi.h>
#include <torch/torch.h>

class Cuda : public Napi::ObjectWrap<Cuda> {
public:
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
    Cuda(const Napi::CallbackInfo& info);
    Napi::Value IsAvailable(const Napi::CallbackInfo& info);

private:
    static Napi::FunctionReference constructor;
};