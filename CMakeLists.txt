cmake_minimum_required(VERSION 3.25.1)
project(presets)

file(GLOB SOURCES *.cpp)
add_executable(main ${SOURCES})

if(NOT DEFINED PRESET_NAME)
    message(FATAL_ERROR "Must be run with a CMake preset")
else()
    message(STATUS "Using preset: ${PRESET_NAME}")
endif()

if(BUGS)
    target_compile_definitions(main PRIVATE BUGS=1)
endif()

if(USE_ALT_LOGIC)
    target_compile_definitions(main PRIVATE USE_ALT_LOGIC=1)
endif()

if(EXTRA_ANALYSIS)
    target_compile_definitions(main PRIVATE EXTRA_ANALYSIS=1)
endif()
