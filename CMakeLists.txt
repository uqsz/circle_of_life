cmake_minimum_required(VERSION 3.24)
project(darwin_s_world)

include(FetchContent)
set(BUILD_SHARED_LIBS off)
FETCHCONTENT_DECLARE(SFML GIT_REPOSITORY https://github.com/SFML/SFML.git GIT_TAG 2.5.1)
FETCHCONTENT_MAKEAVAILABLE(SFML)

set(CMAKE_CXX_STANDARD 14)

include_directories(src/entity)
include_directories(src/evolution)
include_directories(src/headers)
include_directories(src/map)

add_executable(darwin_s_world src/main.cpp src/gui/gui.cpp src/gui/gui.h)

target_link_libraries(darwin_s_world sfml-graphics)
