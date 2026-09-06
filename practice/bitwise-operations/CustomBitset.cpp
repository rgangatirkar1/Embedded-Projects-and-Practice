#include "CustomBitset.h"
#include <vector>
#include <cmath>

// constructor
CustomBitset::CustomBitset(int size) {
    bitset_size = size;
    my_bitset = std::vector<char>(ceil(size/8));
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
        c |= 1;
    }
}

// Clears every bit
void CustomBitset::clear() {
    for (char &c: my_bitset) {
        c &= 1;
    }
}

// Clears a specific bit
void CustomBitset::clear_bit(int bit_no) {
    int index = bit_no / 8;
    int bit_no_win_char = bit_no % 8;
    my_bitset[index] &= ~(1 << bit_no_win_char);
}

void CustomBitset::set_bit (int bit_no) {
    int index = bit_no/8;
    int bit_no_win_char = bit_no % 8;
    my_bitset[index] |= (1 << bit_no_win_char);

}

int CustomBitset::extract_bit (int bit_no) const {
    int index = bit_no/8;
    int bit_no_win_char = bit_no % 8;  
    return (my_bitset[index] >> bit_no_win_char) & 1;
}

//TODO: implement earliest set bit
int CustomBitset::find_earliest_set(int bit_no) const {
    int index = bit_no;
    int bit_no_win_char = bit_no % 8;
    return 0;
}

int CustomBitset::size() const {
    return bitset_size;
}