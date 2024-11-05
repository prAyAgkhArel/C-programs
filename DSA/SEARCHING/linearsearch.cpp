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