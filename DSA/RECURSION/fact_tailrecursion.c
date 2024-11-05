#include<stdio.h>
unsigned long long fact(unsigned int n, unsigned long long result)
{
    if (n==1)
    return result;
    else{
       fact(n-1, n*result);
    }
}
int main(){
    unsigned int n;
    printf("Enter the number for which you want to find factorial:");
    scanf("%d" ,&n);
    printf("\nThe factorial of the entered number is %llu",fact(n,1));
    return 0;
}