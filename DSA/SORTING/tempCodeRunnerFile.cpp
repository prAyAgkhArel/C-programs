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
   

    cout<<"Before sorting"<<endl;     //10=1351us,100=0s,1000=0s,10000=96582us,100000=9829310us
    display(A,n);
    insertionsort(A,n);
    cout<<"After sorting"<<endl;
    display(A,n);

    return 0;
}