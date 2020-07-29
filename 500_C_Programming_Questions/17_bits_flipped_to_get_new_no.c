/* Program to find the no of bits to be flipped to get the new number from the old no*/
#include<stdio.h>
/* for the -ve no it first convert it to +ve no and then check the bits*/
void count_bits_flipped(int old_val,int new_val)
{
    int xor = old_val  ^ new_val,count = 0;
    while(xor)
    {
        xor = xor & (xor -1);
        count++;
    }
    printf("count = %d\n",count);
}
int main()
{
    int new_no,old_no;
    printf("enter the oldno and new no\n");
    scanf("%d%d",&old_no,&new_no);
    count_bits_flipped(old_no,new_no);
}