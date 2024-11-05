#include<stdio.h>
#define TRUE 1
#define FALSE 0
#define MAX 4

struct stack
{
int TOS;
int arr_data[MAX];
};

int isfull(struct stack *ptr)
{
    if(ptr->TOS==MAX-1)
    return TRUE;
    else
    return FALSE;
}

int isempty(struct stack *ptr)
{
    if(ptr->TOS==-1)
    return TRUE;
    else 
    return FALSE;
 }

 void push(struct stack *ptr, int value)
 {
    ptr->TOS+=1;
    ptr->arr_data[ptr->TOS]=value;
 }

 int pop(struct stack *ptr)
 {
    return ptr->arr_data[ptr->TOS--];
    
 }

 int peek(struct stack *ptr)
 {
     return ptr->arr_data[ptr->TOS];
 }



int main(){
    int value, choice;
    struct stack s={-1};
    do{
        printf("1.PUSH\n2.POP\n3.PEEK\n4.EXIT\n");
        printf("choice??");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            if(isfull(&s))
            printf("Stack is full\n.");
            else
            {
                printf("Enter the element you want to push into stack:\n");
                scanf("%d",&value);
                printf("%d was pushed\n",value);
                push(&s,value);
            }
            break;

            case 2:
            if(isempty(&s))
            printf("Nothing to pop from stack.\n");
            else
            {
                printf("%d was poped\n",pop(&s));
            }
            break;

            case 3:
             if(isempty(&s))
            printf("Stack is empty.\n");
            else
            {
                printf("%d is at the top of stack.\n",peek(&s));
            }
            break;

             case 4:
            printf("Thank you!!\n");
            break;

            default:
            printf("Choice can be 1,2,3 and 4 only\n");
        }   


        }while(choice!=4);
        return 0;
      }

