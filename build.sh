#!/bin/bash
clear
make clean && make mrproper

# Export KBUILD flags
export KBUILD_BUILD_USER=yukosky
export KBUILD_BUILD_HOST=a2XX-Team

# Export ARCH/SUBARCH flags
export ARCH="arm64"
export SUBARCH="arm64"

# Export ANDROID VERSION
export ANDROID_MAJOR_VERSION="q"

# Export toolchain/cross flags
export TOOLCHAIN="aarch64-linux-android-"
export CROSS_COMPILE="$(pwd)/toolchain/bin/${TOOLCHAIN}"

# Check if have toolchain folder
if [ ! -d "$(pwd)/toolchain/" ]; then
   git clone https://github.com/a2XX-dev/toolchains toolchain -b 4.9
fi

# Build time
make exynos850-a21snsxx_defconfig
make
