/* program to swap the two numbers using bitwise XOR operator*/
#include<stdio.h>
void swap(int *a, int *b)
{
    if(*a != *b)
    {
        *a = *a ^ *b;
        *b = *a ^ *b;
        *a = *a ^ *b;
    }
}
int main()
{
    int num1,num2;
    printf("Enter the two no's \n");
    scanf("%d%d",&num1,&num2);
    swap(&num1,&num2);
    printf("%d,%d\n",num1,num2);
    
}