#include "options.h"

#ifndef SIMPLE_GRAPHS_VERTEX_H
#define SIMPLE_GRAPHS_VERTEX_H


struct Vertex {
#ifndef SIMPLE_GRAPHS_OPT_COMPUTE_VERTEX_DEGREE
    int degree;
#endif
};


#endif //SIMPLE_GRAPHS_VERTEX_H
