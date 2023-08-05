#include <napi.h>
#include <torch/torch.h>

class NN : public Napi::ObjectWrap<NN> {
    public:
        static Napi::Object Init(Napi::Env env, Napi::Object exports);
        NN(const Napi::CallbackInfo& info);

        virtual torch::Tensor forward(torch::Tensor x);

    private:
    
};