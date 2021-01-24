#include <iostream>
#include <graphs/Graph.h>
#include "example_utils.h"
#include "undirected_graph_example.h"

void undirected_graph_example::run(std::ostream &out) {
    auto graph = new UndirectedGraph(10);
    graph->addEdge(1, 2);
    graph->addEdge(3, 5);

    out << ">>> UNDIRECTED GRAPH EXAMPLE:\n\n";

    out << "Number of vertices: " << graph->getNumberOfVertices() << '\n';
    out << "Number of isolated vertices: " << graph->getNumberOfIsolatedVertices() << '\n';
    out << "Number of edges: " << graph->getNumberOfEdges() << '\n';
    out << '\n';

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

    out << "<<< END UNDIRECTED GRAPH EXAMPLE;\n" << std::endl;

    delete graph;
}
