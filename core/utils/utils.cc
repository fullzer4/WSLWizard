#include "utils.h"

Napi::Value TensorToNapiArray(Napi::Env env, torch::Tensor tensor) {
    torch::Tensor cpu_tensor = tensor.cpu();
    int64_t numel = cpu_tensor.numel();
    std::vector<double> data(numel);
    cpu_tensor.data_ptr<double>()[0];
    auto accessor = cpu_tensor.accessor<double, 1>();
    for (int64_t i = 0; i < numel; i++) {
        data[i] = accessor[i];
    }
    Napi::Array array = Napi::Array::New(env, numel);
    for (int64_t i = 0; i < numel; i++) {
        array.Set(i, Napi::Number::New(env, data[i]));
    }
    return array;
}

torch::Tensor NapiArrayToTensor(Napi::Value value) {
    Napi::Array array = value.As<Napi::Array>();
    int64_t numel = array.Length();
    std::vector<double> data(numel);
    for (int64_t i = 0; i < numel; i++) {
        data[i] = array.Get(i).As<Napi::Number>().DoubleValue();
    }
    return torch::from_blob(data.data(), {numel});
}
