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

# 查找 gtest（依赖 vcpkg 提供的配置）
find_package(GTest CONFIG REQUIRED)

add_executable(intToRoman-tests
        tests/intToRoman_test.cpp
        src/solution.cpp
)

# 链接 gtest
target_link_libraries(intToRoman-tests PRIVATE GTest::gtest_main)

# 包含 Google Test 的 CTest 集成
include(GoogleTest)
gtest_discover_tests(intToRoman-tests)

# 设置包含目录
target_include_directories(intToRoman PRIVATE src)