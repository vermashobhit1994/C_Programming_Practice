/* program to check if the two no's have the opposite signs or not
using the XOR*/
#include<stdio.h>
void check_opposite_sign(int a,int b)
{
    if( (a ^ b) < 0)
        printf("%d and %d no's have opposite signs\n",a,b);
    else
        printf("%d and %d no's have same signs\n",a,b);
}
int main()
{
    int num1,num2;
    printf("ENter the no's to be checked\n");
    scanf("%d%d",&num1,&num2);
    check_opposite_sign(num1,num2);
}