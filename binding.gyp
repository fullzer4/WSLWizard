{
  "targets": [
    {
      "target_name": "addon",
      "type": "shared_library",
      "sources": [
        "./bin/main.cc"
      ],
      "include_dirs": [
        "/home/fullzer4/Codes/jstorch-node/libtorch/include/",
        "/home/fullzer4/Codes/jstorch-node/libtorch/include/torch/csrc/api/include/"
      ],
      "library_dirs": [ "/home/fullzer4/Codes/jstorch-node/libtorch/lib" ],
      "libraries":    [
        "torch",
        "torch_cpu",
      ],
      "conditions": [
      
      ]
    }
  ]
}

