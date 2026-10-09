#include "DynamicArray.h"
#include <iostream>
using namespace std;

DynamicArray::DynamicArray(int size) {
    if (size < 0) size = 0;
    this->size = size;
    this->data = new int[size];
    for (int i = 0; i < size; ++i) data[i] = 0;
}

DynamicArray::DynamicArray(const DynamicArray& other) {
    this->size = other.size;
    this->data = new int[other.size];
    for (int i = 0; i < other.size; ++i) data[i] = other.data[i];
}

DynamicArray& DynamicArray::operator=(const DynamicArray& other) {
    if (this != &other) {
        int* newData = new int[other.size];
        for (int i = 0; i < other.size; ++i) newData[i] = other.data[i];

        delete[] data;
        data = newData;
        size = other.size;
    }
    return *this;
}

DynamicArray::~DynamicArray() {
    delete[] data;
    data = nullptr;
}

void DynamicArray::print() const {
    cout << "{ ";
    for (int i = 0; i < size; ++i) {
        cout << data[i];
        if (i < size - 1) cout << ", ";
    }
    cout << " }" << endl;
}

void DynamicArray::set(int index, int value) {
    if (index < 0 || index >= size) {
        cout << "Loi: index " << index << " vuot bien\n";
        return;
    }
    if (value < -100 || value > 100) {
        cout << "Loi: gia tri " << value << " ngoai [-100,100]\n";
        return;
    }
    data[index] = value;
}

int DynamicArray::get(int index) const {
    if (index < 0 || index >= size) {
        cout << "Loi: index " << index << " vuot bien\n";
        return 0;
    }
    return data[index];
}

void DynamicArray::append(int value) {
    if (value < -100 || value > 100) {
        cout << "Loi: gia tri " << value << " ngoai [-100,100]\n";
        return;
    }
    int* newData = new int[size + 1];
    for (int i = 0; i < size; ++i) newData[i] = data[i];
    newData[size] = value;
    delete[] data;
    data = newData;
    size = size + 1;
}

void DynamicArray::add(const DynamicArray& other) {
    int m = (size < other.size) ? size : other.size;
    for (int i = 0; i < m; ++i) data[i] += other.data[i];
}

void DynamicArray::subtract(const DynamicArray& other) {
    int m = (size < other.size) ? size : other.size;
    for (int i = 0; i < m; ++i) data[i] -= other.data[i];
}