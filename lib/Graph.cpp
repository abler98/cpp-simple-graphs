#include <stdexcept>
#include "options.h"
#include "Graph.h"

//region AbstractGraph
AbstractGraph::AbstractGraph(int numberOfVertices) {
    this->numberOfVertices = numberOfVertices;
    this->vertices = new Vertex[numberOfVertices];
    this->adjacencyMatrix = new Element[numberOfVertices * numberOfVertices];
}

AbstractGraph::~AbstractGraph() {
    delete[] this->adjacencyMatrix;
}

Vertex *AbstractGraph::getVertex(int v) {
    if (v < 0 || v >= this->numberOfVertices) {
        throw std::out_of_range("Out of range error");
    }

    return &this->vertices[v];
}

Element *AbstractGraph::getElement(int i, int j) {
    if (i < 0 || i >= this->numberOfVertices || j < 0 || j >= this->numberOfVertices) {
        throw std::out_of_range("Adjacency matrix out of range error");
    }

    return &this->adjacencyMatrix[j * this->numberOfVertices + i];
}

int AbstractGraph::getNumberOfVertices() {
    return this->numberOfVertices;
}

int AbstractGraph::getNumberOfIsolatedVertices() {
    int result = 0;

    for (int i = 0; i < this->numberOfVertices; ++i) {
        if (this->getVertexDegree(i) == 0) {
            result++;
        }
    }

    return result;
}

int AbstractGraph::getVertexDegree(int v) {
#ifdef SIMPLE_GRAPHS_OPT_COMPUTE_VERTEX_DEGREE
    int result = 0;

    for (int i = 0; i < this->numberOfVertices; ++i) {
        if (this->getElement(v, i)->hasValue()) {
            ++result;
        }
        if (this->getElement(i, v)->hasValue()) {
            ++result;
        }
    }

    return result;
#else
    return this->getVertex(v)->degree;
#endif
}
//endregion


//region DirectedGraph
void DirectedGraph::addEdge(int start, int end) {
    *this->getElement(start - 1, end - 1) = 1;

#ifndef SIMPLE_GRAPHS_OPT_COMPUTE_VERTEX_DEGREE
    this->getVertex(start)->degree += 1;
    this->getVertex(end)->degree += 1;
#endif
}
//endregion


//region UndirectedGraph
void UndirectedGraph::addEdge(int start, int end) {
    *this->getElement(start - 1, end - 1) = 1;

    if (start != end) {
        *this->getElement(end - 1, start - 1) = 1;
    }

#ifndef SIMPLE_GRAPHS_OPT_COMPUTE_VERTEX_DEGREE
    this->getVertex(start)->degree += 1;
    this->getVertex(end)->degree += 1;
#endif
}
//endregion
