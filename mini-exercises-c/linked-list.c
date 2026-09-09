#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *next;
} Node;

Node* reverseList(Node **head);
int main() {

    //create the list first
    Node *head = malloc(sizeof(Node));
    head -> val = 0;
    head -> next = NULL;

    Node *curr = head;

    for (int i = 1; i <= 11; i++) {
        Node *next = malloc(sizeof(Node));
        next -> val = i;
        curr -> next = next;
        curr = next;
    }

    reverseList(&head);
    return 0;
}
Node* reverseList(Node **head) {
    Node *prev = NULL;
    Node *curr = *head;

    while (curr) {
        Node *temp = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = temp;
    }

    *head = prev;
    return *head;
}