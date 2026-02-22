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

# 启用测试
enable_testing()

# 检测编译器类型并设置相应的 gtest 查找策略
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "MinGW")
    # MinGW 编译器 - 尝试使用 pkg-config 或手动查找
    message(STATUS "Detected MinGW compiler, using alternative gtest detection")

    # 方法1: 尝试通过 pkg-config 查找
    find_package(PkgConfig QUIET)

    if(PKG_CONFIG_FOUND)
        pkg_check_modules(GTEST QUIET gtest_main)
    endif()

    # 如果 pkg-config 失败，尝试手动查找
    if(NOT GTEST_FOUND)
        # 查找系统安装的 gtest
        find_path(GTEST_INCLUDE_DIR gtest/gtest.h)
        find_library(GTEST_LIBRARY gtest)
        find_library(GTEST_MAIN_LIBRARY gtest_main)

        if(GTEST_INCLUDE_DIR AND GTEST_LIBRARY AND GTEST_MAIN_LIBRARY)
            set(GTEST_FOUND TRUE)
            message(STATUS "Found gtest: ${GTEST_INCLUDE_DIR}")
        endif()
    endif()
else()
    # 非 MinGW 编译器 - 使用标准的 find_package
    find_package(GTest CONFIG REQUIRED)
endif()

# 创建测试可执行文件
add_executable(intToRoman-tests
        tests/intToRoman_test.cpp
        src/solution.cpp
)

# 根据找到的 gtest 版本进行链接
if(GTEST_FOUND)
    if(TARGET GTest::gtest_main)
        # 标准 vcpkg 安装
        target_link_libraries(intToRoman-tests GTest::gtest_main)
        target_include_directories(intToRoman-tests PRIVATE ${GTEST_INCLUDE_DIRS})
    else()
        # 手动链接方式
        target_link_libraries(intToRoman-tests
                ${GTEST_MAIN_LIBRARY}
                ${GTEST_LIBRARY}
        )
        target_include_directories(intToRoman-tests PRIVATE ${GTEST_INCLUDE_DIR})
    endif()
else()
    message(WARNING "gtest not found, tests will not be built")
    # 可以选择在这里禁用测试构建
endif()

# 包含 Google Test 的 CTest 集成（仅当 gtest 可用时）
if(GTEST_FOUND AND TARGET GTest::gtest_main)
    include(GoogleTest)
    gtest_discover_tests(intToRoman-tests)
endif()

# 设置包含目录
target_include_directories(intToRoman PRIVATE src)
