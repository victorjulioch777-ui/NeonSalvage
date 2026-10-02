cmake_minimum_required(VERSION 3.20)

project(
    NeonSalvageNative
    VERSION 0.1.0
    LANGUAGES C CXX
)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# =========================================================
# neon_core
# =========================================================

add_library(
    neon_core
    STATIC
    c/src/neon_core.c
)

target_include_directories(
    neon_core
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/c/include
)

# =========================================================
# Tests
# =========================================================

enable_testing()

add_executable(
    neon_core_tests
    c/tests/test_neon_core.c
)

target_link_libraries(
    neon_core_tests
    PRIVATE
    neon_core
)

add_test(
    NAME neon_core_tests
    COMMAND neon_core_tests
)