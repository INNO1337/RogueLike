cmake_minimum_required(VERSION 3.15)
project(RogueLike_Remastered)

set(CMAKE_CXX_COMPILER  "-lncurses -fsanitize=address -fomit-frame-pointer -lasan")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_COMPILER /usr/bin/clang++)
set(CMAKE_CC_COMPILER /usr/bin/clang)


add_executable(RogueLike_Remastered main.cpp Entities.hpp Entities.cpp Map.cpp Map.hpp Loop.cpp Loop.hpp)
target_link_libraries(RogueLike_Remastered curses)