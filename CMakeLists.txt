cmake_minimum_required(VERSION 3.24)
project(darwin_s_world)
set(CMAKE_CXX_STANDARD 17)

# list of source files
set(SOURCE_FILES
        src/main.cpp
        src/simulation/simulation.cpp
        src/entity/entity.cpp
        src/map/map.cpp
        src/evolution/evolution.cpp
        src/gui/gui.cpp
)

# list of libraries
set(LIBRARIES sfml-graphics nana)

# fetch content
include(FetchContent)
set(BUILD_EXAMPLES OFF CACHE INTERNAL "")

# SFML library fetch
set(SFML_VERSION 2.6.1)
FetchContent_Declare(sfml
        URL https://github.com/SFML/SFML/archive/refs/tags/${SFML_VERSION}.tar.gz
        FIND_PACKAGE_ARGS ${SFML_VERSION}
        )
FetchContent_MakeAvailable(sfml)

# Nana library fetch
set(NANA_VERSION v1.7.4)
FetchContent_Declare(
        nana
        URL https://github.com/cnjinhao/nana/archive/refs/tags/${NANA_VERSION}.tar.gz
)
FetchContent_MakeAvailable(nana)


# adding source
include_directories(src)

# creating executable
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# linking libraries
target_link_libraries(${PROJECT_NAME} ${LIBRARIES})

