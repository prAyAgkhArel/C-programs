#include<stdio.h>
#include<string.h>
#define MAX 4
#define MOST 50

struct queue
{
    int front;
    int rear;
    char data[MAX][MOST];

};

int isfull(struct queue *ptr)
{
    if (ptr->rear==MAX-1)
    return 1;
    else
    return 0;
    
}

int isempty(struct queue *ptr)
{
    if(ptr->front>ptr->rear)
    return 1;
    else
    return 0;
}

void enqueue(struct queue *ptr, const char *value)
{
    ptr->rear+=1;
    strcpy(ptr->data[ptr->rear], value);
}

char * dequeue(struct queue *ptr)
{
     char *dequed_value=ptr->data[ptr->front++];
     return dequed_value;
}

char * checkfront(struct queue *ptr)
{
     char *front_value=ptr->data[ptr->front];
     return front_value;
}

char * checkrear(struct queue *ptr)
{
     char *rear_value=ptr->data[ptr->rear];
     return rear_value;
}

int main()
{
    struct queue s={0,-1};
    char value[MOST];
    int choice;
    do{
        printf("1.Enqueue\n2.Dequeue\n3.Check Front\n4.Check Rear\n5.Exit\n");
        printf("choice??");
        scanf("%d",&choice);
        switch(choice){
            case 1:
               if (isfull(&s)) 
               printf("Queue is full!\n");
               else{
                  printf("Enter the string that you want to enqueue:\n");
                  scanf("%s",value);
                  enqueue(&s,value);
                  printf("%s was enqueued.\n",value);
               }
            break;

            case 2:
            if(isempty(&s))
            printf("Queue is empty");
            else{
                printf("%s was dequeued.\n",dequeue(&s));
            }
            break;

            case 3:
              printf("%s is in front.\n",checkfront(&s));
            break;

            case 4:
             printf("%s is in rear.\n", checkrear(&s));
            break;

            case 5:
            printf("Thank you!");
            break;

            default:
            printf("Enter choices among the options!\n");
            break;
        }
    }while(choice!=5);
    
        return 0;}

