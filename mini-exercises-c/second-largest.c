#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

// Write a function that returns the second-largest value in an array of ints.
// No sorting allowed — single pass only.
int second_largest(int arr[], int n);

int main() {
    int arr[4] = {15, 9, 1, 2};
    assert(second_largest(arr, 4) == 9);
    printf("All tests passed!\n");
    return 0;
}

int second_largest(int arr[], int n) {
    int largest;
    int second;

    if (arr[0] < arr[1]) {
        largest = arr[1];
        second = arr[0];
    }

    else {
        second = arr[1];
        largest = arr[0];
    }

    for (int i = 2; i < n; i++) {
        if (arr[i] > largest) {
            second = largest;
            largest = arr[i];
        }

        else if (arr[i] > second) {
            second = arr[i];
        }
    }

    return second;
}