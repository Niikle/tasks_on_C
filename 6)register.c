#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STR_BUFFER 32
#define MAX_NUM 5

int main(){
	printf("Enter your login:\t");
	char login[STR_BUFFER];
	scanf("%s", &login);
	
	bool flag = true;
	int i = 0;
	while(flag){
		char filename[8] = "";
    	snprintf(filename, sizeof(filename), "%d", i);
		i++;
		if(i > MAX_NUM) break;

		strcat(filename, ".txt");
		FILE *file = fopen(filename, "r");
		
		if(file == NULL) break;
		
		char get_data[STR_BUFFER] = "";
		while (fgets(get_data, sizeof(get_data), file)) {
			char* get_login = strtok(get_data, " ");
			char* get_pass = strtok(NULL, " ");

			if(strcmp(login, get_login) == 0){
				flag = false;

				printf("Enter your password:\t");
				char password[STR_BUFFER];
				scanf("%s", &password);

				if(strcmp(password, get_pass) == 0){
					printf("\nSuccessfully enter!\n\n");
				}
				else{
					printf("\nWrond password!\n\n");
				}
				return 0;
			}
    	}
		fclose(file);
	}
	printf("\nWrond login!\n\n");

	return 0;
}
