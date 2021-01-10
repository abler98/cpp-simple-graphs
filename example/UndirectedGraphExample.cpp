#include <iostream>
#include "UndirectedGraphExample.h"
#include "../lib/Graph.h"

void UndirectedGraphExample::run() {
    auto graph = new UndirectedGraph(10);
    graph->addEdge(1, 2);

    std::cout << ">>> UNDIRECTED GRAPH EXAMPLE:" << std::endl;
    std::cout << "Number of vertices: " << graph->getNumberOfVertices() << std::endl;
    std::cout << "Number of isolated vertices: " << graph->getNumberOfIsolatedVertices() << std::endl;
    std::cout << "<<< END UNDIRECTED GRAPH EXAMPLE:" << std::endl << std::endl;
}
