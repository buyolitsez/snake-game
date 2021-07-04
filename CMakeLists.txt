cmake_minimum_required(VERSION 3.19)
project(snake_game)

set(CMAKE_CXX_STANDARD 20)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(snake_game main.cpp map.h map.cpp partOfSnake.h partOfSnake.cpp fruit.cpp fruit.h)

target_link_libraries(snake_game sfml-graphics sfml-audio)