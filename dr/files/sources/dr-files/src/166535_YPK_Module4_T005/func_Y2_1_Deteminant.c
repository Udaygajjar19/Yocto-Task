/* REQUIRED HEADERS */

#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include<stdlib.h>
#include "main.h"

/* REQUIRED MARCOS */
#define MAXLINE 1000



void call_determinant(){
	int32_t *matrix1=NULL,matrix_size;
	
	getchar();

	printf("---------------Enter matrix size: ");
        scanf("%d",&matrix_size);

	printf("---------------Matrix------------------\n");
	/*taking user input matrix*/
	user_matrix(&matrix1,matrix_size);
	
	/*displaying the matrix*/
	display_matrix(matrix1,matrix_size);
	/*calling the main determinant function*/
	int32_t det = determinant(matrix1, matrix_size);
    	printf("Determinant of the matrix: %d\n", det);

	free(matrix1);
}

int32_t determinant(int32_t *matrix,int32_t size){
	if (size == 1) {
    		return matrix[0]; /* Base case: 1x1 matrix*/
   	}
    	if (size == 2) {
        	/* Base case: 2x2 matrix determinant formula: ad - bc*/
        	return (matrix[0] * matrix[3]) - (matrix[1] * matrix[2]);
    	}

	int32_t det = 0,sign = 1;
	/* Allocating memory for submatrix*/
	int32_t *submatrix = (int32_t *)calloc((size - 1) * (size - 1), sizeof(int32_t));
	/* first loop is to multiple the first row of matrix with submatrix determinate */
	for(int32_t index=0;index<size;index++){
		int32_t sub_row=0,sub_col=0;
		/*iterating on loop over the other to create a submatrix and passing it recursively*/
		for(int32_t row = 1;row<size;row++){
			for(int32_t col = 0; col < size; col++){
				if(col == index) continue;
				/* allocating value to the submatrix */
				submatrix[sub_row * (size-1) + sub_col] = matrix[row * size + col];

				sub_col++;

				if(sub_col == (size -1)){
					sub_row++;
					sub_col = 0;
				}
			}
		}
	/* determinant value calculation using the recursively */
	det += sign * matrix[index] * determinant(submatrix,size-1);
	/* Alternating the sign */
	sign = -sign;
	}
	
	free(submatrix);
	return det;

}


void user_matrix(int32_t **matrix,int32_t size){
	*matrix = (int32_t *)calloc(size*size,sizeof(int32_t));
	printf("Enter 2D array: \n");
	for(int32_t row =0;row<size;row++){
		for(int32_t col =0;col<size;col++){
			printf("array[%d][%d] = ",row,col);
			scanf("%d",(*matrix) + (row*size+col));
		}
	}
	//free(matrix);
}




void display_matrix(int32_t *matrix,int32_t size){
	printf("Entered matrix:\n");
        for(int32_t row =0;row<size;row++){
                for(int32_t col =0;col<size;col++){
                        printf("%5d",matrix[ row * size + col]);
                }
		printf("\n"); 
        }
}
