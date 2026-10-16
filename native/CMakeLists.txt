cmake_minimum_required(VERSION 3.20)

project(
    NeonSalvageNative
    VERSION 0.2.0
    LANGUAGES C CXX
)


# =========================================================
# Language standards
# =========================================================

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# =========================================================
# godot-cpp
# =========================================================

set(
    GODOTCPP_API_VERSION
    "4.3"
    CACHE STRING
    "Godot API version"
    FORCE
)

add_subdirectory(
    third_party/godot-cpp
    SYSTEM
)


# =========================================================
# neon_core - C
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

set_target_properties(
    neon_core
    PROPERTIES
    POSITION_INDEPENDENT_CODE ON
)


# =========================================================
# GDExtension - C++
# =========================================================

add_library(
    neon_native
    SHARED

    cpp/src/neon_core_bridge.cpp
    cpp/src/register_types.cpp
)

target_include_directories(
    neon_native
    PRIVATE

    ${CMAKE_CURRENT_SOURCE_DIR}/cpp/include
    ${CMAKE_CURRENT_SOURCE_DIR}/c/include
)

target_link_libraries(
    neon_native
    PRIVATE

    godot-cpp
    neon_core
)

set_target_properties(
    neon_native

    PROPERTIES

    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON

    OUTPUT_NAME "neon_native"

    LIBRARY_OUTPUT_DIRECTORY
    "${CMAKE_CURRENT_LIST_DIR}/../godot/bin"
)


# =========================================================
# C tests
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