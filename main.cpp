#include <iostream>
#include <string>
#include "DynamicArray.h"

int main() {
    std::cout << "=== 1. OPERATOR [] ===" << std::endl;
    DynamicArray<int> arr1(3);
    arr1[0] = 10; // Using operator[] as setter
    arr1[1] = 20;
    arr1[2] = 30;
    std::cout << "arr1: " << arr1 << std::endl;
    std::cout << "arr1[1] = " << arr1[1] << std::endl; // Using operator[] as getter

    try {
        arr1[5] = 100; // Out of bounds
    } catch (const std::out_of_range& e) {
        std::cerr << "Caught out_of_range: " << e.what() << std::endl;
    }

    std::cout << "\n=== 2. COMPARISON OPERATORS ===" << std::endl;
    DynamicArray<int> arr2(3);
    arr2[0] = 10; arr2[1] = 20; arr2[2] = 30;
    DynamicArray<int> arr3(3);
    arr3[0] = 10; arr3[1] = 20; arr3[2] = 99;

    std::cout << "arr1 == arr2: " << (arr1 == arr2 ? "true" : "false") << std::endl;
    std::cout << "arr1 != arr3: " << (arr1 != arr3 ? "true" : "false") << std::endl;

    std::cout << "\n=== 3. ARITHMETIC OPERATORS ===" << std::endl;
    DynamicArray<int> arr4(3);
    arr4[0] = 1; arr4[1] = 2; arr4[2] = 3;
    DynamicArray<int> arr5(2); // Different size to test padding with zeros
    arr5[0] = 10; arr5[1] = 20;

    std::cout << "Before +=: arr4 = " << arr4 << std::endl;
    arr4 += arr5;
    std::cout << "After +=: arr4 = " << arr4 << std::endl; // 1+10, 2+20, 3+0

    arr4 += 5; // Scalar addition
    std::cout << "After + 5 (scalar): arr4 = " << arr4 << std::endl;
    
    arr4 -= 10; // Scalar subtraction
    std::cout << "After - 10 (scalar): arr4 = " << arr4 << std::endl;

    std::cout << "\n=== 4. ITERATORS (RANGE-BASED FOR) ===" << std::endl;
    std::cout << "Iterating over arr1: ";
    for (const auto& x : arr1) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    // Modifying elements through iterator (non-const)
    std::cout << "Doubling elements of arr1...\n";
    for (auto& x : arr1) {
        x *= 2;
    }
    std::cout << "arr1 after modification: " << arr1 << std::endl;

    return 0;
}