/* Author: Bhavik Parekh
 * Created: 
 * Modified:27/05/2025
 *
 * This header is updated to apply the patch for adding ownership of file and License
 */
#include<stdio.h>
#include<stdlib.h>
#include"library.h"


int main(){
	printf("this statement is to see that the patch is applied properly in runqemu\n");
	int inumber,iposition,input1,input2;

	char input[9];

	printf("enter the value of first binary string:");
	fgets(input,32,stdin);
	input1 = strtoul(input,NULL,2);

	printf("\nenter the value of second binary string:");
	fgets(input,32,stdin);
	input2 = strtoul(input,NULL,2);

	printf("\nenter the value of position you want to change the binary string:");
	scanf("%d",&iposition);

	printf("\nenter the value of the number of bits you want to change from the position given:");
	scanf("%d",&inumber);


	setbit(input1,inumber,iposition,input2);
	return 0;

}

void setbit(int x,int inumber,int iposition, int y){

	int mask;
	//long long output;
	mask= (((1<<inumber)-1)<<iposition);
	printf("\noutput bit string:%d\n",x);
	int variable1,variable2,variable3;

	printf("\nmask:%d\n",mask);
	printf("\n!mask:%d\n",~mask);
	y&=mask;
	x&=~mask;
	x|=y;
	printf("\noutput bit string:%d\n",x);
	binary(x);



}

void binary(int decimal){


	int index;
	for(index=15;index>=0;--index){
		int binary= (decimal >> index) & 1;
		printf("%d",binary);
	}
	printf("\n");


}
