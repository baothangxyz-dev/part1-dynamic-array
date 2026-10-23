#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <iostream>
#include <stdexcept>
#include <type_traits>
#include <typeinfo>
#include <cmath>
#include <utility> // Cần cho std::move

template <typename T>
class DynamicArray {
private:
    T* data;
    int size;

    void validateValue(T value) {
        if constexpr (std::is_integral_v<T>) {
            if (static_cast<int>(value) < -100 || static_cast<int>(value) > 100) {
                throw std::invalid_argument("Value must be between -100 and 100");
            }
        }
    }

    void validateIndex(int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index is out of range");
        }
    }

public:
    // 1. Default Constructor
    explicit DynamicArray(int arraySize = 0) : data(nullptr), size(arraySize) {
        if (arraySize < 0) {
            throw std::invalid_argument("Array size cannot be negative");
        }
        data = new T[arraySize]();
    }

    // 2. Destructor
    ~DynamicArray() {
        delete[] data;
    }

    // 3. Copy Constructor (Phần 1)
    DynamicArray(const DynamicArray& other) : data(new T[other.size]), size(other.size) {
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    // 4. Copy Assignment Operator (Zadanie 1 - Đã tối ưu)
    DynamicArray& operator=(const DynamicArray& other) {
        if (this != &other) { // Protect against self-assignment
            T* newData = new T[other.size]; // Allocate new memory FIRST
            for (int i = 0; i < other.size; ++i) {
                newData[i] = other.data[i];
            }
            delete[] data; // Free old memory
            data = newData; // Steal new pointer
            size = other.size;
        }
        return *this;
    }

    // 5. Move Constructor (Zadanie 2)
    DynamicArray(DynamicArray&& other) noexcept 
        : data(other.data), size(other.size) {
        // Steal the pointer and reset the source
        other.data = nullptr;
        other.size = 0;
    }

    // 6. Move Assignment Operator (Zadanie 3)
    DynamicArray& operator=(DynamicArray&& other) noexcept {
        if (this != &other) { // Protect against self-assignment
            delete[] data; // Free own data first
            
            // Steal resources
            data = other.data;
            size = other.size;

            // Reset source
            other.data = nullptr;
            other.size = 0;
        }
        return *this;
    }

    // --- Các hàm cũ giữ nguyên ---
    int getSize() const { return size; }

    void set(int index, T value) {
        validateIndex(index);
        validateValue(value);
        data[index] = value;
    }

    T get(int index) const {
        validateIndex(index);
        return data[index];
    }

    void pushBack(T value) {
        validateValue(value);
        T* newData = new T[size + 1];
        for (int i = 0; i < size; ++i) newData[i] = data[i];
        newData[size] = value;
        delete[] data;
        data = newData;
        ++size;
    }

    // --- ZADANIE 1: Operator [] ---
    T& operator[](int index) {
        validateIndex(index);
        return data[index];
    }
    const T& operator[](int index) const {
        validateIndex(index);
        return data[index];
    }

    // --- ZADANIE 2: Comparison Operators ---
    bool operator==(const DynamicArray& other) const {
        if (size != other.size) return false;
        for (int i = 0; i < size; ++i) {
            if (data[i] != other.data[i]) return false;
        }
        return true;
    }
    bool operator!=(const DynamicArray& other) const {
        return !(*this == other);
    }

    // --- ZADANIE 3: Arithmetic Operators ---
    DynamicArray& operator+=(const DynamicArray& other) {
        for (int i = 0; i < size; ++i) {
            T otherValue = (i < other.size) ? other.data[i] : T(0);
            validateValue(data[i] + otherValue);
            data[i] += otherValue;
        }
        return *this;
    }
    DynamicArray& operator-=(const DynamicArray& other) {
        for (int i = 0; i < size; ++i) {
            T otherValue = (i < other.size) ? other.data[i] : T(0);
            validateValue(data[i] - otherValue);
            data[i] -= otherValue;
        }
        return *this;
    }
    DynamicArray& operator+=(T scalar) {
        if constexpr (!std::is_arithmetic_v<T>) throw std::bad_typeid();
        for (int i = 0; i < size; ++i) {
            validateValue(data[i] + scalar);
            data[i] += scalar;
        }
        return *this;
    }
    DynamicArray& operator-=(T scalar) {
        if constexpr (!std::is_arithmetic_v<T>) throw std::bad_typeid();
        for (int i = 0; i < size; ++i) {
            validateValue(data[i] - scalar);
            data[i] -= scalar;
        }
        return *this;
    }

    // --- ZADANIE 4: Iterators ---
    T* begin() { return data; }
    const T* begin() const { return data; }
    T* end() { return data + size; }
    const T* end() const { return data + size; }

    friend std::ostream& operator<<(std::ostream& os, const DynamicArray<T>& arr) {
        os << "{";
        for (int i = 0; i < arr.size; ++i) {
            os << arr.data[i];
            if (i + 1 < arr.size) os << ", ";
        }
        os << "}";
        return os;
    }
};

template <typename T>
double calculateDistance(const DynamicArray<T>& a, const DynamicArray<T>& b) {
    if (a.getSize() != b.getSize()) {
        throw std::invalid_argument("Arrays must have the same size");
    }
    if constexpr (!std::is_arithmetic_v<T>) {
        throw std::bad_typeid();
    } else {
        double sum = 0.0;
        for (int i = 0; i < a.getSize(); ++i) {
            double diff = static_cast<double>(a.get(i)) - static_cast<double>(b.get(i));
            sum += diff * diff;
        }
        return std::sqrt(sum);
    }
}

#endif