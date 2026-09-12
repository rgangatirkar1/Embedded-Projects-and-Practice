#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

int get_bit(int number, int bit_number);

int main() {
    int test = 0xFFFF; // this is two bytes, meaning first 16 bits will all be one, last 16 bits will all be zero
    for (int i = 0; i < 16; i++) {
        assert(get_bit(test, i) == 1);
    }

    for (int i = 16; i < 32; i++) {
        assert(get_bit(test, i) == 0);    
    }

    printf("Getting bit test passed!\n");
    return 0;
}

int get_bit(int number, int bit_number) {

    if (bit_number < 0 || bit_number >= 32) {
        printf("Invalid bit number provided!\n");
        return -1;
    }

    //isolate the byte first
    int byte_number = bit_number / 8;
    int bit_no_in_byte = bit_number % 8;
    char *first_byte = (char *) &number;
    char *actual_byte = first_byte + byte_number;
    return (*actual_byte >> bit_no_in_byte) & 1;
}

void split_int(uint16_t int_to_split) {
    char *start = (char *) &int_to_split;
    char *end = (char *)(start + 1);
}