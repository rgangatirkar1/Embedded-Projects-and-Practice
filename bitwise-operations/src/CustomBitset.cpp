#include "CustomBitset.h"
#include <vector>
#include <cmath>
#include <iostream>

// constructor
CustomBitset::CustomBitset(int size) {
    bitset_size = size;
    my_bitset = std::vector<char>((size+7/8), 0);
}

// Flips all the bits (0 -> 1, 1 -> 0)
void CustomBitset::flip(){
    for (char &c: my_bitset) {
        c = ~c;
    }
}

// Sets each bit to 1
void CustomBitset::set() {
    for (char &c: my_bitset) {
        c |= 0b11111111;
    }
}

// Clears every bit
void CustomBitset::clear() {
    for (char &c: my_bitset) {
        c &= 0;
    }
}

// Clears a specific bit
void CustomBitset::clear_bit(int bit_no) {
    check_valid_bit_index(bit_no, bitset_size);
    int index = bit_no / 8;
    int bit_no_win_char = bit_no % 8;
    my_bitset[index] &= ~(1 << bit_no_win_char);
}

void CustomBitset::set_bit (int bit_no) {
    check_valid_bit_index(bit_no, bitset_size);
    int index = bit_no/8;
    int bit_no_win_char = bit_no % 8;
    my_bitset[index] |= (1 << bit_no_win_char);

}

int CustomBitset::extract_bit (int bit_no) const {
    check_valid_bit_index(bit_no, bitset_size);
    int index = bit_no/8;
    int bit_no_win_char = bit_no % 8;  
    return (my_bitset[index] >> bit_no_win_char) & 1;
}

//TODO: implement earliest set bit
int CustomBitset::find_earliest_set(int bit_no) const {
    check_valid_bit_index(bit_no, bitset_size);
    int index = bit_no;
    int bit_no_win_char = bit_no % 8;
    if (bit_no_win_char < 7) {
        for (int i = bit_no_win_char; i <= 7; i++) {
            
        }
    }
    return 0;
}

int CustomBitset::size() const {
    return bitset_size;
}

void check_valid_bit_index(int bit_no, int bitset_size) {
    if (bit_no >= bitset_size) {
        throw std::out_of_range("Invalid bit number!");
    }
}

// Iterator functions 
CustomBitset::iterator CustomBitset::begin() {
    return my_bitset.begin();
}

CustomBitset::iterator CustomBitset::end() {
    return my_bitset.end();
}

CustomBitset::const_iterator CustomBitset::begin() const {
    return my_bitset.begin();
}

CustomBitset::const_iterator CustomBitset::end() const {
    return my_bitset.end();
}