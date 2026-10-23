#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <iostream>
#include <stdexcept>
#include <type_traits>
#include <typeinfo>
#include <cmath>

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
    explicit DynamicArray(int arraySize = 0) : data(nullptr), size(arraySize) {
        if (arraySize < 0) {
            throw std::invalid_argument("Array size cannot be negative");
        }
        data = new T[arraySize]();
    }

    DynamicArray(const DynamicArray& other) : data(new T[other.size]), size(other.size) {
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    DynamicArray& operator=(const DynamicArray& other) {
        if (this != &other) {
            T* newData = new T[other.size];
            for (int i = 0; i < other.size; ++i) {
                newData[i] = other.data[i];
            }
            delete[] data;
            data = newData;
            size = other.size;
        }
        return *this;
    }

    ~DynamicArray() {
        delete[] data;
    }

    int getSize() const {
        return size;
    }

    void set(int index, T value) {
        validateIndex(index);
        validateValue(value);
        data[index] = value;
    }

    T get(int index) const {
        validateIndex(index);
        return data[index];
    }

    void print() const {
        std::cout << "{";
        for (int i = 0; i < size; ++i) {
            std::cout << data[i];
            if (i + 1 < size) {
                std::cout << ", ";
            }
        }
        std::cout << "}" << std::endl;
    }

    void pushBack(T value) {
        validateValue(value);
        T* newData = new T[size + 1];
        for (int i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        newData[size] = value;
        delete[] data;
        data = newData;
        ++size;
    }

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