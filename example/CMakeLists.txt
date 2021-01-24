add_executable(
        simple_graphs_example
        main.cpp
        example_options.h
        example_utils.cpp
        example_utils.h
        directed_graph_example.cpp
        directed_graph_example.h
        undirected_graph_example.cpp
        undirected_graph_example.h
)

target_link_libraries(
        simple_graphs_example
        PUBLIC
        simple_graphs_lib
)
