//Program to find the number of seconds in year using the macro (manifest constant)

#include<stdio.h>



#define NO_OF_SEC_YEAR(YEAR)     (YEAR % 100 != 0 && YEAR % 4 == 0 || YEAR % 400 == 0)?\
                                     ( ( 366 * 24 * 60 *60) ):\
                                     ( ( 365 * 24 * 60*60))
                                 
                                 
                                 
int main()
{
    int year = 2000;//2000 is leap year
    //int year = 1998;//1998 is normal year
    
    printf("No of seconds = %d\n",NO_OF_SEC_YEAR(year));
}
