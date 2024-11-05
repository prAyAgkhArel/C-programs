#include<iostream>
using namespace std;

class smallobj{
    private:
    int somedata;
    public:
    void setdata(int d){
            somedata=d;
        }
    void showdata(){
            cout<<"Data is "<<somedata<<endl;
        }
};
int main()
{
    smallobj s1,s2;
    s1.setdata(100);
    s2.setdata(200); // setdata function ley duitai data 100 ra 200 set garxa s1 ra s2 ko use garera!(wow)

    s1.showdata();
    s2.showdata();

    return 0;
}