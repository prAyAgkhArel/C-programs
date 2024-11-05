#include<stdio.h>
#include<stdlib.h>

struct dll_node {
    int data;
    struct dll_node *prev;
    struct dll_node *next;
};

struct dll_node *head = NULL;
struct dll_node *tail = NULL;

void insertAtFront(int element) {
    struct dll_node *newNode = (struct dll_node*)malloc(sizeof(struct dll_node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = element;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    printf("%d was inserted at the front.\n", element);
}

void display() {
    struct dll_node *temp = head;
    if (temp == NULL) {
        printf("Empty list!\n");
        return;
    }

    printf("NULL <-> ");
    while (temp->next != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("%d <-> NULL\n", temp->data);
}

void deleteFromEnd() {
    if (head == NULL) {
        printf("Empty list\n");
        return;
    }

    if (head == tail) {
        free(head);
        head = tail = NULL;
    } else {
        struct dll_node *temp = tail->prev;
        temp->next = NULL;
        free(tail);
        tail = temp;
    }
}

int main() {
    insertAtFront(100);
    display();
    insertAtFront(200);
    display();
    insertAtFront(300);
    insertAtFront(400);
    insertAtFront(500);
    display();
    deleteFromEnd();
    display();
    deleteFromEnd();
    display();
    return 0;
}
