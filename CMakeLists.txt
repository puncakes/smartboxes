cmake_minimum_required(VERSION 3.5)
project(smart_boxes)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
set(CMAKE_CXX_STANDARD 14)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

message (build dir: ${CMAKE_BINARY_DIR})

add_compile_definitions(GL_SILENCE_DEPRECATION)

add_subdirectory(lib/nanogui)
include_directories(lib/nanogui/include)
include_directories(lib/glm)
include_directories(${NANOGUI_EXTRA_INCS})
add_definitions(${NANOGUI_EXTRA_DEFS})

include_directories(lib/glm)

add_subdirectory(lib/Box2D-cmake)

set(JSON_BuildTests OFF CACHE INTERNAL "")
add_subdirectory(lib/json)

add_subdirectory(lib/SOIL)
include_directories(lib/SOIL/src)

#easylogging doesn't compile into a lib so just include it's source/header
include_directories(lib/easyloggingpp/src)

file(COPY configs DESTINATION ${CMAKE_BINARY_DIR})

set(SOURCE_FILES main.cpp game.cpp menu.cpp physicshelper.cpp inputmanager.cpp debugdraw.cpp shapes/shape.cpp shapes/rectangle.cpp lib/easyloggingpp/src/easylogging++.cc commandmanager.cpp Commands/CreateBoxCommand.cpp Commands/LambdaCommand.cpp Commands/LambdaCommand.h Robot.cpp Robot.h RobotParts/IRobotPart.h RobotParts/RBody.cpp RobotParts/RBody.h GraphicsHelper.cpp GraphicsHelper.h Commands/CreateRobotCommand.cpp Commands/CreateRobotCommand.h
        camera.cpp camera.h Sprite.cpp Sprite.h Shader.h Shader.cpp
        cursor_tools/ICursor.h
        cursor_tools/create_box.cpp)
add_executable(smart_boxes ${SOURCE_FILES})

target_link_libraries(smart_boxes Box2D-cmake nanogui ${NANOGUI_EXTRA_LIBS} nlohmann_json SOIL)
