#include <string>
#include <stdexcept>
#include "graphs/options.h"
#include "graphs/Graph.h"

static inline std::string vertex_labeler(int i) {
    return "V" + std::to_string(i + 1);
}

static inline std::string edge_labeler(int i) {
    return "E" + std::to_string(i + 1);
}

//region AbstractGraph
AbstractGraph::AbstractGraph(int numberOfVertices) {
    this->numberOfVertices = numberOfVertices;
    this->vertices = new Vertex[numberOfVertices]();
    this->adjacencyMatrix = new Element[numberOfVertices * numberOfVertices]();
}

AbstractGraph::~AbstractGraph() {
    delete[] this->vertices;
    delete[] this->adjacencyMatrix;
}

[[maybe_unused]] inline Vertex *AbstractGraph::getVertex(int v) {
    return &this->vertices[this->getVertexIndex(v)];
}

inline Vertex *AbstractGraph::getVertexAt(int i) {
    return &this->vertices[i];
}

inline Element *AbstractGraph::getElement(int i, int j) {
    return &this->adjacencyMatrix[j * this->numberOfVertices + i];
}

inline int AbstractGraph::getVertexIndex(int v) const {
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
            if (i == j) {
                result += 2;
                continue;
            } else {
                ++result;
            }
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

std::vector<int> *AbstractGraph::depthFirstSearch(int v) {
    bool *visited = new bool[this->numberOfVertices]();
    auto result = this->depthFirstSearchInternal(this->getVertexIndex(v), visited);
    delete[] visited;

    return result;
}

std::vector<int> *AbstractGraph::depthFirstSearchInternal(int i, bool *visited) {
    visited[i] = true;

    auto result = new std::vector<int>();
    result->push_back(i + 1);

    for (int j = 0; j < this->numberOfVertices; ++j) {
        if (visited[j]) {
            continue;
        }
        if (this->getElement(i, j)->hasValue()) {
            auto nestedResult = this->depthFirstSearchInternal(j, visited);
            for (int &vertex : *nestedResult) {
                result->push_back(vertex);
            }
            delete nestedResult;
        }
    }

    return result;
}

Matrix *AbstractGraph::createAdjacencyMatrix() {
    auto matrix = new Matrix(this->numberOfVertices, this->numberOfVertices, vertex_labeler, vertex_labeler);

    for (int i = 0; i < this->numberOfVertices; ++i) {
        for (int j = 0; j < this->numberOfVertices; ++j) {
            *(*matrix)[i][j] = this->getElement(i, j)->getValue();
        }
    }

    return matrix;
}
//endregion


//region DirectedGraph
void DirectedGraph::addEdge(int start, int end) {
    int startIndex = this->getVertexIndex(start);
    int endIndex = this->getVertexIndex(end);
    auto element = this->getElement(startIndex, endIndex);

    if (element->hasValue()) {
        return;
    }

    *element = 1;

#ifndef SIMPLE_GRAPHS_OPT_COMPUTE_VERTEX_DEGREE
    this->getVertexAt(startIndex)->degree += 1;
    this->getVertexAt(endIndex)->degree += 1;
#endif

#ifndef SIMPLE_GRAPHS_OPT_COMPUTE_NUMBER_OF_EDGES
    ++this->numberOfEdges;
#endif
}

int DirectedGraph::getNumberOfEdges() {
#ifdef SIMPLE_GRAPHS_OPT_COMPUTE_NUMBER_OF_EDGES
    int result = 0;

    for (int i = 0; i < this->getNumberOfVertices(); ++i) {
        for (int j = 0; j < this->getNumberOfVertices(); ++j) {
            if (this->getElement(i, j)->hasValue()) {
                ++result;
            }
        }
    }

    return result;
#else
    return this->numberOfEdges;
#endif
}

Matrix *DirectedGraph::createIncidenceMatrix() {
    int numberOfVertices = this->getNumberOfVertices();
    int numberOfEdges = this->getNumberOfEdges();

    auto matrix = new Matrix(numberOfVertices, numberOfEdges, vertex_labeler, edge_labeler);

    int e = 0;

    for (int i = 0; i < numberOfVertices; ++i) {
        for (int j = 0; j < numberOfVertices; ++j) {
            if (this->getElement(i, j)->hasValue()) {
                if (i == j) {
                    *(*matrix)[i][e] = 1;
                } else {
                    *(*matrix)[i][e] = 1;
                    *(*matrix)[j][e] = -1;
                }
                ++e;
            }
        }
    }

    return matrix;
}
//endregion


//region UndirectedGraph
void UndirectedGraph::addEdge(int start, int end) {
    int startIndex = this->getVertexIndex(start);
    int endIndex = this->getVertexIndex(end);
    auto element = this->getElement(startIndex, endIndex);

    if (element->hasValue()) {
        return;
    }

    *element = 1;

    if (start != end) {
        *this->getElement(endIndex, startIndex) = 1;
    }

#ifndef SIMPLE_GRAPHS_OPT_COMPUTE_VERTEX_DEGREE
    this->getVertexAt(startIndex)->degree += 1;
    this->getVertexAt(endIndex)->degree += 1;
#endif

#ifndef SIMPLE_GRAPHS_OPT_COMPUTE_NUMBER_OF_EDGES
    ++this->numberOfEdges;
#endif
}

int UndirectedGraph::getNumberOfEdges() {
#ifdef SIMPLE_GRAPHS_OPT_COMPUTE_NUMBER_OF_EDGES
    int result = 0;

    for (int i = 0; i < this->getNumberOfVertices(); ++i) {
        for (int j = i; j < this->getNumberOfVertices(); ++j) {
            if (this->getElement(i, j)->hasValue()) {
                ++result;
            }
        }
    }

    return result;
#else
    return this->numberOfEdges;
#endif
}

Matrix *UndirectedGraph::createIncidenceMatrix() {
    int numberOfVertices = this->getNumberOfVertices();
    int numberOfEdges = this->getNumberOfEdges();

    auto matrix = new Matrix(numberOfVertices, numberOfEdges, vertex_labeler, edge_labeler);

    int e = 0;

    for (int i = 0; i < numberOfVertices; ++i) {
        for (int j = i; j < numberOfVertices; ++j) {
            if (this->getElement(i, j)->hasValue()) {
                if (i == j) {
                    *(*matrix)[i][e] = 1;
                } else {
                    *(*matrix)[i][e] = 1;
                    *(*matrix)[j][e] = 1;
                }
                ++e;
            }
        }
    }

    return matrix;
}
//endregion
