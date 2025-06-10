
/* REQUIRED HEADERS */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include"main.h"


void call_day_of_year(){
	int32_t year,month,day;
	/*taking user input*/
	printf("Enter year:");
	scanf(" %d",&year);
	printf("Enter month:");
        scanf(" %d",&month);
	printf("Enter day:");
        scanf(" %d",&day);
	/* result value is stored in the variable */
	int32_t result = day_of_year(year,month,day);

	if(result != -1){
		printf("days of year is %d\n",result);
	}
}
void call_month_day(){
	int32_t year,yearday,month,day;
        
	/*taking user input*/
	printf("Enter year:");
        scanf(" %d",&year);
	printf("Enter yearday:");
        scanf(" %d",&yearday);
	/*month and day returns */
	month_day(year,yearday,&month,&day);
	if(month != -1 && day != -1){
		printf("month:%d | days:%d\n",month,day);
	}
}


static char daytab[2][13] = { 
 	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, 
 	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} 
 	};

int32_t day_of_year(int32_t year, int32_t month, int32_t day){
	int32_t i,leap;
	leap = (year%4 == 0 && year%100 != 0) || (year%400 == 0);
	/* month and year valdition */
	if(month < 1 || month >12 || year < 0){
		printf("Error invalid input\n");
		return -1;
	}
	/*day validation*/
	if (day < 1 || day > daytab[leap][month]){
		printf("Error: day must be valid\n");
		return -1;
	}
	
	for(i = 1;i<month;i++){
		day+= daytab[leap][i];
	}
	return day;
}


void month_day(int year, int yearday, int *pmonth, int *pday)
 {
 	int i, leap;
 	leap = (year%4 == 0 && year%100 != 0) || (year%400 == 0);
 	/* year and yearday validation */
	if(year < 0 || yearday < 0 || yearday > 365){
                printf("Error invalid input\n");
		*pmonth = -1;
		*pday = -1;
                return ;
        }

	for (i = 1; yearday > daytab[leap][i]; i++)
 		yearday -= daytab[leap][i];
 	*pmonth = i;
 	*pday = yearday;
 }
