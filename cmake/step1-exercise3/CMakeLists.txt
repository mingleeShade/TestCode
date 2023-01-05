cmake_minimum_required(VERSION 3.22)

project(Tutorial VERSION 1.0)

configure_file(TutorialConfig.h.in TutorialConfig.h)

add_executable(Tutorial tutorial.cxx)

message(STATUS "PROJECT_BINARY_DIR: ${PROJECT_BINARY_DIR}; SOURCE: ${PROJECT_SOURCE_DIR}")
# target_include_directories(Tutorial PUBLIC
#     "${PROJECT_BINARY_DIR}"
#     )
