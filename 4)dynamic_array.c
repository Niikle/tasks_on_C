#include <stdio.h>
#include <malloc.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void show_array(int* array, int size){
	for(int i = 0; i < size; ++i){
		printf("%d\t", array[i]);
	}
	printf("\n");
}

int* bubble_sort(int* array, int size){
	int* array_new = (int*)malloc(size * sizeof(int));
	
	for(int i = 0; i < size; ++i){
		array_new[i] = array[i];
	}

	for(int i = 0; i < size; ++i){
		for(int j = 0; j < size - i - 1; ++j){
			if(array_new[j] > array_new[j + 1]){
				swap(&array_new[j], &array_new[j + 1]);
			}
		}
	}

	return array_new;
}

int main(){
	int size;
	scanf("%d", &size);
	int* array = (int*)malloc(size * sizeof(int));

	for(int i = 0; i < size; ++i){
		scanf("%d", &array[i]);
	}

	printf("\nYour array:\n");
	show_array(array, size);

	int* array_sorted = bubble_sort(array, size);

	printf("\nModified array:\n");
	show_array(array_sorted, size);
	
	free(array_sorted);
	free(array);
	return 0;
}
