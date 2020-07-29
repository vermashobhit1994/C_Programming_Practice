/* Program to check whether the no has a odd or even parity*/
#include<stdio.h>
#include<stdbool.h>
void parity_check(int n)
{
    int count = 0,parity = false;
    while(n )
    {
        parity = !parity;
        n = n&(n-1);
        //count++;
    }
    if(parity)
        printf("odd parity\n");
    else    
        printf("even parity\n");
    /*
    if(count & 1)
        printf("Odd parity\n");
    else
        printf("Even parity\n");*/

}
int main(void)
{
    int n;
    printf("Enter the no\n");
    scanf("%d",&n);
    parity_check(n);
}