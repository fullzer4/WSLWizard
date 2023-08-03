{
    "targets": [{
        "target_name": "jstorchcore",
        "cflags!": [ "-fno-exceptions" ],
        "cflags_cc!": [ "-fno-exceptions" ],
        "sources": [
            "./core/addon.cc",
            "./core/tensor/tensor.cc",
            "./core/tensor/DoubleTensor.cc",
            "./core/tensor/DoubleTensor.h",
            "./core/tensor/FloatTensor.cc",
            "./core/tensor/FloatTensor.h",
            "./core/tensor/HalfTensor.cc",
            "./core/tensor/HalfTensor.h",
            "./core/tensor/CharTensor.cc",
            "./core/tensor/CharTensor.h",
            "./core/tensor/ByteTensor.cc",
            "./core/tensor/ByteTensor.h",
            "./core/tensor/BoolTensor.cc",
            "./core/tensor/BoolTensor.h",
            "./core/tensor/IntTensor.cc",
            "./core/tensor/IntTensor.h",
            "./core/tensor/LongTensor.cc",
            "./core/tensor/LongTensor.h",
            "./core/tensor/ShortTensor.cc",
            "./core/tensor/ShortTensor.h",
            "./core/tensor/BFloat16Tensor.cc",
            "./core/tensor/BFloat16Tensor.h",
            "./core/utils/utils.h",
            "./core/utils/utils.cc",
        ],
        'include_dirs': [
            "<!@(node -p \"require('node-addon-api').include\")"
        ],
        'libraries': [],
        'dependencies': [
            "<!(node -p \"require('node-addon-api').gyp\")"
        ],
        'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ]
    }]
}