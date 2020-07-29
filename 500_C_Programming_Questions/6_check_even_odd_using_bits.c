/* Program to check if the given integer is even or odd
using the bitwise operator*/
#include<stdio.h>
void check_even_odd(int n)
{
    if(n & 1 == 1)
        printf("no is odd \n");
    else
        printf("no is even \n");
}
int main()
{
    int n;
    printf("Enter the no to be check\n");
    scanf("%d",&n);
    check_even_odd(n);
}
