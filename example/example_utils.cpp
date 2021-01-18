#include <string>
#include <iostream>
#include <ctime>
#include <iomanip>
#include "example_utils.h"

class NullBuffer : public std::streambuf {
public:
    int overflow(int c) override {
        return c;
    }
};

void example_utils::run_example(const std::string &label, example_options &options, void (*runnable)(std::ostream &)) {
    if (!options.benchmark_mode) {
        (*runnable)(std::cout);
        return;
    }

    NullBuffer null_buffer;
    std::ostream null_stream(&null_buffer);

    std::clock_t start_time = std::clock();

    std::cout << ">>> " << label << " EXAMPLE BENCHMARK: " << options.benchmark_iters << " iterations..."
              << std::endl;

    for (int i = 0; i < options.benchmark_iters; ++i) {
        (*runnable)(null_stream);
    }

    double elapsed_time = double(std::clock() - start_time) / CLOCKS_PER_SEC;

    std::cout << "<<< " << label << " EXAMPLE BENCHMARK: " << elapsed_time << " sec\n" << std::endl;
}

// TODO: Make universal helper for any type (using templates)
std::string example_utils::int_vector_to_string(std::vector<int> *vector) {
    std::string result;

    for (size_t i = 0; i < vector->size(); ++i) {
        if (i > 0) {
            result += ", ";
        }

        result += std::to_string(vector->at(i));
    }

    return result;
}

void example_utils::print_matrix(Matrix *matrix, std::ostream &out) {
    out << "   ";

    for (int i = 0; i < matrix->getNumberOfColumns(); ++i) {
        out << std::setw(4) << matrix->getColumnLabel(i);
    }

    out << '\n';

    for (int i = 0; i < matrix->getNumberOfRows(); ++i) {
        out << std::setw(3) << matrix->getRowLabel(i);
        for (int j = 0; j < matrix->getNumberOfColumns(); ++j) {
            out << std::setw(4) << *(*matrix)[i][j];
        }
        out << '\n';
    }

    out.flush();
}
