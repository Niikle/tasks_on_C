#include <stdio.h>
#include <malloc.h>

int fact(int a){
	if(a == 1) return 1;
	return a * fact(a - 1);
}

int step(int a, int b){
	int res = 1;
	for(int i = 0; i < b; ++i){
		res *= a;
	}
	return res;
}

int main(){	
	int size;
	scanf("%d", &size);
	int* arr = (int*)malloc(size * sizeof(int));
	for(int i = 0; i < size; ++i){
		scanf("%d", &arr[i]);
	}

	for(int i = 0; i < size; ++i){
		printf("%d\t", arr[i]);
	}
	printf("\n");

	//double a, b;
	int select1, select2;
	scanf("%d", &select1);
	scanf("%d", &select2);
	select1--;
	select2--;

	printf("You select:\t%d\t%d\n", arr[select1], arr[select2]);

	printf("Sum:\t%d\n", arr[select1] + arr[select2]);
	printf("Subt:\t%d\n", arr[select1] - arr[select2]);
	printf("Mult:\t%d\n", arr[select1] * arr[select2]);
	printf("Div:\t%f\n", arr[select1] / arr[select2]);

	printf("Fac:\t%d\n", fact(arr[select1]));
	printf("Deg:\t%d\n", step(arr[select1], arr[select2]));

	printf("Rem:\t%d\n", arr[select1] % arr[select2]);
	printf("Size:\t%d\n", sizeof(arr[select1]));

	free(arr);
	return 0;
}

