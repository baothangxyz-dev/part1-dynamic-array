#include <iostream>
#include <string>
#include <utility> // std::move
#include "DynamicArray.h"

// Hàm nhận tham số truyền bằng giá trị (Pass by value)
// Khi gọi hàm này, C++ sẽ COPY nếu ta truyền biến thường (lvalue)
// và sẽ MOVE nếu ta dùng std::move (rvalue)
void processArray(DynamicArray<int> arr) {
    std::cout << "  Inside function, array received: " << arr << std::endl;
}

int main() {
    std::cout << "=== 1. DEMO COPY VS MOVE ===\n" << std::endl;

    DynamicArray<int> original(3);
    original[0] = 1; original[1] = 2; original[2] = 3;
    std::cout << "Original array: " << original << std::endl;

    // --- COPY ---
    std::cout << "\n[Copying array...]" << std::endl;
    DynamicArray<int> copied = original; // Copy constructor is called
    std::cout << "Copied array:   " << copied << std::endl;
    std::cout << "Original still has data: " << original << std::endl;

    // --- MOVE ---
    std::cout << "\n[Moving array...]" << std::endl;
    // std::move tells the compiler: "I don't need 'original' anymore, take its resources"
    DynamicArray<int> moved = std::move(original); 
    
    std::cout << "Moved array:    " << moved << std::endl;
    // The original array should now be empty (size 0) because its pointer was stolen!
    std::cout << "Original after move (should be empty): " << original << std::endl;


    std::cout << "\n=== 2. DEMO PASS BY VALUE ===\n" << std::endl;
    
    DynamicArray<int> arrForCopy(2);
    arrForCopy[0] = 10; arrForCopy[1] = 20;
    
    std::cout << "Passing by COPY:" << std::endl;
    processArray(arrForCopy); // Copies data
    
    std::cout << "\nPassing by MOVE:" << std::endl;
    processArray(std::move(arrForCopy)); // Moves data, no copy made

    std::cout << "\n=== DONE ===" << std::endl;
    return 0;
}