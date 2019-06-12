cmake_minimum_required(VERSION 3.5)
project(Editor)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_compile_definitions(GL_SILENCE_DEPRECATION)

add_subdirectory(lib/nanogui)
include_directories(lib/nanogui/include)
include_directories(${NANOGUI_EXTRA_INCS})
add_definitions(${NANOGUI_EXTRA_DEFS})

add_subdirectory(lib/Box2D-cmake)

set(SOURCE_FILES main.cpp)
add_executable(Editor ${SOURCE_FILES})
target_link_libraries(Editor Box2D-cmake nanogui ${NANOGUI_EXTRA_LIBS})
