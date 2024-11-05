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

    auto t1=chrono::high_resolution_clock::now();
    bubblesort(A,n);
    auto t2=chrono::high_resolution_clock::now();
    auto duration=chrono::duration_cast<chrono::microseconds>(t2-t1);
    cout<<"Time= "<<duration.count()<<endl;
   
    
    return 0;
}