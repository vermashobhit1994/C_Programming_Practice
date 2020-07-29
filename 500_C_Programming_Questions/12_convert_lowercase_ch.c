/*Program to convert the uppercase letter to lowercase*/
#include<stdio.h>
char convert_lowercase(char ch)
{
    int mask = 1<<5;//five for the value 32
    ch |= mask;
    return ch;
}
int main()
{
    char ch;
    printf("enter the character\n");
    scanf("%c",&ch);
    ch = convert_lowercase(ch);
    printf("In lowercase ch = %c\n",ch);
}