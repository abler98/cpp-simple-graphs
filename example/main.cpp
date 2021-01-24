#include <iostream>
#include <stdexcept>
#include <string>
#include <cstdlib>
#include <climits>
#include <cerrno>

#include "example_options.h"
#include "example_utils.h"
#include "directed_graph_example.h"
#include "undirected_graph_example.h"

static void read_options(example_options &options, int argc, char *argv[]);
static void read_benchmark_options(example_options &options, int argc, char *argv[]);
static void read_int_argument(int &dest, char *arg);

int main(int argc, char *argv[]) {
    example_options options{};

    try {
        read_options(options, argc, argv);
    } catch (const std::exception &e) {
        std::cerr << "Read options error: " << e.what() << std::endl;
        return 1;
    }

    example_utils::run_example("DIRECTED GRAPH", options, directed_graph_example::run);
    example_utils::run_example("UNDIRECTED GRAPH", options, undirected_graph_example::run);

    return 0;
}

static void read_options(example_options &options, int argc, char *argv[]) {
    if (argc <= 1) {
        return;
    }

    if (std::string(argv[1]) == "benchmark") {
        read_benchmark_options(options, argc, argv);
    } else {
        throw std::invalid_argument("Invalid usage");
    }
}

static void read_benchmark_options(example_options &options, int argc, char *argv[]) {
    options.benchmark_mode = true;

    switch (argc) {
        case 2:
            // Default number of iterations
            options.benchmark_iters = SIMPLE_GRAPHS_EXAMPLE_DEFAULT_BENCHMARK_ITERS;
            break;
        case 3:
            read_int_argument(options.benchmark_iters, argv[2]);
            break;
        default:
            throw std::invalid_argument("Invalid benchmark mode arguments");
    }
}

static void read_int_argument(int &dest, char *arg) {
    char *endptr;
    errno = 0;

    long val = std::strtol(arg, &endptr, 10);

    if (*endptr != '\0' || errno != 0 || val < INT_MIN || val > INT_MAX) {
        throw std::invalid_argument("Invalid program argument");
    }

    dest = (int) val;
}
