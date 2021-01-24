#include <vector>
#include "Element.h"
#include "options.h"
#include "Vertex.h"
#include "Matrix.h"

#ifndef SIMPLE_GRAPHS_GRAPH_H
#define SIMPLE_GRAPHS_GRAPH_H


class Graph {
public:
    virtual int getNumberOfVertices() = 0;
    virtual int getNumberOfIsolatedVertices() = 0;
    virtual int getNumberOfEdges() = 0;
    virtual void addEdge(int start, int end) = 0;
    virtual int getVertexDegree(int v) = 0;
    virtual std::vector<int> *depthFirstSearch(int v) = 0;
    virtual Matrix *createAdjacencyMatrix() = 0;
    virtual Matrix *createIncidenceMatrix() = 0;
};


class AbstractGraph : public Graph {
private:
    int numberOfVertices;
    Vertex *vertices;
    Element *adjacencyMatrix;

protected:
#ifndef SIMPLE_GRAPHS_OPT_COMPUTE_NUMBER_OF_EDGES
    int numberOfEdges = 0;
#endif

    explicit AbstractGraph(int numberOfVertices);

    [[maybe_unused]] Vertex *getVertex(int v);
    [[maybe_unused]] Vertex *getVertexAt(int i);
    Element *getElement(int i, int j);
    [[nodiscard]] int getVertexIndex(int v) const;
    int getVertexDegreeAt(int i);
    std::vector<int> *depthFirstSearchInternal(int i, bool *visited);

public:
    ~AbstractGraph();

    int getNumberOfVertices() override;
    int getNumberOfIsolatedVertices() override;
    int getVertexDegree(int v) override;
    std::vector<int> *depthFirstSearch(int v) override;
    Matrix *createAdjacencyMatrix() override;
};


class DirectedGraph : public AbstractGraph {
public:
    explicit DirectedGraph(int numberOfVertices) : AbstractGraph(numberOfVertices) {}

    void addEdge(int start, int end) override;
    int getNumberOfEdges() override;
    Matrix *createIncidenceMatrix() override;
};


class UndirectedGraph : public AbstractGraph {
public:
    explicit UndirectedGraph(int numberOfVertices) : AbstractGraph(numberOfVertices) {}

    void addEdge(int start, int end) override;
    int getNumberOfEdges() override;
    Matrix *createIncidenceMatrix() override;
};


#endif //SIMPLE_GRAPHS_GRAPH_H
