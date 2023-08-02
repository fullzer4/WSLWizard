{
    "targets": [{
        "target_name": "jstorchcore",
        "cflags!": [ "-fno-exceptions" ],
        "cflags_cc!": [ "-fno-exceptions" ],
        "sources": [
            "./core/addon.cc",
            "./core/tensor.cc",
            "./core/tensor.h",
            "./core/tensor/methods.cc",
            "./core/tensor/methods.h",
            "./core/utils.cc",
            "./core/utils.h",
            "./core/cuda.cc",
            "./core/cuda.h",
            "./core/cuda/tensor.cu"
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