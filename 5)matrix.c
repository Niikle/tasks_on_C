#include <stdio.h>
#include <stdlib.h>

int determinant(int** array, int rows, int cols);
int** get_minor(int** array, int n, int skip_row, int skip_col);

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

int** create_matrix(int rows, int cols){
    int** array = malloc(rows * sizeof(int*));
    for(int i = 0; i < rows; ++i){
        array[i] = malloc(cols * sizeof(int));
    }
    return array;
}

void destroy_matrix(int** array, int rows){
    for(int i = 0; i < rows; ++i){
        free(array[i]);
    }
    free(array);
}

int** get_minor(int** array, int n, int skip_row, int skip_col){
    int** minor = create_matrix(n - 1, n - 1);
    int mi = 0;
    for(int i = 0; i < n; ++i){
        if(i == skip_row) continue;
        int mj = 0;
        for(int j = 0; j < n; ++j){
            if(j == skip_col) continue;
            minor[mi][mj] = array[i][j];
            ++mj;
        }
        ++mi;
    }
    return minor;
}

int determinant(int** array, int rows, int cols){
	if(rows != cols) return 0;
    if(rows == 1) return array[0][0];
    if(rows == 2) return array[0][0] * array[1][1] - array[0][1] * array[1][0];

    int n = rows;
    int det = 0, sign = 1;

    for(int j = 0; j < n; ++j){
        if(array[0][j] == 0){
            sign = -sign;
            continue;
        }
        int** minor = get_minor(array, n, 0, j);
        det += sign * array[0][j] * determinant(minor, n - 1, n - 1);
        destroy_matrix(minor, n - 1);
        sign = -sign;
    }

    return det;
}

int main(){
    int rows, cols;
    printf("Enter count rows and cols:\t");
    scanf("%d%d", &rows, &cols);
    printf("\n");

    int** array = create_matrix(rows, cols);

    printf("Input matrix:\n");
    input_matrix(array, rows, cols);
    printf("\nYour matrix:\n");
    print_matrix(array, rows, cols);
    printf("\nThe determinant of matrix:\n");
    printf("%d\n\n", determinant(array, rows, cols));

    destroy_matrix(array, rows);

    return 0;
}
