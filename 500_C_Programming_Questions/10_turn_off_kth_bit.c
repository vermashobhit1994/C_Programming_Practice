/* Program to turn off or reset the kth bit in number*/
#include<stdio.h>
void reset_kth_bit(int *p,int k)
{
    *p = (*p) & ~(1<<(k-1)); 
}
int main()
{
    int n,k;
    printf("Enter the no\n");
    scanf("%d",&n);
    printf("Enter the kth bit value\n");
    scanf("%d",&k);
    reset_kth_bit(&n,k);
    printf("value after result = %d\n",n);
}