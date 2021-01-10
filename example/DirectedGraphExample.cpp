#include <iostream>
#include "DirectedGraphExample.h"
#include "../lib/Graph.h"

void DirectedGraphExample::run() {
    auto directedGraph = new DirectedGraph(10);
    directedGraph->addEdge(1, 2);

    std::cout << ">>> DIRECTED GRAPH EXAMPLE:" << std::endl;
    std::cout << "Number of vertices: " << directedGraph->getNumberOfVertices() << std::endl;
    std::cout << "Number of isolated vertices: " << directedGraph->getNumberOfIsolatedVertices() << std::endl;
    std::cout << "<<< END DIRECTED GRAPH EXAMPLE:" << std::endl << std::endl;
}
