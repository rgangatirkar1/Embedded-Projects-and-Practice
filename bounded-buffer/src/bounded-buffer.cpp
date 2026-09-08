#include "bounded-buffer.h"
#include <vector>
#include <semaphore>


template <typename T>
T BoundedBuffer<T>::pop() {
    
    //Check if the buffer has objects, waits if it's empty
    slots_full.acquire();

    //lock the buffer to prevent anything else from reading/writing, otherwise there could be race condtions
    mtx.lock();
    T val =  buffer[read_index];
    read_index = (read_index + 1) % size;

    //unlock the mutex and increase the number of empty slots, potentially allowing the producer to write
    mtx.unlock();
    slots_empty.release();

    return val    
}

template <typename T>
void BoundedBuffer<T>::put(T value) {
    //Check if the buffer has space, otherwise wait
    slots_empty.acquire();

    //lock the buffer to prevent anything else from reading/writing, otherwise there could be race condtions
    mtx.lock();
    buffer[write_index] = value;
    write_index = (write_index + 1) % size;

    //unlock the mutex and increase the number of empty slots, potentially allowing a consumer to read
    mtx.unlock();
    slots_full.release();
}


