cmake_minimum_required(VERSION 3.27)

set(EXEC_NAME "Prog")

file(GLOB SRC_FILES "src/*.cpp")

project(A-star_pathfinding)

add_executable(${EXEC_NAME} ${SRC_FILES})

target_include_directories(${EXEC_NAME} PUBLIC src)
