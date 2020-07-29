/* Program to sort the binary array in linear time*/
#include<stdio.h>
void sort_using_swap(int *arr, int n);
int  swap_no(int *arr,int cur_index, int prev_index);
void print_array(int *arr, int n);
void sort_using_count(int *arr, int n);
int main(int argc, char **argv)
{

    int arr[] = {1,0,1,0,1,0,0},option;
    printf("1. SWAP METHOD\n2. COUNT METHOD\n");
    printf("Enter your option\n");
    scanf("%d",&option);
    if(option == 1)
    {
        sort_using_swap(arr,sizeof(arr)/sizeof(arr[0]));
        print_array(arr, sizeof(arr)/sizeof(arr[0]));
    }
    else
    {
        sort_using_count(arr, sizeof(arr)/sizeof(arr[0]));
        print_array(arr, sizeof(arr)/sizeof(arr[0]));
    } 
        
}
/* swap the current index no with the initial index 
Then we increment that initial index to +1 to add next zero*/
int  swap_no(int *arr,int cur_index, int prev_index)
{
    int temp;
    temp = arr[cur_index];
    arr[cur_index] = arr[prev_index];
    arr[prev_index] = temp;
    //incremented by 1 since to place the next zero
    return prev_index+1;

}
void sort_using_swap(int *arr, int n)
{
    int swap_next_index = 0;
    for(int i = 0;i<n;i++)
    {
        /*current value is zero then swap the current value with 
        initial index and return the initial index +1*/
        if(arr[i] == 0)
        {
            swap_next_index = swap_no(arr,i,swap_next_index);
        }
    }
}
void print_array(int *arr, int n)
{
    printf("The array is \n");
    for(int i = 0;i< n;i++)
        printf("%d, ",arr[i]);
    printf("\n");
}
void sort_using_count(int *arr, int n)
{
    int count_zero = 0,i = 0;
    while(i < n)
    {
        if(arr[i] == 0)
            count_zero++;
        i++;
    }
    i = 0;
    /* putting the zeroes*/
    while(count_zero--)
    {
        arr[i++] = 0;
    }
    /* put the remaining value as 1*/
    while(i < n)
        arr[i++] = 1;

}