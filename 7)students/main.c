#include <stdio.h>
#include <stdlib.h>
#include "student.h"

#define STR_BUFFER 64
#define MENU_POINTS 2

static void strip_newline(char *str) {
    if (!str) return;
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

bool good_input(int *count){
	if (scanf("%d", count) <= 0) {
		fprintf(stderr, "Invalid count\n");
		return false;
	}
	return true;
}

void print_all_from_select_data(char* data, int select){
	bool flag_can_read = true;
	int i = 0;
	while(flag_can_read){
		i++;
		char filename[STR_BUFFER] = {0};
    	snprintf(filename, sizeof(filename), "%d.txt", i);

    	FILE *file = fopen(filename, "r");
    	if (!file) {
        	fprintf(stderr, "The end of searching\n", filename);
        	return;
    	}
		
		char id_str[STR_BUFFER] = {0};
	    char age_str[STR_BUFFER] = {0};
		char curs_str[STR_BUFFER] = {0};
	    char name_str[STR_BUFFER] = {0};
		if (!fgets(id_str, sizeof(id_str), file)) { fclose(file); return; }
	    if (!fgets(age_str, sizeof(age_str), file)) { fclose(file); return; }
		if (!fgets(curs_str, sizeof(curs_str), file)) { fclose(file); return; }
	    if (!fgets(name_str, sizeof(name_str), file)) { fclose(file); return; }
	    fclose(file);

	    strip_newline(id_str);
		strip_newline(age_str);
		strip_newline(curs_str);
		strip_newline(name_str);

		if(select == 1){
			if(strcmp(data, id_str)) continue;
		}
		else if(select == 2){
			if(strcmp(data, age_str)) continue;
		}
		else if(select == 3){
			if(strcmp(data, curs_str)) continue;
		}
		else if(select == 4){
			if(strcmp(data, name_str)) continue;
		}
		
		Student* student = createNull();
		read(student, i);
		show(student);
		destroy(student);

	}
}

int main(void) {
	bool flag_no_break = true;
	while(flag_no_break){
		int menu_point;

		printf("Enter your choise:\n");
		printf("1) save student\n");
		printf("2) find student\n");
		printf("3) show all students\n");
		printf("4) exit\n");

		if(!good_input(&menu_point)) return 1;
		system("cls");

		switch(menu_point){
		case 1:
			printf("Enter count of students to add\n");
			int count_students;
			if(!good_input(&count_students)) return 1;
			system("cls");

		    Student** sArr = malloc(sizeof(Student*) * count_students);
		    if (!sArr) {
		        fprintf(stderr, "Failed to allocate array of pointers\n");
		        return 1;
		    }


		    for (int i = 0; i < count_students; ++i) {
		        Student* s = entered();
					system("cls");
		        if (!s) {
		            fprintf(stderr, "Failed to create student %d\n", i);
		            for (int j = 0; j < i; ++j) destroy(sArr[j]);
		            free(sArr);
		            return 1;
		        }
		        sArr[i] = s;
		    }


			for (int i = 0; i < count_students; ++i) {
		        registered(sArr[i]);
		    }

		    for (int i = 0; i < count_students; ++i) {
		        destroy(sArr[i]);
		        sArr[i] = NULL;
		    }
		    free(sArr);
		    sArr = NULL;


			break;
		case 2:
			printf("Enter type of data to find the student\n");
			printf("1) id\n");
			printf("2) age\n");
			printf("3) curs\n");
			printf("4) name\n");

			int type_of_data;
		    if(!good_input(&type_of_data)) return 1;
			system("cls");

			char str[STR_BUFFER];
			switch(type_of_data){
			case 1:
				printf("Enter id:\n");
				int id_to_find;
				if(!good_input(&id_to_find)) return 1;

    			_itoa(id_to_find, str, 10);
				print_all_from_select_data(str, type_of_data);

				break;
			case 2:
				printf("Enter age:\t");
				int age_to_find;
				if(!good_input(&age_to_find)) return 1;

    			_itoa(age_to_find, str, 10);
				print_all_from_select_data(str, type_of_data);

				break;
			case 3:
				printf("Enter curs:\t");
				int curs_to_find;
				if(!good_input(&curs_to_find)) return 1;

    			_itoa(curs_to_find, str, 10);
				print_all_from_select_data(str, type_of_data);

				break;
			case 4:
				printf("Enter name:\t");
				char name_to_find[STR_BUFFER];
				if (!scanf("%63s", name_to_find)) return 1;

				print_all_from_select_data(name_to_find, type_of_data);
			
				break;
			}

			break;
		case 3:
			print_all_from_select_data("", 0);
			break;
		case 4:
			flag_no_break = false;
			break;
		}
	}

    return 0;
}
