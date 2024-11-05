
#include<stdio.h>
#include<stdlib.h>
struct sll
{
    int data;
    struct sll *next;
};

struct sll *first, *last;
void insertAtFront(int element)
{
   struct sll *NewNode;
   NewNode=(struct sll*)malloc(sizeof(struct sll));
   if(NewNode==NULL)
   {
    printf("Memory allocation failed!\n");

   }
   else
   {

    NewNode->data=element;
    NewNode->next=NULL;
    if(first==NULL)//i.e. list is empty
    {
        first=last=NewNode;
    }
    else
    {
      NewNode->next=first;
      first=NewNode;
    }
    printf("%d was inserted at the front.\n",element);
   }
}
void display()
{
    struct sll *temp =first;
    if(first == NULL)
    {
      printf("Empty list!\n");

    }
    else
    {
      while(temp->next != NULL)
      {
        printf("%d -> ", temp->data);
        temp= temp->next;
      }
      printf("%d ->NULL\n", temp->data);
    }
}
void DeleteFromEnd()
{
  struct sll *temp;
  if(first == NULL)
  {
  printf("Empty list\n");
  }
  else if(first->next == NULL)
  {
    first=last=NULL;
  }
  else{
    temp = first;
    while(temp->next != last)
    {
      temp= temp->next;
    }
    last=temp;
    last->next=NULL;
    temp=temp->next;

  }
}
int main()
{
    first=NULL;
    last=NULL;
    insertAtFront(100);
    display();
    insertAtFront(200);
    display();
    insertAtFront(300);
    insertAtFront(400);
    insertAtFront(500);
    display();
    DeleteFromEnd();
    display();
    DeleteFromEnd();
    display();
    return 0;
}
  