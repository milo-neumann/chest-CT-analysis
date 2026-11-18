cmake_minimum_required(VERSION 3.20)

project(ITKtesting LANGUAGES CXX)

find_package(ITK REQUIRED)
include(${ITK_USE_FILE})

add_executable(ITKtesting main.cpp)

target_link_libraries(ITKtesting PRIVATE ${ITK_LIBRARIES})