cmake_minimum_required(VERSION 3.16)
project(graph_visualizer)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(SDL3 REQUIRED)
add_executable(app
    main.cpp
    graph.cpp
)
target_link_libraries(app SDL3::SDL3)
