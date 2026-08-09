cmake_minimum_required(VERSION 3.21)

project(RiverModMenu VERSION 1.0.0)

add_library(${PROJECT_NAME} SHARED
src/main.cpp
)

target_link_libraries(${PROJECT_NAME}
geode-sdk
)