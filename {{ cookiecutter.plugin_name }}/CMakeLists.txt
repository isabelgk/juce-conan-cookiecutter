cmake_minimum_required(VERSION 3.19)
project({{ cookiecutter.plugin_name.upper() }} VERSION 0.1.0)

set(CMAKE_CXX_STANDARD {{ cookiecutter.cpp_standard }})
set(CMAKE_CSS_STANDARD_REQUIRED ON)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build, options are: Debug Release" FORCE)
endif()


# Pull in dependencies
include(${CMAKE_CURRENT_LIST_DIR}/cmake/{{ cookiecutter.plugin_name }}Conan.cmake)


# Set up JUCE
add_subdirectory(
    ${CONAN_JUCE_ROOT}
    ${CMAKE_BINARY_DIR}/JUCE
    EXCLUDE_FROM_ALL
    )

set(BINARY_RESOURCES "")
set(HAS_BINARY_RESOURCES FALSE)

if(HAS_BINARY_RESOURCES)
    juce_add_binary_data(BinaryResources SOURCES ${BINARY_RESOURCES})
endif()


# Target JUCE Plugin
include("${CMAKE_CURRENT_LIST_DIR}/cmake/{{ cookiecutter.plugin_name }}Plugin.cmake")
