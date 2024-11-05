#include<stdio.h>
void TOH(int n, char src, char dst, char tmp)
{
    if(n==1)
    printf("Move disc %d from %c to %c\n",n, src,dst);
    else{
        TOH(n-1,src,tmp,dst);
        printf("Move disc %d from %c to %c\n",n, src,dst);
        TOH(n-1,tmp,dst,src);}
 }

int main()
{
    int n;
    printf("Enter the number of discsS:");
    scanf("%d",&n);
    TOH(n,'A','C','B');
    return 0;
}