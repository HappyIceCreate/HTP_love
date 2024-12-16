cmake_minimum_required(VERSION 3.15)



set(PROJECT_NAME dzshk)
project("${PROJECT_NAME}")

set(CMAKE_CXX_STANDART 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDART_REQUIRED TRUE)


add_executable("${PROJECT_NAME}" laba8.1.cpp laba8.2.cpp laba8.3.cpp)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/origin.txt ${CMAKE_CURRENT_BINARY_DIR}/DEBUG COPYONLY)