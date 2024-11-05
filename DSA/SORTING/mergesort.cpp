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
    int B[100000]; // Increased the size of the array to match the size of the input array A
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
    srand(time(0)); // Seed for random number generation

    for(i=0;i<n;i++)
    {
        A[i]=rand();
    }

    auto t1=chrono::high_resolution_clock::now();
    mergeSort(A,0,n-1);
    auto t2=chrono::high_resolution_clock::now();
    auto duration=chrono::duration_cast<chrono::microseconds>(t2-t1);
    cout<<"Time= "<<duration.count()<<endl;
    
    // cout<<"Before sorting"<<endl;
    // display(A,n);
    // cout<<"After sorting"<<endl;
    // display(A,n);

    return 0;
}
