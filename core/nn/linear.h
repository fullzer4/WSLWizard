#include <napi.h>
#include <torch/torch.h>

class Linear : public Napi::ObjectWrap<Linear> {
    public:
        static Napi::Object Init(Napi::Env env, Napi::Object exports);
        Linear(const Napi::CallbackInfo& info);

        torch::Tensor forward(torch::Tensor x);

    private:
        torch::nn::Linear layer;
};