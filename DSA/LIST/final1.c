// Singly linked list

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

//OUTPUT:
  
100 was inserted at the front.
100 ->NULL
200 was inserted at the front.
200 -> 100 ->NULL
300 was inserted at the front.
400 was inserted at the front.
500 was inserted at the front.
500 -> 400 -> 300 -> 200 -> 100 ->NULL
500 -> 400 -> 300 -> 200 ->NULL
500 -> 400 -> 300 ->NULL




//doubly linked list:

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
    struct dll_node newNode = (struct dll_node)malloc(sizeof(struct dll_node));
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

/*
output:
100 was inserted at the front.
NULL <-> 100 <-> NULL
200 was inserted at the front.
NULL <-> 200 <-> 100 <-> NULL
300 was inserted at the front.
400 was inserted at the front.
500 was inserted at the front.
NULL <-> 500 <-> 400 <-> 300 <-> 200 <-> 100 <-> NULL
NULL <-> 500 <-> 400 <-> 300 <-> 200 <-> NULL
NULL <-> 500 <-> 400 <-> 300 <-> NULL
*/



// bubblesorting

#include<iostream>
#include<chrono>
using namespace std;

void swap(int *x, int *y)  //labsheetmaa 10,100,10000 ko time naapne
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

void display(int A[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

void bubblesort(int A[], int n)
{
int i,j;
for(i=0;i<n-1;i++)
{
    for(j=0;j<n-i-1;j++)
    {
       if(A[j]>A[j+1])
          swap(&A[j],&A[j+1]);
    }
}

}
int main()
{
    int A[100000],n,i;
    cout<<"Enter n "<<endl;
    cin>>n;
    for(i=0;i<n;i++)
    {
        A[i]=rand();
    }

    cout<<"Before sorting"<<endl;     
    display(A,n);
    bubblesort(A,n);
    cout<<"After sorting"<<endl;
    display(A,n);

    auto t1=chrono::high_resolution_clock::now();
    bubblesort(A,n);
    auto t2=chrono::high_resolution_clock::now();
    auto duration=chrono::duration_cast<chrono::microseconds>(t2-t1);
    cout<<"Time= "<<duration.count()<<endl;

    return 0;
}

//OUTPUT:
Enter n 
10
Before sorting
41 18467 6334 26500 19169 15724 11478 29358 26962 24464 
After sorting
41 6334 11478 15724 18467 19169 24464 26500 26962 29358 
Time= 0
//measuring time only for bubblesort:
Enter n 
10
Time= 0
Enter n 
100
Time= 0
Enter n 
1000
Time= 0
Enter n 
10000
Time= 162902



//INSERTION SORTING:
#include<iostream>
#include<chrono>
using namespace std;

void swap(int *x, int *y)  //labsheetmaa 10,100,10000 ko time naapne
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

void display(int A[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

void insertionsort(int A[], int n)
{
int i,j;
for(i=0;i<n-1;i++)
{
   int smallest=A[i];
   int position=i;
   for(j=i+1;j<n;j++)
   {
    if(A[j]<smallest)
    {
    smallest=A[j];
    position=j;
    }
   }
   if(i!=position)
   swap(A[i],A[position]);

}

}
int main()
{
    int A[100000],n,i;
    cout<<"Enter n "<<endl;
    cin>>n;
    for(i=0;i<n;i++)
    {
        A[i]=rand();
    }
   

    cout<<"Before sorting"<<endl;     
    display(A,n);
    insertionsort(A,n);
    cout<<"After sorting"<<endl;
    display(A,n);

    return 0;
}

//OUTPUT:
Enter n 
5
Before sorting
41 18467 6334 26500 19169 
After sorting
41 6334 18467 19169 26500 
//Measuring time for insertion sort
Enter n 
10
Time= 0
Enter n 
100
Time= 0
Enter n 
1000
Time= 0
Enter n 
10000
Time= 107386
Enter n 
100000
Time= 9712137



//SELECTION SORTING:

#include<iostream>
#include<chrono>
using namespace std;

void swap(int *x, int *y)  
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

void display(int A[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

void selectionsort(int A[], int n)
{
int i,j;
for(i=0;i<n-1;i++)
{
   int smallest=A[i];
   int position=i;
   for(j=i+1;j<n;j++)
   {
    if(A[j]<smallest)
    {
    smallest=A[j];
    position=j;
    }
   }
   if(i!=position)
   swap(A[i],A[position]);

}

}
int main()
{
    int A[100000],n,i;
    cout<<"Enter n "<<endl;
    cin>>n;
    for(i=0;i<n;i++)
    {
        A[i]=rand();
    }

    auto t1=chrono::high_resolution_clock::now();
    selectionsort(A,n);
    auto t2=chrono::high_resolution_clock::now();
    auto duration=chrono::duration_cast<chrono::microseconds>(t2-t1);
    cout<<"Time= "<<duration.count()<<endl;
   
    /*
    cout<<"Before sorting"<<endl;     
    display(A,n);
    selectionsort(A,n);
    cout<<"After sorting"<<endl;
    display(A,n);*/

    return 0;
}

//OUTPUT1:

Enter n 
10
Before sorting
41 18467 6334 26500 19169 15724 11478 29358 26962 24464 
After sorting
41 6334 11478 15724 18467 19169 24464 26500 26962 29358 
//measurement of time duration of selection sort
Enter n 
10
Time= 0
Enter n 
100
Time= 0
Enter n 
1000
Time= 0
Enter n 
10000
Time= 110440
Enter n 
100000
Time= 9934402

//QUICK SORTING:
#include<iostream>
#include<chrono>
using namespace std;

void swap(int *x, int *y)  //labsheetmaa 10,100,10000 ko time naapne
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

void display(int A[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

int partition(int A[],int l,int r)
{
   int x=l;
   int y=r;
   int pivot=A[l];
   while(x<y)
   {
    while(A[x]<=pivot)
    x++;
    while(A[y]>pivot)
    y--;
    if(x<y)
    swap(&A[x],&A[y]);
   }
  A[l]=A[y];
  A[y]=pivot;
  return y;
}

void qsort(int A[],int l, int r)
{
    if(l<r)
    {
        int p=partition(A,l,r);
        qsort(A,l,p-1);
        qsort(A,p+1,r);
    }
}   



int main()
{
    int A[100000],n,i;
    cout<<"Enter n "<<endl;
    cin>>n;
    for(i=0;i<n;i++)
    {
        A[i]=rand();
    }

    /*auto t1=chrono::high_resolution_clock::now();
    qsort(A,i,n);
    auto t2=chrono::high_resolution_clock::now();
    auto duration=chrono::duration_cast<chrono::microseconds>(t2-t1);
    cout<<"Time= "<<duration.count()<<endl;*/
   
   
    cout<<"Before sorting"<<endl;     
    display(A,n);
    qsort(A,i,n);
    cout<<"After sorting"<<endl;
    display(A,n);

    return 0;
}


//OUTPUT1:
Enter n 
10
Before sorting
41 18467 6334 26500 19169 15724 11478 29358 26962 24464
After sorting
41 18467 6334 26500 19169 15724 11478 29358 26962 24464

Enter n 
10
Time= 0
Enter n 
100
Time= 0
Enter n 
1000
Time= 0
Enter n 
10000
Time= 0


//MERGESORT:

#include<iostream>
#include<chrono>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;

void swap(int *x, int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

void display(int A[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

void merge(int *A, int left, int mid, int right)
{
    int B[100000]; 
    int i, j, k;
    i = left;
    j = mid + 1;
    k = left;
    while (i <= mid && j <= right)
    {
        if (A[i] <= A[j])
        {
            B[k] = A[i];
            i++;
        }
        else
        {
            B[k] = A[j];
            j++;
        }
        k++;
    }
    if (i > mid)
    {
        while (j <= right)
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    else
    {
        while (i <= mid)
        {
            B[k] = A[i];
            i++;
            k++;
        }
    }
    for (k = left; k <= right; k++)
    {
        A[k] = B[k];
    }
}

void mergeSort(int A[], int l, int r)
{
    int m;
    if (l < r)
    {
        m = floor((l + r) / 2);
        mergeSort(A, l, m);
        mergeSort(A, m + 1, r);
        merge(A, l, m, r);
    }
}

int main()
{
    int A[100000],n,i;
    cout<<"Enter n "<<endl;
    cin>>n;
    srand(time(0)); 

    for(i=0;i<n;i++)
    {
        A[i]=rand();
    }

    /*auto t1=chrono::high_resolution_clock::now();
    mergeSort(A,0,n-1);
    auto t2=chrono::high_resolution_clock::now();
    auto duration=chrono::duration_cast<chrono::microseconds>(t2-t1);
    cout<<"Time= "<<duration.count()<<endl;*/
    
    cout<<"Before sorting"<<endl;
    display(A,n);
    cout<<"After sorting"<<endl;
    display(A,n);

    return 0;
}


//OUTPUT:
Enter n 
10
Before sorting
22335 577 7948 24165 20893 19677 25171 14975 7616 20578 
After sorting
22335 577 7948 24165 20893 19677 25171 14975 7616 20578

Enter n 
20
Time= 0
Enter n 
200
Time= 0
Enter n 
2000
Time= 0
Enter n 
20000
Time= 0



//Binary searching:
#include <stdio.h>
#include <stdlib.h>

#define n 10

void insertionSort(int a[], int size);
int binarySearch(int a[], int key, int left, int right);

int main() {
    int a[n], key, i;

    printf("***** BINARY SEARCH *****\n\n");
    printf("Enter 10 numbers:\n");

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    insertionSort(a, n);

    printf("\nEnter the number to search: ");
    scanf("%d", &key);

    int foundIndex = binarySearch(a, key, 0, n - 1);

    if (foundIndex != -1)
        printf("\n%d was found at position %d\n", key, foundIndex + 1);
    else
        printf("\n%d was not found\n", key);

    return 0;
}

void insertionSort(int a[], int size) {
    int i, j, temp;
    for (i = 1; i < size; i++) {
        temp = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > temp) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
}

int binarySearch(int a[], int key, int left, int right) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] == key)
            return mid;
        else if (a[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1; // Key not found
}

//OUTPUT:
Enter 10 numbers:
0
10
20
33
44
55
6
77
88
99

Enter the number to search: 55

55 was found at position 7


//LINEARSEARCHING:
#include<iostream>

using namespace std;

int LS(int A[],int n,int key)
{
    int i,flag=0;
    
    for(i=0;i<n;i++)
    {
        if (A[i]== key)
        {
            flag = 1;
            return i;
        }
    }

    if (flag==0)
    return -1;
}

int main()
{
    int A[100000],n,i,key;
    cout<<"Enter n ";
    cin>>n;
    
    for(i=0;i<n;i++)
     {
    A[i]=rand();
    printf("%d\n",A[i]);
   }
    cout<<"Enter key ";
    cin>>key;
    cout<<"key is at position "<<LS(A,n,key)<<endl;
    return 0;
}

//OUTPUT:
Enter n 5
41
18467
6334
26500
19169
Enter key 41
key is at position 0





