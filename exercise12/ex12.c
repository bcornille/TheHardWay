#include <stdio.h>

int main(int argc, char *argv[])
{
	int i = 0;

	if(argc == 1) {
		printf("You don't have an argument. You suck.\n");
	} else if(argc > 1 && argc < 7) {
		printf("Here's your arguments:\n");

		for(i = 1; i < argc; i++) {
			printf("%s ", argv[i]);
		}
		printf("\n");
	} else {
		printf("You have too many arguments. You suck.\n");
	}

	return 0;
}	
