#include <iostream>
#include "ExampleUtils.h"
#include "DirectedGraphExample.h"
#include "../lib/Graph.h"

void DirectedGraphExample::run() {
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

    std::cout << ">>> DIRECTED GRAPH EXAMPLE:" << std::endl;

    std::cout << "Number of vertices: " << graph->getNumberOfVertices() << std::endl;
    std::cout << "Number of isolated vertices: " << graph->getNumberOfIsolatedVertices() << std::endl;

    std::cout << "Vertex degree [1]: " << graph->getVertexDegree(1) << std::endl;
    std::cout << "Vertex degree [7]: " << graph->getVertexDegree(7) << std::endl;
    std::cout << "Vertex degree [9]: " << graph->getVertexDegree(9) << std::endl;

    auto dfs1 = graph->depthFirstSearch(1);
    auto dfs7 = graph->depthFirstSearch(7);
    auto dfs9 = graph->depthFirstSearch(9);

    std::cout << "Depth-first search [1]: " << ExampleUtils::intVectorToString(dfs1) << std::endl;
    std::cout << "Depth-first search [7]: " << ExampleUtils::intVectorToString(dfs7) << std::endl;
    std::cout << "Depth-first search [9]: " << ExampleUtils::intVectorToString(dfs9) << std::endl;

    delete dfs1;
    delete dfs7;
    delete dfs9;

    std::cout << "<<< END DIRECTED GRAPH EXAMPLE:" << std::endl << std::endl;

    delete graph;
}
