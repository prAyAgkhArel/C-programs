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

    auto t1=chrono::high_resolution_clock::now();
    qsort(A,i,n);
    auto t2=chrono::high_resolution_clock::now();
    auto duration=chrono::duration_cast<chrono::microseconds>(t2-t1);
    cout<<"Time= "<<duration.count()<<endl;
   
   
    /*cout<<"Before sorting"<<endl;     //10=1351us,100=0s,1000=0s,10000=96582us,100000=9829310us
    display(A,n);
    qsort(A,i,n);
    cout<<"After sorting"<<endl;
    display(A,n);*/

    return 0;
}