/*Program to calculate the absolute value of an integer*/
#include<stdio.h>
#define CHAR_BIT 8
int cal_abs(int n)
{
    int mask = n>>(sizeof(int) * CHAR_BIT - 1);//equals to 4 *8  -1
    
    return (n + mask) ^ mask;//addition to clear the +ve part bits
}
int main()
{
    int n;
    printf("Enter the no\n");
    scanf("%d",&n);
    printf("absolute value is %d\n",cal_abs(n));
}