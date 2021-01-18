#include <iostream>
#include "example_utils.h"
#include "directed_graph_example.h"
#include "../lib/Graph.h"

void directed_graph_example::run(std::ostream &out) {
    auto graph = new DirectedGraph(10);

    graph->addEdge(1, 2);
    graph->addEdge(2, 3);
    graph->addEdge(3, 5);
    graph->addEdge(1, 5);
    graph->addEdge(2, 4);
    graph->addEdge(4, 6);
    graph->addEdge(6, 1);
    graph->addEdge(7, 3);
    graph->addEdge(7, 8);
    graph->addEdge(8, 6);
    graph->addEdge(8, 7);

    out << ">>> DIRECTED GRAPH EXAMPLE:\n\n";

    out << "Number of vertices: " << graph->getNumberOfVertices() << '\n';
    out << "Number of isolated vertices: " << graph->getNumberOfIsolatedVertices() << '\n';
    out << "Number of edges: " << graph->getNumberOfEdges() << "\n\n";

    out << "Vertex degree [1]: " << graph->getVertexDegree(1) << '\n';
    out << "Vertex degree [7]: " << graph->getVertexDegree(7) << '\n';
    out << "Vertex degree [9]: " << graph->getVertexDegree(9) << "\n\n";

    auto dfs1 = graph->depthFirstSearch(1);
    auto dfs7 = graph->depthFirstSearch(7);
    auto dfs9 = graph->depthFirstSearch(9);

    out << "Depth-first search [1]: " << example_utils::int_vector_to_string(dfs1) << '\n';
    out << "Depth-first search [7]: " << example_utils::int_vector_to_string(dfs7) << '\n';
    out << "Depth-first search [9]: " << example_utils::int_vector_to_string(dfs9) << "\n\n";

    delete dfs1;
    delete dfs7;
    delete dfs9;

    auto adjacency_matrix = graph->createAdjacencyMatrix();
    auto incidence_matrix = graph->createIncidenceMatrix();

    out << "Adjacency matrix:\n";
    example_utils::print_matrix(adjacency_matrix, out);
    out << '\n';

    out << "Incidence matrix:\n";
    example_utils::print_matrix(incidence_matrix, out);
    out << '\n';

    delete adjacency_matrix;
    delete incidence_matrix;

    out << "<<< END DIRECTED GRAPH EXAMPLE;\n" << std::endl;

    delete graph;
}
