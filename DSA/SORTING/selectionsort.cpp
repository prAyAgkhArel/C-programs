
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

    /*auto t1=chrono::high_resolution_clock::now();
    selectionsort(A,n);
    auto t2=chrono::high_resolution_clock::now();
    auto duration=chrono::duration_cast<chrono::microseconds>(t2-t1);
    cout<<"Time= "<<duration.count()<<endl;*/
   
    
    cout<<"Before sorting"<<endl;     //10=1351us,100=0s,1000=0s,10000=150981us,100000=25475164us
    display(A,n);
    selectionsort(A,n);
    cout<<"After sorting"<<endl;
    display(A,n);

    return 0;
}