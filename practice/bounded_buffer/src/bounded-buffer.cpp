#include "bounded-buffer.h"
#include <vector>

template <typename T>
BoundedBuffer<T>::BoundedBuffer(int size) {
    buffer = vector<T>(size);
    this -> size = size;
}

template <typename T>
T BoundedBuffer<T>::pop() {
    //TODO: implement logic
}

template <typename T>
void BoundedBuffer<T>::put(T value) {
    //TODO: implement logic
}


