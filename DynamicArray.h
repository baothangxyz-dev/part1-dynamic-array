#pragma once
#include <iostream>

class DynamicArray {
private:
    int* data;
    int size;

public:
    DynamicArray(int size = 0);
    ~DynamicArray();
    void print() const;
    void set(int index, int value);
    int  get(int index) const;

    DynamicArray(const DynamicArray& other);
    DynamicArray& operator=(const DynamicArray& other);
    void append(int value);
    void add(const DynamicArray& other);
    void subtract(const DynamicArray& other);

    int getSize() const { return size; }
};