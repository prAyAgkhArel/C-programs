/*Write a program that has a class with a dynamically allocated character array as its data member. One 
object should contain "Engineers are" and another should contain " Creatures of logic". Member function 
join() should concatenate two strings by passing two objects as arguments. Display the concatenated 
string through a member function. Use constructors to allocate and initialize the data member. Also, 
write a destructor to free the allocated memory for the character array. Make your own function for the 
concatenation of two strings.*/
#include<iostream>
using namespace std;
int main()
{
    int size;
    char name[size];
    cout<<"Enter the size"<<endl;
    cin>>size;
    cin>>name;
    cout<<"The name is "<<name<<endl;
    return 0;
}