#!/bin/bash

# Check if have gcc/32 & clang folder
if [ ! -d "$(pwd)/gcc/" ]; then
   git clone --depth 1 git://github.com/LineageOS/android_prebuilts_gcc_linux-x86_aarch64_aarch64-linux-android-4.9 gcc
fi

if [ ! -d "$(pwd)/gcc32/" ]; then
   git clone --depth 1 git://github.com/LineageOS/android_prebuilts_gcc_linux-x86_arm_arm-linux-androideabi-4.9 gcc32
fi

if [ ! -d "$(pwd)/clang/" ]; then
   git clone --depth 1 https://github.com/Chatur27/Toolchains-for-Eureka.git -b proton_clang_12 clang
fi

# Export KBUILD flags
export KBUILD_BUILD_USER=yukosky
export KBUILD_BUILD_HOST=a2XX-Team

# Export ARCH/SUBARCH flags
export ARCH="arm64"
export SUBARCH="arm64"

# Export ANDROID VERSION
export ANDROID_MAJOR_VERSION="q"

# Export CCACHE
export CCACHE="$(which ccache)"

# Export toolchain/cross flags
export TOOLCHAIN="aarch64-linux-android-"
export CLANG_TRIPLE="aarch64-linux-gnu-"
export CROSS_COMPILE="$(pwd)/gcc/bin/${TOOLCHAIN}"
export CROSS_COMPILE_ARM32="$(pwd)/gcc32/bin/arm-linux-androideabi-"
export WITH_OUTDIR=true

# Export PATH flag
export PATH="${PATH}:$(pwd)/clang/bin:$(pwd)/gcc/bin:$(pwd)/gcc32/bin"

# Clear the console
clear

# Remove out dir folder and clean the source
if [ "${WITH_OUTDIR}" == true ]; then
   if [ -d "$(pwd)/out" ]; then
      rm -rf out
   fi
fi
make clean && make mrproper

# Build time
if [ "${WITH_OUTDIR}" == true ]; then
   if [ ! -d "$(pwd)/out" ]; then
      mkdir out
   fi
fi

if [ "${WITH_OUTDIR}" == true ]; then
   "${CCACHE}" make O=out exynos850-a21snsxx_defconfig
   "${CCACHE}" make -j18 O=out CC=clang CLANG_TRIPLE="${CLANG_TRIPLE}"
else
   "${CCACHE}" make exynos850-a21snsxx_defconfig
   "${CCACHE}" make -j18 CC=clang CLANG_TRIPLE="${CLANG_TRIPLE}"
fi
