#include <string>
#include "ExampleUtils.h"

std::string ExampleUtils::intVectorToString(std::vector<int> vector) {
    std::string result;

    for (size_t i = 0; i < vector.size(); ++i) {
        if (i > 0) {
            result += ", ";
        }

        result += std::to_string(vector[i]);
    }

    return result;
}
