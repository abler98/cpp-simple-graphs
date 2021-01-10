cmake_minimum_required(VERSION 3.16)
project(simple_graphs)

set(CMAKE_CXX_STANDARD 20)

add_executable(
        simple_graphs
        main.cpp
        example/ExampleUtils.cpp
        example/ExampleUtils.h
        example/DirectedGraphExample.cpp
        example/DirectedGraphExample.h
        example/UndirectedGraphExample.cpp
        example/UndirectedGraphExample.h
        lib/Graph.cpp
        lib/Graph.h
        lib/Element.cpp
        lib/Element.h
        lib/Vertex.h
        lib/options.h
)
