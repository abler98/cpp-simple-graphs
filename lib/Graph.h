#include <vector>
#include "Element.h"
#include "Vertex.h"

#ifndef SIMPLE_GRAPHS_GRAPH_H
#define SIMPLE_GRAPHS_GRAPH_H


class Graph {
public:
    virtual int getNumberOfVertices() = 0;
    virtual int getNumberOfIsolatedVertices() = 0;
    virtual void addEdge(int start, int end) = 0;
    virtual int getVertexDegree(int v) = 0;
    virtual std::vector<int> *depthFirstSearch(int v) = 0;
};


class AbstractGraph : public Graph {
private:
    int numberOfVertices;
    Vertex *vertices;
    Element *adjacencyMatrix;

protected:
    explicit AbstractGraph(int numberOfVertices);

    [[maybe_unused]] Vertex *getVertex(int v);
    Vertex *getVertexAt(int i);
    Element *getElement(int i, int j);
    [[nodiscard]] inline int getVertexIndex(int v) const;
    int getVertexDegreeAt(int i);
    std::vector<int> *depthFirstSearchInternal(int i, bool *visited);

public:
    ~AbstractGraph();

    int getNumberOfVertices() override;
    int getNumberOfIsolatedVertices() override;
    int getVertexDegree(int v) override;
    std::vector<int> *depthFirstSearch(int v) override;
};


class DirectedGraph : public AbstractGraph {
public:
    explicit DirectedGraph(int numberOfVertices) : AbstractGraph(numberOfVertices) {}

    void addEdge(int start, int end) override;
};


class UndirectedGraph : public AbstractGraph {
public:
    explicit UndirectedGraph(int numberOfVertices) : AbstractGraph(numberOfVertices) {}

    void addEdge(int start, int end) override;
};


#endif //SIMPLE_GRAPHS_GRAPH_H
