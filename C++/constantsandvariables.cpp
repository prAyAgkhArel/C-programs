#include<iostream>
#include<limits.h>  // has max and min value of all datatypes
using namespace std;

int main(){
    char a='2';
    std::cout<<a<<std::endl;
    std::cout<<(int)a<<std::endl;  //typecasting prints ascii value of character 2
     
     a=127;      //treats 127 as an ascii value and prints the character of that value if a is printed.
    std::cout<<a<<std::endl;
    std::cout<<(int)a<<std::endl; //typecasting
    
    cout<<SCHAR_MIN<<endl; //prints min ascii value of short char
    cout<<SCHAR_MAX<<endl; //prints max ascii value of short char
    
    return 0;
}