#include <iostream>
#include "example_utils.h"
#include "undirected_graph_example.h"
#include "../lib/Graph.h"

void undirected_graph_example::run(std::ostream &out) {
    auto graph = new UndirectedGraph(10);
    graph->addEdge(1, 2);
    graph->addEdge(3, 5);

    out << ">>> UNDIRECTED GRAPH EXAMPLE:\n\n";

    out << "Number of vertices: " << graph->getNumberOfVertices() << '\n';
    out << "Number of isolated vertices: " << graph->getNumberOfIsolatedVertices() << "\n\n";

    auto adjacencyMatrix = graph->createAdjacencyMatrix();

    out << "Adjacency matrix:\n";
    example_utils::print_matrix(adjacencyMatrix, out);
    out << '\n';

    delete adjacencyMatrix;

    auto incidenceMatrix = graph->createIncidenceMatrix();

    out << "Incidence matrix:\n";
    example_utils::print_matrix(incidenceMatrix, out);
    out << '\n';

    delete incidenceMatrix;

    out << "<<< END UNDIRECTED GRAPH EXAMPLE;\n" << std::endl;

    delete graph;
}
