#!/bin/bash

build_addon() {
    platform=$1
    arch=$2

    echo "Building for $platform - $arch..."
    cmake-js build --arch=$arch --platform=$platform

    mv build/Release/jstorch.node bin/$platform-$arch/jstorch.node
}

build_addon darwin x64
build_addon darwin arm64

build_addon linux x64
build_addon linux x86
build_addon linux arm64
build_addon linux armhf
build_addon linux ppc64le
build_addon linux s390x

build_addon win32 x64
build_addon win32 x86
