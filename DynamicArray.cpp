#include "DynamicArray.h"

#include <iostream>
#include <stdexcept>

DynamicArray::DynamicArray(int arraySize) : data(nullptr), size(arraySize) {
    if (arraySize < 0) {
        throw std::invalid_argument("Array size cannot be negative");
    }

    data = new int[arraySize]();
}

DynamicArray::DynamicArray(const DynamicArray& other)
    : data(new int[other.size]), size(other.size) {
    for (int i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

DynamicArray& DynamicArray::operator=(const DynamicArray& other) {
    if (this != &other) {
        int* newData = new int[other.size];
        for (int i = 0; i < other.size; ++i) {
            newData[i] = other.data[i];
        }

        delete[] data;
        data = newData;
        size = other.size;
    }
    return *this;
}

DynamicArray::~DynamicArray() {
    delete[] data;
}

void DynamicArray::validateValue(int value) {
    if (value < -100 || value > 100) {
        throw std::invalid_argument("Value must be between -100 and 100");
    }
}

void DynamicArray::validateIndex(int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index is out of range");
    }
}

int DynamicArray::getSize() const {
    return size;
}

void DynamicArray::set(int index, int value) {
    validateIndex(index);
    validateValue(value);
    data[index] = value;
}

int DynamicArray::get(int index) const {
    validateIndex(index);
    return data[index];
}

void DynamicArray::print() const {
    std::cout << "{";
    for (int i = 0; i < size; ++i) {
        std::cout << data[i];
        if (i + 1 < size) {
            std::cout << ", ";
        }
    }
    std::cout << "}" << std::endl;
}

void DynamicArray::pushBack(int value) {
    validateValue(value);

    int* newData = new int[size + 1];
    for (int i = 0; i < size; ++i) {
        newData[i] = data[i];
    }
    newData[size] = value;

    delete[] data;
    data = newData;
    ++size;
}

void DynamicArray::add(const DynamicArray& other) {
    for (int i = 0; i < size; ++i) {
        const int otherValue = (i < other.size) ? other.data[i] : 0;
        data[i] += otherValue;
    }
}

void DynamicArray::subtract(const DynamicArray& other) {
    for (int i = 0; i < size; ++i) {
        const int otherValue = (i < other.size) ? other.data[i] : 0;
        data[i] -= otherValue;
    }
}
