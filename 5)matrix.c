#include <stdio.h>
#include <malloc.h>

void input_matrix(int** array, int rows, int cols){
	for(int i = 0; i < rows; ++i){
		for(int j = 0; j < cols; ++j){
			scanf("%d", &array[i][j]);
		}
	}
}

void print_matrix(int** array, int rows, int cols){
	for(int i = 0; i < rows; ++i){
		for(int j = 0; j < cols; ++j){
			printf("%d\t", array[i][j]);
		}
		printf("\n");
	}
}

int calcualte_determinant(int** array, int rows, int cols){
	if(rows != cols) return 0;
	if(rows == 1) return array[0][0];
	if(rows == 2) return array[0][0] * array[1][1] - array[0][1] * array[1][0];
}

int main(){
	int rows, cols;
	printf("Enter count rows and cols:\t");
	scanf("%d%d", &rows, &cols);
	printf("\n");

	int** array = (int**)malloc(rows * sizeof(int*));
	for(int i = 0; i < rows; ++i){
		array[i] = (int*)malloc(cols * sizeof(int));
	}

	printf("Input matrix:\n");
	input_matrix(array, rows, cols);
	printf("\nYour matrix:\n");
	print_matrix(array, rows, cols);
	printf("\nThe determinant of matrix:\n");
	printf("%d\n\n", calcualte_determinant(array, rows, cols));


	for(int i = 0; i < rows; ++i){
		free(array[i]);
	}
	free(array);

	return 0;
}
