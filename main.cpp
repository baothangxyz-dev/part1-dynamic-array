
#include <iostream>
#include <stdexcept>
#include <new>
#include <limits>
#include "DynamicArray.h"

int main() {
    DynamicArray arr(3);

    arr.set(0, 10);
    arr.set(1, 20);
    arr.set(2, 30);

    std::cout << "=== 1. out_of_range ===" << std::endl;
    arr.print();

    try {
        arr.get(5);
    } catch (const std::out_of_range& e) {
        std::cout << "Caught out_of_range: "
                  << e.what() << std::endl;
    }

    std::cout << "\n=== 2. invalid_argument ===" << std::endl;

    try {
        arr.set(0, 150);
    } catch (const std::invalid_argument& e) {
        std::cout << "Caught invalid_argument: "
                  << e.what() << std::endl;
    }

    try {
        arr.pushBack(-150);
    } catch (const std::invalid_argument& e) {
        std::cout << "Caught invalid_argument: "
                  << e.what() << std::endl;
    }

    std::cout << "\n=== 3. bad_alloc ===" << std::endl;

    try {
        volatile std::size_t count =
            std::numeric_limits<std::size_t>::max();

        int* memory = new int[count];
        delete[] memory;
        std::cout << "Allocation succeeded on this system."
                  << std::endl;
    } catch (const std::bad_alloc& e) {
        std::cout << "Caught bad_alloc: "
                  << e.what() << std::endl;
    }

    std::cout << "\n=== Array still works ===" << std::endl;
    arr.print();

    return 0;
}
