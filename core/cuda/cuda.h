#include <napi.h>
#include <torch/torch.h>

Napi::Boolean IsCudaAvailable(const Napi::CallbackInfo& info);