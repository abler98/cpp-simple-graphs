#include <iostream>
#include "DirectedGraphExample.h"
#include "../lib/Graph.h"

void DirectedGraphExample::run() {
    auto graph = new DirectedGraph(10);
    graph->addEdge(1, 2);

    std::cout << ">>> DIRECTED GRAPH EXAMPLE:" << std::endl;
    std::cout << "Number of vertices: " << graph->getNumberOfVertices() << std::endl;
    std::cout << "Number of isolated vertices: " << graph->getNumberOfIsolatedVertices() << std::endl;
    std::cout << "<<< END DIRECTED GRAPH EXAMPLE:" << std::endl << std::endl;

    delete graph;
}
