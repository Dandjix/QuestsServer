cmake_minimum_required(VERSION 4.0)
project(MyProject LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 26)

find_package(Quests REQUIRED)

file(GLOB_RECURSE SERVER_SOURCES src/*.cpp)


add_executable(${PROJECT_NAME} ${SERVER_SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE Quests::Quests)