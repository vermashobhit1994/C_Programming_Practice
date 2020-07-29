/* Program to find the pairs with given sum*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 1000
void find_pair_using_loop(int *arr, int n,int sum);
void find_pair_using_sorting(int *arr, int n,int sum);
void find_pair_using_hashing(int *arr, int n,int sum);

int main()
{
    int arr[] = {8,7,2,5,3,1},choice,sum = 0;
    printf("MENU\n1. DOUBLE LOOP\n2. SORTING\n3. HASHING\n4. EXIT\n");
    scanf("%d",&choice);
    printf("Enter the sum \n");
    scanf("%d",&sum);
    switch(choice)
    {
        case 1: 
            find_pair_using_loop(arr, sizeof(arr)/sizeof(arr[0]),sum);
            break;
        case 2: 
            find_pair_using_loop(arr, sizeof(arr)/sizeof(arr[0]),sum);
            break;
        case 3: 
            find_pair_using_loop(arr, sizeof(arr)/sizeof(arr[0]),sum);
            break;
        case 4: 
            exit(0);
        default:
            printf("Enter the correct choice\n");

    }
}
void find_pair_using_loop(int *arr, int n,int sum)
{
    for(int i=0;i<n-1;i++)//loop to check the current value
    { 
        
        for(int j=i+1;j<n;j++)//loop to check the next values from current value to end of array
        {
            if(arr[j] == sum - arr[i])//condition to check the two values that makes the sum
            {
                printf("%d and %d pairs\n",arr[i],arr[j]);
                break;//once value is found then no need to move further
            }
                
        }
    }
}
int compare_func(const void *val1,const void *val2)
{
    return ( *(int *)val1 - *(int *)val2);
}

void find_pair_using_sorting(int *arr, int n,int sum)
{
    qsort(arr,n,sizeof(arr[0]),compare_func);//sort using the predefined quick sort
    int low = 0;//index start from 1st element
    int high = n-1;//index start from last element
    for(int i=0;i<n;i++)
    {
        if(low+high <  sum)//increment low if sum is low then current sum
            low++;
        else if(low+high > sum)//decrement high if sum is high then current sum
            high--;
        else//we get the sum
        {
            printf("%d, and %d are pairs with sum = %d\n",arr[low],arr[high],sum);
            low++;//done since to check the next pair of sum
            high--;
        }
    }
}

void find_pair_using_hashing(int *arr, int n,int sum)
{
    int hash_table[MAX] = {0};
    for(int i = 0;i<n;i++)
    {
        int diff = sum - arr[i];//find the one value that makes up the sum 
        if(hash_table[diff] == 1)//checking if the value repeats or not
            printf("%d and %d are pairs with sum = %d\n",arr[i],diff,sum);
        hash_table[arr[i]] = 1;//putting it 1 to check the repetition
    }
}
