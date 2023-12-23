#include "VectorPlus.h"

VectorPlus::VectorPlus() {
    arr = new int[1];
    capacity = 1;
    current = 0;
}

VectorPlus::~VectorPlus() {
    delete[] arr;
}

void VectorPlus::push_back(int data) {
    if (current == capacity) {
        int* temp = new int[2 * capacity];

        for (int i = 0; i < capacity; i++) {
            temp[i] = arr[i];
        }

        delete[] arr;
        capacity *= 2;
        arr = temp;
    }

    arr[current] = data;
    current++;
}

int VectorPlus::at(int index) {
    if (index < current)
        return arr[index];
    return -1;
}

void VectorPlus::pop_back() {
    current--;
}

int VectorPlus::size() {
    return current;
}

int VectorPlus::get_capacity() {
    return capacity;
}
