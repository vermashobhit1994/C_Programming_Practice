//Program to understand the difference between enum and macro in c

#include<stdio.h>
#include<stdint.h>
#include<limits.h>
#define MONDAY      0L
#define TUESDAY     1
#define WEDNESDAY   5.6
#define THRUSDAY    -1
#define FRIDAY      4
#define SATURDAY    5
#define SUNDAY      6


#define DAY  TUESDAY	

#if DAY==MONDAY
    #define STR  "Today is Monday\n"
#elif DAY==TUESDAY
    #define STR  "Today is Tuesday\n"
#endif





typedef enum 
{
	Monday =0L,
	Tuesday,

	//error since constant must be integer
	//Wednesday = 5.6,
	Wednesday ,
	Thrusday=-1,
	Friday,
	Saturday,
	Sunday
}day_t;



#define day Tuesday
#if day==Monday
    #define ENUMSTR "Monday is today\n"
#elif day==Tuesday
    #define ENUMSTR "Tuesday is today\n"
#endif



int main()
{
	
	//day_t day = Tuesday;

        //1. Macro is expanded at preprocessing stage while enum is processed at compile time.
	//2. In macro we can specfify the sizeof data type but can't specify in enum.

        printf("sizeof(Monday) = %ld ",sizeof(Monday));//4 bytes
        printf("sizeof(MONDAY) = %ld\n",sizeof(MONDAY));//8 bytes
  
        //3. At debugging time the enum constant remained by constant name and its value isn't replaced.
	

        //4. Using macro we can do conditional compilation(make decisions) but can't do using enum
        printf(STR);//print Tuesday
        printf(ENUMSTR);//print Monday even if day = Tuesday
	printf("Value of day = %d\n",day);

	//5.for enum value must be integer constant and not a decimal value but for macro it can be of any value. 
	printf("value of enum Wednesday = %d\n",Wednesday);
	printf("value of macro WEDNESDAY = %f\n",WEDNESDAY);

	//6.
	day_t day = Thrusday;
	uint32_t current_day = THRUSDAY;
	printf("value of macro THRUSDAY = %#x\n",Thrusday << 2 );
        printf("value of enum Thrusday = %#x\n",THRUSDAY << 2);

	printf("Using enum Current Day = %d\n",day);
}
