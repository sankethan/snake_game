cmake_minimum_required(VERSION 3.19.2)

project(snake_game)

file(COPY "resources" DESTINATION "${CMAKE_BINARY_DIR}")

add_library(snake STATIC snake.cpp)
target_include_directories(snake PUBLIC ./)

add_library(scoreboard STATIC scoreboard.cpp)
target_include_directories(scoreboard PUBLIC ./)

add_library(fruit STATIC fruit.cpp)
target_include_directories(fruit PUBLIC ./)


add_executable(snake_game main.cpp)
add_executable(snake_game_win WIN32 main.cpp)

target_link_libraries(snake_game PRIVATE snake)
target_link_libraries(snake_game PRIVATE fruit)
target_link_libraries(snake_game PRIVATE scoreboard)
target_link_libraries(snake_game PRIVATE m)
target_link_libraries(snake_game PRIVATE raylib)
target_link_libraries(snake_game PRIVATE GL)
target_link_libraries(snake_game PRIVATE pthread)
target_link_libraries(snake_game PRIVATE dl)
target_link_libraries(snake_game PRIVATE rt)
target_link_libraries(snake_game PRIVATE X11)

target_link_libraries(snake_game_win PRIVATE snake)
target_link_libraries(snake_game_win PRIVATE fruit)
target_link_libraries(snake_game_win PRIVATE scoreboard)
target_link_libraries(snake_game_win PRIVATE m)
target_link_libraries(snake_game_win PRIVATE raylib)
target_link_libraries(snake_game_win PRIVATE GL)
target_link_libraries(snake_game_win PRIVATE pthread)
target_link_libraries(snake_game_win PRIVATE dl)
target_link_libraries(snake_game_win PRIVATE rt)
target_link_libraries(snake_game_win PRIVATE X11)