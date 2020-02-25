cmake_minimum_required(VERSION 3.15)
project(Jonnalagadda-VinayMadhav)

SET(CMAKE_INSTALL_RPATH "")

set(CMAKE_CXX_STANDARD 11)

add_library(Jonnalagadda-VinayMadhav SHARED matrix_utils.cpp matrix_utils.h)

add_executable(main main.cpp)

target_link_libraries(main Jonnalagadda-VinayMadhav)




