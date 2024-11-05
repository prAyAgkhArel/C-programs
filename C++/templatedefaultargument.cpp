#include<iostream>
using namespace std;
template<int x, class T= int>

class example
{ 

    T arr[x];
    public:
    void getarray()
    {
        int i;
        for(i=0; i<x; i++)
        {
            cin>>arr[i];
        }
    }
    void showarray()
    {   cout<<"array elements are:";
        int i;
        for(i=0; i<x; i++)
        {
            cout<<endl<<arr[i]1;
        }
    }


};

      int main()
      {
        example <2,int>a1;
        example <3>a2;
        example<2,float>a3;

        a1.getarray();
        a2.getarray();
        a3.getarray();
        a1.showarray();
        a2.showarray();
        a3.showarray();

        return 0;
      }