cmake_minimum_required(VERSION 3.16)
project(simple_graphs)

set(CMAKE_CXX_STANDARD 20)

add_executable(
        simple_graphs
        main.cpp
        example/example_options.h
        example/example_utils.cpp
        example/example_utils.h
        example/directed_graph_example.cpp
        example/directed_graph_example.h
        example/undirected_graph_example.cpp
        example/undirected_graph_example.h
        lib/Graph.cpp
        lib/Graph.h
        lib/Element.cpp
        lib/Element.h
        lib/Vertex.h
        lib/options.h
)
