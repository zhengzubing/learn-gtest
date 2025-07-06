cmake_minimum_required(VERSION 3.11)  # FetchContent 最低要求
project(learn_gtest)

set(CMAKE_CXX_STANDARD 20)

# 添加 Google Test
include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG main
)
FetchContent_MakeAvailable(googletest)

# 测试可执行文件
add_executable(learn_gtest
        test/test_case.cpp
)

target_link_libraries(learn_gtest
        gtest
)

## 启用测试
#enable_testing()
#add_test(NAME all_tests COMMAND learn_gtest)