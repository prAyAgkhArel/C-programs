#include <stdio.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define MAX 4
#define MOST 50 

struct stack {
    int TOS;
    char arr_data[MAX][MOST]; // Array to hold strings
};

int isfull(struct stack *ptr) {
    if (ptr->TOS == MAX - 1)
        return TRUE;
    else
        return FALSE;
}

int isempty(struct stack *ptr) {
    if (ptr->TOS == -1)
        return TRUE;
    else
        return FALSE;
}

void push(struct stack *ptr, const char *value) {
    if (!isfull(ptr)) {
        ptr->TOS += 1;
        strcpy(ptr->arr_data[ptr->TOS], value);
    } else {
        printf("Stack is full\n");
    }
}

char* pop(struct stack *ptr) {
    if (!isempty(ptr)) {
        char* popped_value = ptr->arr_data[ptr->TOS];
        ptr->TOS -= 1;
        return popped_value;
    } else {
        printf("Nothing to pop from stack\n");
        
    }
}

char* peek(struct stack *ptr) {
    if (!isempty(ptr)) {
        return ptr->arr_data[ptr->TOS];
    } else {
        printf("Stack is empty\n");
    
    }
}

int main() {
    char value[MOST];
    int choice;
    struct stack s = { -1 };

    do {
        printf("1. PUSH\n2. POP\n3. PEEK\n4. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the string you want to push into stack: ");
                scanf("%s", value);
                push(&s, value);
                printf("%s was pushed\n", value);
                break;
            case 2:
                printf("%s was popped\n", pop(&s));
                break;
            case 3:
                printf("%s is at the top of stack\n", peek(&s));
                break;
            case 4:
                printf("Thank you!!\n");
                break;
            default:
                printf("Choice can be 1, 2, 3, or 4 only\n");
                break;
        }
    } while (choice != 4);

    return 0;
}
