add_library(
        simple_graphs_lib
        STATIC
        include/graphs/options.h
        include/graphs/Graph.h
        include/graphs/Element.h
        include/graphs/Vertex.h
        include/graphs/Matrix.h
        src/graphs/Graph.cpp
        src/graphs/Element.cpp
        src/graphs/Matrix.cpp
)

target_include_directories(
        simple_graphs_lib
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)
