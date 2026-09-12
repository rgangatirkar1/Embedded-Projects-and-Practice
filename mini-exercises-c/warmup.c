#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

double average(int a, int b) {
    return ((a+b) / 2.0);
}

int sum_of_digits(int n) {
    
}

void reverse_string(char *s) {
    int length = strlen(s);
    int count = 0;
    while (count < length/2) {
        char temp = *(s+count);
        *(s + count) = *(s + length - count - 1);
        *(s + length - count - 1) = temp;
        count++;
    }
}

int max_profit(int prices[], int n) {
    int curr_min = prices[0];
    int curr_max_profit = 0;
    for (int i = 1; i < n; i++) {
        if (prices[i] < curr_min) {
            curr_min = prices[i];
        }
        if ((prices[i] - curr_min) > curr_max_profit) {
            curr_max_profit = prices[i] - curr_min;
        }
    }

    return curr_max_profit;
}