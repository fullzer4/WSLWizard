{
  "targets": [
    {
      "target_name": "addon",
      "sources": [
        "./bin/main.cc",
        "./bin/tensor/ones.cc",
        "./bin/tensor/zeros.cc",
        "./bin/tensor/tensor_utils.cc",
        "./bin/tensor/tensor_uitls.h",
        "./bin/tensor/base_tensor.h",
        "./bin/tensor/int_tensor.h"
      ],
      "include_dirs": [
        "/home/fullzer4/Codes/jstorch-node/libtorch/include/",
        "/home/fullzer4/Codes/jstorch-node/libtorch/include/torch/csrc/api/include/"
      ],
      "library_dirs": [ "/home/fullzer4/Codes/jstorch-node/libtorch/lib" ],
      "libraries": [
        "/home/fullzer4/Codes/jstorch-node/libtorch/lib/libtorch.so",
        "/home/fullzer4/Codes/jstorch-node/libtorch/lib/libtorch_cpu.so",
      ],
      "conditions": [
      	[ 'OS=="linux" or OS=="freebsd" or OS=="openbsd" or OS=="solaris"', {
          "cflags!": [ "-fno-exceptions" ],
          'cflags_cc!': ["-fno-rtti", "-fno-exceptions"],
       	  'cflags_cc+': ['-frtti'],
  	  }
	],
	['OS=="mac"', {
          'xcode_settings': {
            'GCC_ENABLE_CPP_EXCEPTIONS': 'YES'
          }
        }]
      ]
    }
  ]
}

