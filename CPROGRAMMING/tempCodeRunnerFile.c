#include<stdio.h>
int GCD(int min, int max)
{
    if(max%min==0)
    return min;
    else
    return GCD(max % min, min);
}

int main(){
int a,b,min,max;
printf("Enter any two numbers for their greatest common divider:");
scanf("%d %d", &a, &b);
if(a==b)
printf("The greatest common divider is %d",a);
else{
     (a > b) ? (max = a, min = b) : (max = b, min = a);
     printf("The greatest common divider is %d",GCD(min,max));
}

   return 0;
}