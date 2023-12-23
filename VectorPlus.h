#ifndef VECTORPLUS_H
#define VECTORPLUS_H

#include <iostream>
#include <algorithm>

class VectorPlus {
private:
    int* arr;
    int capacity;
    int current;

public:
    VectorPlus();
    ~VectorPlus();
    void push_back(int data);
    int at(int index);
    void pop_back();
    int size();
    int get_capacity();
};

#endif // VECTORPLUS_H
