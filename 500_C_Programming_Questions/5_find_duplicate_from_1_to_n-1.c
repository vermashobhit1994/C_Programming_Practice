//Program to find the duplicate elements in array from 1 to n-1 elements
#include<stdio.h>
#include<stdlib.h>//for exit(0)
#include<stdbool.h>//for true and false
#define MAX 1000
//works when the zero repeats
void duplicate_find_hashing(int *arr, int n)
{
    int hash_table[MAX] = {false},found_duplicate = false;
    for(int i= 0;i<n;i++)
    {
        /* checking the index in hash table as 1
        Since if value repeats then at that particular index in hash table
        we get the repeated 1 value.*/
        if(hash_table[arr[i]] == true)
        {
            found_duplicate = true;
            printf("duplicate element is %d \n",arr[i]);
            //break;/* to avoid if more than 1 element repeat*/
        }
        /* putting the hash_table value as 1*/
        hash_table[arr[i]] = true;
    }
    if(found_duplicate == false)
        printf("No duplicate element found\n");
}
void duplicate_find_negative(int *arr, int n)
{
    int duplicate = -1;
    for(int i= 0;i<n;i++)
    {
        int item = abs(arr[i]);//current absolute value when the value is negative
        if(arr[item-1] >= 0)//if the value is positive
            arr[item-1] = -arr[item-1];//negative at the current index
        else
        {
            duplicate = item;
            printf("duplicate element is %d\n",duplicate);
            //break;//remove break to find more than duplicate element
        }
    }
    //restore the original array
    for(int i= 0;i<n;i++)
    {
        if(arr[i] < 0)
            arr[i] = -arr[i];
    }
    //print when no duplicate found
    if(duplicate == -1)
        printf("No duplicate element found\n");
    
}
/*not used to find more than one duplicate values
and if no duplicate element is there*/
void duplicate_find_xor(int *arr, int n)
{   
    int xor = 0;
    /*find the xor of current elements . Here the duplicate element is excluded
    since the xor of duplicate element is zero*/
    for(int i= 0;i<n;i++)
    {
        xor ^= arr[i];
    }
    //xor from 1 to n-1
    for(int i= 1;i<n;i++)
        xor ^= i;
    printf("duplicate element found = %d\n",xor);
}
/*not used to find more than one duplicate values
and no duplicate element */
void duplicate_find_sum(int *arr, int n)
{
    int sum_array = 0,sum_n = 0;
    //sum from 1 to n-1
    for(int i = 1;i<n;i++)
        sum_n += i;
    for(int j = 0;j<n;j++)
        sum_array +=arr[j];
    printf("sum_n = %d, sum_array = %d\n",sum_n,sum_array);
    if(sum_array - sum_n != 0)
        printf("duplicate no is %d\n",sum_array - sum_n);
    /*here the sum would be zero if there are no duplicate elements*/
    else
        printf("no duplicate element found\n");
        
}
int main(void)
{   
    int choice,arr[] = {1,3,2,3,4};

    while(true)
    {
        printf("\nMENU\n1. USING HASHING\n2. USING NEGATIVE NO CONCEPT\n3. USING XOR\n4. USING SUM METHOD\n5. EXIT\n");
        printf("Enter the choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
           case 1:  
                duplicate_find_hashing(arr, sizeof(arr)/sizeof(arr[0]));
                break;
            case 2:
                duplicate_find_negative(arr, sizeof(arr)/sizeof(arr[0]));
                break;
            case 3:
                duplicate_find_xor(arr, sizeof(arr)/sizeof(arr[0])) ;
                break;
            case 4:
                duplicate_find_sum(arr, sizeof(arr)/sizeof(arr[0]));
                break;
            case 5:
                exit(0);
            default:
                printf("Enter the correct choice\n");
        }
    }

}
