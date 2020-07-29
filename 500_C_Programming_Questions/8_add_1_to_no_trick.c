/*  Program to add 1 to number trick*/
#include<stdio.h>
int main()
{
    int n;
    printf("Enter a no\n");
    scanf("%d",&n);
    printf("%d + 1 = %d\n",n,-~n);
}