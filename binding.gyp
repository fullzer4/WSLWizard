{
  'variables': {
     # executar builds
  },
  'targets': [{
    'target_name': 'jstorch',
    'sources': [
       'core/addon.cc',
       'core/cuda/cuda.cc',
       'core/cuda/cuda.h',
       'core/nn/load.cc',
       'core/nn/load.h',
       'core/tensor/tensor.cc',
       'core/tensor/tensor.h'
     ],
     'include_dirs': [
       'core/libtorch/include',
       "<!(node -p \"require('node-addon-api').include_dir\")",         
       "../node_modules/node-addon-api",
       "node_modules/node-addon-api",
       "/usr/include/node",
       "/usr/local/include/node",       
     ],
    'link_settings': {
      'library_dirs': ['core/libtorch/lib'],
      'libraries': [
        'libtorch.so'
      ]
    },
    "dependencies": ["<!(node -p \"require('node-addon-api').gyp\")"],
    "defines": ["NAPI_CPP_EXCEPTIONS"],
    "cflags!": ["-fno-exceptions"],
    "cflags_cc!": ["-fno-exceptions"],
    "cflags": ["-Wall", "-Wno-psabi", "-std=c++14", "-pthread"],
    "cflags_cc": ["-Wall", "-Wno-psabi", "-pthread"],
  }]
}