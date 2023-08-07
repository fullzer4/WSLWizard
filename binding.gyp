{
  "targets": [
    {
      "target_name": "jstorch",
      "sources": [
        "core/*.cc",
        "core/tensor/*.cc",
        "core/cuda/*.cc",
        "core/nn/*.cc"
      ],
      "include_dirs": [
        "<!@(node -p \"require('node-addon-api').include\")",
        "<(module_root_dir)/node_modules/node-addon-api",
        "<(module_root_dir)/node_modules/node-addon-api/src"
      ],
      "dependencies": [
        "<!(node -p \"require('node-addon-api').gyp\")"
      ],
      "cflags!": ["-fno-exceptions"],
      "cflags_cc!": ["-fno-exceptions"],
      "defines": [
        "NAPI_DISABLE_CPP_EXCEPTIONS"
      ],
      "link_settings": {
        "libraries": [
          "-lc++",
          "-lc++abi",
          "-lm",
          "-ldl",
          "-pthread",
          "~/Libs/libtorch/include/torch"
        ]
      }
    }
  ]
}
