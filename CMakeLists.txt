cmake_minimum_required(VERSION 3.31)
project(chippp-8)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")
if(CMAKE_EXPORT_COMPILE_COMMANDS)
  set(CMAKE_CXX_STANDARD_INCLUDE_DIRECTORIES 
      ${CMAKE_CXX_IMPLICIT_INCLUDE_DIRECTORIES})
endif()
set(CMAKE_CXX_SCAN_FOR_MODULES OFF)
set(CMAKE_CXX_FLAGS "-Werror -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion")

add_executable(chippp-8 src/main.cpp src/emulator/Environment.cpp src/emulator/Emulator.cpp)

target_include_directories(chippp-8 PRIVATE "$ENV{HOME}/.local/include")
target_link_directories(chippp-8 PRIVATE "$ENV{HOME}/.local/lib")
target_link_libraries(chippp-8 PRIVATE raylib)
