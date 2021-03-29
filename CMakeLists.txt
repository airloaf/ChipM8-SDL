cmake_minimum_required(VERSION 3.9)

# In case of linux, tell it to places binaries in bin folder
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Library locations (Change these to the appropriate path on your machine)
if (WIN32)
    set(INCLUDE_DIR C:/DevelopmentLibraries/include/)
    set(LIB_DIR C:/DevelopmentLibraries/lib/x64)
else()
#################### UNIX like machines
    set(INCLUDE_DIR /usr/local/include/)
    set(LIB_DIR /usr/local/lib)
endif()

include_directories(${INCLUDE_DIR})
link_directories(${LIB_DIR})




project(ChipM8_Project)

# Create ChipM8 executable
file(GLOB_RECURSE SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} src/*.cpp)
add_executable(ChipM8-SDL ${SRCS})

# Link Libraries
target_link_libraries(ChipM8-SDL SDL2)
target_link_libraries(ChipM8-SDL ChipM8)

# Platform specific options
if (EMSCRIPTEN)
    set(CMAKE_EXECUTABLE_SUFFIX .html)
    set(CMAKE_C_FLAGS "-s USE_SDL=2")
    set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -s FORCE_FILESYSTEM=1")
    set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -s EXTRA_EXPORTED_RUNTIME_METHODS=['ccall']")
else()
    target_link_libraries(ChipM8-SDL SDL2main)
endif()