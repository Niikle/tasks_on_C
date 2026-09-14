#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

void print_data(int data, bool is_bot_data){
	if(is_bot_data) printf("Бот отвечает:\t");
	else printf("Вы Выбрали:\t");
	switch(data){
	case 1:
		printf("Камень!\n");
		break;
	case 2:
		printf("Ножницы!\n");
		break;
	case 3:
		printf("Бумага!\n");
		break;
	}
}

bool is_win(int you_data, int rand_data){
	return (you_data == 1 && rand_data == 2) ||
		   (you_data == 2 && rand_data == 3) ||
		   (you_data == 3 && rand_data == 1);
}

int main(){
	setlocale(LC_ALL, "ru");

	int data, counter = 0;
	bool is_end = false;
	srand(time(0));

	while(!is_end){
		printf("Введите:\n1)Камень\n2)Ножницы\n3)Бумага\n");
		scanf("%d", &data);
		if(data < 1 || 3 < data) {
			printf("\nОшибка ввода: недопустимые данные\n");
			break;
		}
		int rand_data = rand() % 3 + 1;

		print_data(data, false);
		print_data(rand_data, true);

		if(data == rand_data) printf("Ничья!\n");
		else if(!is_win(data, rand_data)) printf("Вы проиграли!\n");
		else {
			printf("Вы выйграли!\n");
			counter++;
		}

		printf("Побед подряд:\t%d\n\n", counter);
	}
	printf("Гейм овер\n");
	printf("Вы вйграли %d раз подряд\n\n", counter);

	return 0;
}
