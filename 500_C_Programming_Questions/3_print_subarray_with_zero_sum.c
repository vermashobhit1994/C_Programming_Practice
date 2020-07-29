/* Program to print all the subarrays with zero sum*/
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define MAX 1000

void print_zero_sum_subarray(int *arr, int n);
void print_subarray(int *arr, int fist_index,int last_index);
int find_index_repeat_sum(int *arr, int cur_index,int cur_sum);

int main()
{
    int arr[] = {3,4,-7,3,1,3,1,-4,-2,-2},choice;
    printf("MENU\n1. USING HASHING\n2. EXIT\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            print_zero_sum_subarray(arr,sizeof(arr)/sizeof(arr[0]));
            break;
        case 2:
            exit(0);
        default:
            printf("Enter the correct choice\n");
    }
}
void print_subarray(int *arr, int first_index,int last_index)
{
    printf("The subarray is \n");   
    for(int i=first_index;i<=last_index;i++)
        printf("%d, ",arr[i]);
    printf("\n");
    
}
/* To find the index where the sum appeared in hash table*/
int find_index_repeat_sum(int *arr, int cur_index,int cur_sum)
{
    for(int i=0;i<cur_index;i++)
    {
        if(arr[i] == cur_sum)
            return i;
    }
    return -1;
}

void print_zero_sum_subarray(int *arr, int n)
{
    /* here the repeat_sum_index is initialized with -1 to 
    avoid the condition for index return = 0*/
    int hash_table[MAX] = {0},repeat_sum_index = -1,sum = 0;
    for(int i = 0;i<n;i++)
    {
        
        sum += arr[i];//calculate the sum upto current index
        /* condition for the repeat sum */
        
        {   
        repeat_sum_index = find_index_repeat_sum(hash_table,i,sum);
        }
        /* condition for zero sum and repeated sum check*/
        if(sum == 0|| repeat_sum_index != -1  )
        {
            
            /*print the subarray corresponding to zero sum*/
            if(sum == 0)
                print_subarray(arr, 0,i);
            /*Here the zero can be repeat.
            When the zero repeat then repeat_sum_index changes from default value i.e -1
            +1 is done since the elements that include in sum to zero starts after 
            element not included is found*/
            if(repeat_sum_index != -1)
                print_subarray(arr,repeat_sum_index+1,i);
        }
        /* if the sum doesn't match in hash table put that sum to hash table ith index*/
        hash_table[i] = sum;
    }
}