#include <napi.h>
#include <torch/torch.h>

class Conv2d : public Napi::ObjectWrap<Conv2d> {
    public:
        static Napi::Object Init(Napi::Env env, Napi::Object exports);
        Conv2d(const Napi::CallbackInfo& info);


    private:
        torch::nn::Conv2d conv2d;
};