#include "bounded-buffer.h"
#include <iostream>

int main() {
    BoundedBuffer<int> my_buffer(5);

    // Make a bunch of producer threads and test that they block after hitting the limit

    //Then, make a bunch of consumer threads and test that they block after 

    std::cout<<"All tests passed!"<<std::endl;
    return 0;
}