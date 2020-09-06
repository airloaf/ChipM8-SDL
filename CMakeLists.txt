cmake_minimum_required(VERSION 3.9)

set(INCLUDE_DIR C:/DevelopmentLibraries/include/)
set(LIB_DIR C:/DevelopmentLibraries/lib/x64)

project(ChipM8_Project)

file(GLOB_RECURSE SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} src/*.cpp)
add_executable(ChipM8-SDL ${SRCS})

# Set include and link directories
target_include_directories(ChipM8-SDL PUBLIC ${INCLUDE_DIR})
target_link_directories(ChipM8-SDL PUBLIC ${LIB_DIR})

# Link Libraries
target_link_libraries(ChipM8-SDL PUBLIC SDL2)
target_link_libraries(ChipM8-SDL PUBLIC SDL2main)
target_link_libraries(ChipM8-SDL PUBLIC ChipM8)