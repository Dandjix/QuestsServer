cmake_minimum_required(VERSION 4.0)
project(QuestsServer LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 26)

find_package(Quests REQUIRED)

file(GLOB_RECURSE SOURCES src/*.cpp)
file(GLOB_RECURSE IMPORTED_SOURCES imported/*.cpp)


add_executable(${PROJECT_NAME} ${IMPORTED_SOURCES} ${SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE Quests::Quests)

target_include_directories(${PROJECT_NAME} PRIVATE
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/imported
)