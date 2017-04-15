cmake_minimum_required(VERSION 3.7)
project(testGame2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp components.h systems.cpp systems.h world.cpp world.h utilities.cpp utilities.h)
add_executable(testGame2 ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(testGame2 ${SFML_LIBRARIES})
endif()