#include<iostream>
using namespace std;

class smallobj{
      public:
    int somedata;
    void showdata(){
            cout<<"Data is "<<somedata<<endl;
        }
};
int main()
{
    smallobj s1,s2;
   s1.somedata=100;
   s2.somedata=150; //main function baatai classko publicko data change gareko
    s1.showdata();
    s2.showdata();

    return 0;
}