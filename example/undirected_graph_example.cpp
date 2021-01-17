#include <iostream>
#include "undirected_graph_example.h"
#include "../lib/Graph.h"

void undirected_graph_example::run(std::ostream &out) {
    auto graph = new UndirectedGraph(10);
    graph->addEdge(1, 2);

    out << ">>> UNDIRECTED GRAPH EXAMPLE:\n";
    out << "Number of vertices: " << graph->getNumberOfVertices() << '\n';
    out << "Number of isolated vertices: " << graph->getNumberOfIsolatedVertices() << '\n';
    out << "<<< END UNDIRECTED GRAPH EXAMPLE;\n" << std::endl;

    delete graph;
}
