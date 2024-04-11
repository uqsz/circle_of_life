cmake_minimum_required(VERSION 3.24)
project(darwin_s_world)
set(CMAKE_CXX_STANDARD 17)


include(FetchContent)
set(BUILD_SHARED_LIBS off)

FETCHCONTENT_DECLARE(SFML GIT_REPOSITORY https://github.com/SFML/SFML.git GIT_TAG 2.6.1)
FETCHCONTENT_MAKEAVAILABLE(SFML)


include_directories(src/entity)
include_directories(src/evolution)
include_directories(src/headers)
include_directories(src/map)
include_directories(resources)

FETCHCONTENT_DECLARE(
        Nana
        GIT_REPOSITORY https://github.com/cnjinhao/nana.git
        GIT_TAG v1.7.4
)

FETCHCONTENT_MAKEAVAILABLE(Nana)


add_executable(darwin_s_world src/main.cpp src/simulation/simulation.cpp src/entity/entity.cpp src/map/map.cpp src/evolution/evolution.cpp src/gui/gui.cpp)

target_link_libraries(darwin_s_world
        sfml-graphics nana)
