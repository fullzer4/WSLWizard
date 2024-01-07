#pragma once
#include <torch/torch.h>

class BaseTensor {
public:
    BaseTensor() = default;
    virtual ~BaseTensor() = default;

    virtual torch::Tensor getTensor() const = 0;

};