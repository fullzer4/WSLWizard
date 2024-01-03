{
  "targets": [
    {
      "name": "jstorch",
      "sources": ["./bin/main.cc"],
      "includeDirs": [
        "/home/fullzer4/Codes/jstorch-node/libtorch/include/",
        "/home/fullzer4/Codes/jstorch-node/libtorch/include/torch/csrc/api/include/"
      ],
      "libraries": [
        "/home/fullzer4/Codes/jstorch-node/libtorch/lib/libtorch.so",
        "/home/fullzer4/Codes/jstorch-node/libtorch/lib/libc10.so",
        "/home/fullzer4/Codes/jstorch-node/libtorch/lib/libtorch_cpu.so",
        "/home/fullzer4/Codes/jstorch-node/libtorch/lib/libtorch_python.so"
      ],
      "cflags": ["-std=c++17"]
    }
  ]
}

