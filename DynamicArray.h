#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

class DynamicArray {
private:
    int* data;
    int size;

    static void validateValue(int value);
    void validateIndex(int index) const;

public:
    explicit DynamicArray(int arraySize = 0);
    DynamicArray(const DynamicArray& other);
    DynamicArray& operator=(const DynamicArray& other);
    ~DynamicArray();

    int getSize() const;
    void set(int index, int value);
    int get(int index) const;
    void print() const;
    void pushBack(int value);
    void add(const DynamicArray& other);
    void subtract(const DynamicArray& other);
};

#endif
