#pragma once
#include "base_tensor.h"

class IntTensor : public BaseTensor {
public:
    IntTensor(const torch::Tensor& tensor) : tensor_(tensor) {}

    torch::Tensor getTensor() const override {
        return tensor_;
    }

private:
    torch::Tensor tensor_;
};