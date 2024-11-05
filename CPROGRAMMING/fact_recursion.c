#include<stdio.h>

int fact(int n){
    if(n==1)
    return 1;
    else
    return n*fact(n-1);
}

int main(){
    
    
    int n;
    printf("Enter the number for which you want factorial.");
    scanf("%d",&n);
    printf("The factorial of the entered number is %d\n",fact(n));
      

return 0;
}


