#include<iostream>
using namespace std;
class feet;
class meter
{
    private:
    float m;
    public:
    meter()
    {
        m=0;
    }
    meter(float f)
    {
        m=f;
    }
    void display()
    {
        cout<<"the value of converted data to meter is "<<m<<endl;
    }
};
class feet
{
    private:
    int f;
    public:
     void input()
     {
        cout<<"enter the value in feet"<<endl;
        cin>>f;
     }
     operator meter()
     {
        float m=f*0.3048;
        return(meter(m));
     }
};
int main()
{
    feet f;
    meter m;
    f.input();
    m=f;
    m.display();
    return 0;
}