/* REQUIRED HEADERS */

#include<stdio.h>
#include<stdint.h>
#include "main.h"
#include<time.h>

/* REQUIRED MARCOS */
#define MAXLINE 1000
void call_binsearch(){
	while(1){	
		int8_t c;
		int32_t result,x,arr[MAXLINE]={2,6,1,4,3,5,42,3,7,52};
		double dTime1,dTime2;
		clock_t start,end,start1,end1;
		
		printf("Enter number -> ");
		scanf("%d",&x);
		arr_sort(arr,MAXLINE);
		/*calling the function*/
		start = clock();
		binsearch_old();
		end = clock();
		dTime1 = ((double) (end - start)) / CLOCKS_PER_SEC;

		start1= clock();
		result = binsearch(x,arr,MAXLINE);
		end1 = clock();
		dTime2=((double) (end1 - start1)) / CLOCKS_PER_SEC;
		
		printf("time taken by old binsearch -> %f\n",dTime1);
		printf("time taken by modified binsearch -> %f\n",dTime2);
		
		/*if value is -1 then not matched*/
		if(result == -1){
			printf("Not matched");
		}
		/*prints the index got matched*/
		else{
			printf("index: %d",result);
		}
		printf("\nEnter q to quit:");
                scanf(" %c", &c);
                if(c == 'q'){
                        break;
                }
	}
}


/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */ 
int32_t binsearch(int32_t x, int32_t v[], int32_t n) 
 { 
 	int32_t low, high, mid; 
	low = 0; 
	high = n - 1;
	/* runs till low is less then high*/
	while (low < high) { 
		
		/*making comparision with mid index*/
        	mid = (low+high)/2;
		
		/*value is greater then mid index value then low value is increased by mid*/	
		if (x > v[mid]) 
			low = mid + 1; 
		else 
			/*if x is less than mid then high is reduced to mid value*/
			high = mid; 
 	} 
	/*final check */
	return (v[low] == x) ? low : -1; /* no match */ 
 }


int binsearch_old()
{
uint32_t x = 3,v[4] = {1,2,3,4};
uint32_t n = 5;
uint32_t low, high, mid;
low = 0;
high = n - 1;
while (low <= high) {
mid = (low+high)/2;
if (x < v[mid])
high = mid - 1;
else if (x > v[mid])
low = mid + 1;
else 
{
         printf("%d\n",mid);
         return mid;
}
}
printf("%d",-1);
return -1; 
}




int32_t arr_sort(int32_t arr[],int32_t n){
	int32_t i,j,temp;
	for(i=0;i< (n-1);i++){
		for(j=0;j<(n-i-1);j++){
			if(arr[j] > arr[j+1] ){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	
	}
	return 0;
}


