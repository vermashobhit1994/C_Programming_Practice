/*Program to convert the uppercase letter to lowercase*/
#include<stdio.h>
char convert_uppercase(char ch)
{
    int mask = 1<<5;
    return ch & ~(1<<5);   
    
}
int main()
{
    char ch;
    printf("enter the character %d\n",'_');
    scanf("%c",&ch);
    ch = convert_uppercase(ch);
    printf("In Uppercase ch = %c\n",ch);
}
