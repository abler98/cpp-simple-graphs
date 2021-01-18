#include <string>
#include <vector>
#include <iostream>

#include "example_options.h"
#include "../lib/Matrix.h"

#ifndef SIMPLE_GRAPHS_EXAMPLEUTILS_H
#define SIMPLE_GRAPHS_EXAMPLEUTILS_H


namespace example_utils {
    void run_example(const std::string &label, example_options &options, void (*runnable)(std::ostream &));
    std::string int_vector_to_string(std::vector<int> *vector);
    void print_matrix(Matrix *matrix, std::ostream &out);
}


#endif //SIMPLE_GRAPHS_EXAMPLEUTILS_H
