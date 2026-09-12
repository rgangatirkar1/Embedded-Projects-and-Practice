#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void swap(int *a, int *b);
void reverse_array(int *arr, int n);

int main() {
    int a = 10;
    int b = 11;
    swap(&a, &b);
    assert(a == 11);
    assert(b == 10);
    printf("Swap test passed!\n");

    int odd_arr[11] = {1,2,3,4,5,6,7,8,9,10,11};
    int even_arr[10] = {1,2,3,4,5,6,7,8,9,10};

    reverse_array(&odd_arr[0], 11);
    for (int i = 0; i < 11; i++) {
        assert(odd_arr[i] == 11-i);
    }

    reverse_array(&even_arr[0], 10);
    for (int i = 0; i < 10; i++) {
        assert(even_arr[i] == 10-i);
    }   

    printf("Array swap passed!\n"); 
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverse_array(int *arr, int n) {
    for (int i = 0; i < n/2; i++) {
        int temp = *(arr + i);
        *(arr + i) = *(arr + n - i - 1);
        *(arr + n - i -1) = temp;  
    }
}

void reverse_array_w_move(int *arr, int n) {
     int *start = arr;
    int *end = arr + n - 1;

    while (start < end) {
        swap(start, end);
        start++;
        end--;
    }
}