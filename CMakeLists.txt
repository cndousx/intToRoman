cmake_minimum_required(VERSION 3.14)
project(intToRoman)

set(CMAKE_CXX_STANDARD 20)

# 启用测试
enable_testing()

# 创建主可执行文件
add_executable(intToRoman
    src/main.cpp
    src/solution.cpp
)