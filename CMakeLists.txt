cmake_minimum_required(VERSION 3.19)
project(snake_game)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0")
#set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0")
#set(CMAKE_CXX_FLAGS "-Wfloat-equal -Wlogical-op -Wall -Wextra -Wno-unused-result -Wshadow -D_GLIBCXX_DEBUG -fsanitize=address -fsanitize=undefined -fstack-protector-strong -fstack-check -fno-sanitize-recover=all")


find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(snake_game main.cpp Map.h Map.cpp snakeFiles/PartOfSnake.h snakeFiles/PartOfSnake.cpp Fruit.cpp Fruit.h Constants.h snakeFiles/Snake.cpp snakeFiles/Snake.h brain/brain.h brain/brain.cpp)

target_link_libraries(snake_game sfml-graphics sfml-audio)