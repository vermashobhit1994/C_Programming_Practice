/*Program to invert the lowercase to uppercase and uppercase to lowercase*/
#include<stdio.h>
char invert_case(char ch)
{
    return ch ^(1<<5);
}
int main()
{
    char ch;
    printf("enter the character \n");
    scanf("%c",&ch);
    ch = invert_case(ch);
    printf("ch = %c\n",ch);   
}