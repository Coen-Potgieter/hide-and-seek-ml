

#include "../include/helper_funcs.h"

#include <iostream>

void printMartix(const std::vector<std::vector<float>>& inpMatrix) {
    for (size_t rowIdx = 0; rowIdx < inpMatrix.size(); rowIdx++) {
        size_t numElems = inpMatrix[rowIdx].size();
        for (size_t elemIdx = 0; elemIdx < numElems; elemIdx++) {
            std::cout << inpMatrix[rowIdx][elemIdx];
            if (elemIdx != numElems - 1) std::cout << ',';
            std::cout << ' ';
        }
        std::cout << '\n';
    }
    return;
}
