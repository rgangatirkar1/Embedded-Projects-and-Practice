#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

int my_strlen(const char *s);
void my_strcpy(char *dest, const char *src);
bool is_palindrome(const char *s);

int main() {
    const char *test_string = "my-test-string";
    assert(my_strlen(test_string) == 14);
    printf("String length test passed!\n");

    const char *str_to_copy = "speak-your-mi";
    char buffer[14];
    my_strcpy(buffer, str_to_copy);
    for (int i = 0; i < my_strlen(buffer); i++) {
        assert(buffer[i] == str_to_copy[i]);
    }
    printf("String copy test passed!\n");
    char *palindrome = "racecar";
    char *not_palindrome = "hello";
    assert(is_palindrome(palindrome) == true);
    assert(is_palindrome(not_palindrome) == false);
    printf("Palindrome test passed!\n");
    return 0;
}

int my_strlen(const char *s) {
    int length = 0;
    while (*(s + length) != '\0') {
        length++;
    } 
    return length;
}

void my_strcpy(char *dest, const char *src) {
    int length = my_strlen(src);
    int count = 0;
    while (count < length) {
        *(dest + count) = src[count];
        count++;
    }
    dest[count] = '\0';
}

bool is_palindrome(const char *s) {
    int start = 0;
    int end = my_strlen(s)-1;
    while (start < end) {
        if (s[start] != s[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}