cmake_minimum_required(VERSION 3.17)

project(snake_sfml)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic")

find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

file(GLOB sources CONFIGURE_DEPENDS "src/*.cc")
add_executable(snake_sfml "${sources}")
target_include_directories(snake_sfml PRIVATE "src")

target_link_libraries(snake_sfml sfml-graphics)
