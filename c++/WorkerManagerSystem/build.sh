#!/bin/bash

# 默认构建类型为 Release
BUILD_TYPE=${1:-Release}
EXECUTABLE_NAME=${2:-wm}

# 设置构建目录
BUILD_DIR="./build"

# 创建并进入构建目录（如果不在其中）
if [ ! -d "${BUILD_DIR}" ]; then
    echo "Creating build directory..."
    mkdir -p "${BUILD_DIR}"
fi
cd "${BUILD_DIR}"

# 移除旧的构建文件
echo "Removing old build files..."
rm -rf *

# 配置项目
echo "Configuring project for ${BUILD_TYPE}..."
cmake -DCMAKE_BUILD_TYPE=${BUILD_TYPE} ..

# 构建项目
echo "Building project for ${BUILD_TYPE}..."
cmake --build . --config ${BUILD_TYPE}

# 检查构建是否成功
if [ $? -ne 0 ]; then
    echo "Build failed!"
    exit 1
else
    echo "Build succeeded!"
fi

# 运行可执行文件
echo "Running ${EXECUTABLE_NAME}..."
exec ./${EXECUTABLE_NAME}
