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
    delete[] this->vertices;
    delete[] this->adjacencyMatrix;
}

Vertex *AbstractGraph::getVertex(int v) {
    return &this->vertices[this->getVertexIndex(v)];
}

Vertex *AbstractGraph::getVertexAt(int i) {
    return &this->vertices[i];
}

Element *AbstractGraph::getElement(int i, int j) {
    return &this->adjacencyMatrix[j * this->numberOfVertices + i];
}

int AbstractGraph::getVertexIndex(int v) const {
    int index = v - 1;

    if (index < 0 || index >= this->numberOfVertices) {
        throw std::out_of_range("Vertex out of range error");
    }

    return index;
}

int AbstractGraph::getVertexDegreeAt(int i) {
#ifdef SIMPLE_GRAPHS_OPT_COMPUTE_VERTEX_DEGREE
    int result = 0;

    for (int j = 0; j < this->numberOfVertices; ++j) {
        if (this->getElement(i, j)->hasValue()) {
            ++result;
        }
        if (this->getElement(j, i)->hasValue()) {
            ++result;
        }
    }

    return result;
#else
    return this->getVertexAt(i)->degree;
#endif
}

int AbstractGraph::getNumberOfVertices() {
    return this->numberOfVertices;
}

int AbstractGraph::getNumberOfIsolatedVertices() {
    int result = 0;

    for (int i = 0; i < this->numberOfVertices; ++i) {
        if (this->getVertexDegreeAt(i) == 0) {
            result++;
        }
    }

    return result;
}

int AbstractGraph::getVertexDegree(int v) {
    return this->getVertexDegreeAt(this->getVertexIndex(v));
}
//endregion


//region DirectedGraph
void DirectedGraph::addEdge(int start, int end) {
    int startIndex = this->getVertexIndex(start);
    int endIndex = this->getVertexIndex(end);

    *this->getElement(startIndex, endIndex) = 1;

#ifndef SIMPLE_GRAPHS_OPT_COMPUTE_VERTEX_DEGREE
    this->getVertexAt(startIndex)->degree += 1;
    this->getVertexAt(endIndex)->degree += 1;
#endif
}
//endregion


//region UndirectedGraph
void UndirectedGraph::addEdge(int start, int end) {
    int startIndex = this->getVertexIndex(start);
    int endIndex = this->getVertexIndex(end);

    *this->getElement(startIndex, endIndex) = 1;

    if (start != end) {
        *this->getElement(endIndex, startIndex) = 1;
    }

#ifndef SIMPLE_GRAPHS_OPT_COMPUTE_VERTEX_DEGREE
    this->getVertexAt(startIndex)->degree += 1;
    this->getVertexAt(endIndex)->degree += 1;
#endif
}
//endregion
