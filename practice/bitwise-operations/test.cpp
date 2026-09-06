#include "CustomBitset.h"
#include <cassert>
#include <iostream>

// Declare helper functions
void check_set(CustomBitset& bitset);
void check_unset(CustomBitset& bitset);
void check_size(CustomBitset& bitset);
void check_bits(CustomBitset& bitset, bool bit, int value);

int main() {
    
    //Initialize bitset
    CustomBitset test_bitset(64);
    
    // Set all the bits
    test_bitset.set();
    check_set(test_bitset);

    // Clear all the bits
    test_bitset.clear();
    check_unset(test_bitset);

    // Get the size
    check_size(test_bitset);

    // Set a bunch of bits, then extract them
    for (int i = 0; i < 64; i++) {
        if (i % 3 == 0) {
            test_bitset.set_bit(i);
        }
    }
    check_bits(test_bitset, 1, 3);
    
    // Clear some bits, then extract and check
    for (int i = 0; i < 64; i++) {
        if (i % 3 == 0) {
            test_bitset.clear_bit(i);
        }
    }

    check_bits(test_bitset, 0, 3);


    // Setting some bits, then flipping the entire bitset and checking if it was flipped properly
    CustomBitset original_bitset = test_bitset;
    for (int i = 0; i < 64; i++) {
        if (i % 2 == 0) {
            test_bitset.set_bit(i);
        }
    }
    
    test_bitset.flip();

    //TODO: test flipping functionality

    std::cout<< "All tests passed!" <<std::endl;
    return 0;
}

void check_set(CustomBitset &test_bitset) {
    unsigned char mask = 0b11111111;
    for (char c: test_bitset) {
        assert((mask & c) == mask);
    }
}

void check_unset(CustomBitset &test_bitset) {
    for (char c: test_bitset) {
        assert(c == 0);
    }
}

void check_size(CustomBitset &test_bitset) {
    assert(test_bitset.size() == 64);
}

void check_bits(CustomBitset &test_bitset, bool bit, int value) {
    // Set some bits, then extract them
    for (int i = 0; i < 64; i++) {
        if (i % value == 0) {
            assert(test_bitset.extract_bit(i) == bit);
        }
    }
}