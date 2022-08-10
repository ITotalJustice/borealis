cmake_minimum_required(VERSION 3.20.0)

project(borealis
    LANGUAGES C CXX
)

find_program(CLANGD_INSTALLED clangd)

if (CLANGD_INSTALLED)
    set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
    message(STATUS "found clangd: generating compile_commands.json to ${CMAKE_BINARY_DIR}/compile_commands.json")
else()
    message(STATUS "cant find clangd: not generating compile_commands.json")
endif()

message(STATUS "SYSTEM: ${CMAKE_SYSTEM_NAME}")
message(STATUS "COMPILER: ${CMAKE_CXX_COMPILER_ID}")

option(DEMO "build demo" ON)

if (DEMO)
    add_subdirectory(demo)
endif()

add_subdirectory(library)
