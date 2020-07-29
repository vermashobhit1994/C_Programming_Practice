/* Program to find the position of an alphabet 26 characters*/
#include<stdio.h>
int find_pos_alphabet(char ch)
{
    int mask = (1<<6) | (1<<5);//to clear the 32 and 64 value
    return ch & ~(mask); 
}
int main()
{
    char ch;
    printf("enter the character \n");
    scanf("%c",&ch);
    
    int pos =  find_pos_alphabet(ch);
    printf("Position of %c alphabet  = %d\n",ch,pos);   

}