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

void buble_sort(int* array, int size){
	for(int i = 0; i < size; ++i){
		for(int j = 0; j < size - i - 1; ++j){
			if(array[j] > array[j + 1]){
				swap(&array[j], &array[j + 1]);
			}
		}
	}
}

void quick_sort(int* array, int left, int right){
	if(left > right) return;

	int pivot = array[(left + right) / 2];
	int i = left;
	int j = right;

	while(i <= j){
		while(array[i] < pivot) i++;
		while(array[j] > pivot) j--;

		if(i <= j){
			swap(&array[i], &array[j]);
			i++;
			j--;
		}
	}
	quick_sort(array, left, j);
	quick_sort(array, i, right);
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

	//buble_sort(array, size);
	quick_sort(array, 0, size - 1);

	printf("\nSort array:\n");
	show_array(array, size);

	printf("\nMin:\t%d\n", array[0]);
	printf("Max:\t%d\n\n", array[size - 1]);

	free(array);
	return 0;
}
