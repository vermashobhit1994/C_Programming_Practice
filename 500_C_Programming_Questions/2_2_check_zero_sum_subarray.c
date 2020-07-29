//Program to check if the zero sum subarray exists or not
#include<stdio.h>
#include<stdlib.h>//for exit()
#include<stdbool.h>
#define MAX 1000
int  check_zero_sum(int *arr, int n);
int check_sum_exists(int sum,int *hash_table,int cur_index);
int main()
{
    int arr[] = {1, 4, -2, -2, 5, -4, 3},choice;
    printf("MENU\n1. USING HASHING\n2. EXIT\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            if(check_zero_sum(arr, sizeof(arr)/sizeof(arr[0])) )
                printf("zero sum subarray exists \n");
            else
                printf("Zero sum subarray doesn't exists\n");
            break;
        case 2:
            exit(0);
        default:
            printf("Enter the correct choice\n");
    }
}
/* To check if the sum exists in the hash table or not*/
int check_sum_exists(int sum,int *hash_table,int cur_index)
{
    for(int i = 0;i<cur_index;i++)
        if(sum == hash_table[i])
            return true;
    return false;
}
int check_zero_sum(int *arr, int n)
{
    int hash_table[MAX] = {0},sum = 0;
    for(int i = 0;i<n;i++)
    {
        sum += arr[i];//calculate the sum upto current index
        if(sum == 0 || check_sum_exists(sum,hash_table,i))
            return true;
        hash_table[i] = sum;
        
    }
    return false;
}