#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

void reverse(char *s);

int main() {
    char string[6]= "Hello";
    reverse(string);
    assert(strcmp(string, "olleH") == 0);
    char new_string[5] = "abcd";
    reverse(new_string);
    assert(strcmp(new_string, "dcba") == 0);
    printf("All tests passed!\n");
    return 0;
}

void reverse(char *s) {
    int size = strlen(s);
    for (int i = 0; i < size / 2; i++) {
        char temp = s[i];
        s[i] = s[size-i-1];
        s[size-i-1] = temp;
    }
    printf("%s\n", s);
}