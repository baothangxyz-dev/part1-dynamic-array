#include <iostream>
#include <string>
#include "DynamicArray.h"

int main() {
    std::cout << "=== 1. DEMO WITH INTEGERS ===" << std::endl;

    DynamicArray<int> arr1(2);
    arr1.set(0, 10);
    arr1.set(1, 20);

    DynamicArray<int> arr2(2);
    arr2.set(0, 15);
    arr2.set(1, 25);

    std::cout << "Array 1: " << arr1 << std::endl;
    std::cout << "Array 2: " << arr2 << std::endl;

    try {
        double dist = calculateDistance(arr1, arr2);
        std::cout << "Distance: " << dist << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        std::cout << "\nAttempting to set value 150 (invalid)..." << std::endl;
        arr1.set(0, 150);
    } catch (const std::invalid_argument& e) {
        std::cerr << "Caught invalid_argument: " << e.what() << std::endl;
    }

    std::cout << "\n=== 2. DEMO WITH STRINGS ===" << std::endl;

    DynamicArray<std::string> strArr1(1);
    DynamicArray<std::string> strArr2(1);

    strArr1.set(0, "Hello");
    strArr2.set(0, "World");

    std::cout << "String Array 1: " << strArr1 << std::endl;
    std::cout << "String Array 2: " << strArr2 << std::endl;

    try {
        std::cout << "Attempting to calculate distance with strings..." << std::endl;
        double dist = calculateDistance(strArr1, strArr2);
    } catch (const std::bad_typeid& e) {
        std::cerr << "Caught bad_typeid: Cannot calculate distance for non-numeric types!" << std::endl;
    }

    std::cout << "\n=== 3. DEMO WITH DIFFERENT SIZES ===" << std::endl;

    DynamicArray<int> arr3(3);
    try {
        std::cout << "Attempting to calculate distance with different sizes..." << std::endl;
        calculateDistance(arr1, arr3);
    } catch (const std::invalid_argument& e) {
        std::cerr << "Caught invalid_argument: " << e.what() << std::endl;
    }

    std::cout << "\n=== DONE ===" << std::endl;
    return 0;
}