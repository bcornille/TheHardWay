#include <stdio.h>

int main(int argc, char *argv[])
{
	if(argc < 2) {
		printf("ERROR: You need at least one argument.\n");
		// This is how you abort a program.
		return 1;
	}

	int i = 0;
	int j = 1;
	char letter = argv[1][0];
	for(j = 1; j < argc; j++, i = 0) {
		for(letter = argv[j][0]; argv[j][i] != '\0'; i++, letter = argv[j][i]) {
			// char letter = argv[1][i];

			switch(letter) {
				case 'a':
				case 'A':
					printf("%d-%d: 'A'\n", j, i);
					break;

				case 'e':
				case 'E':
					printf("%d-%d: 'E'\n", j, i);
					break;

				case 'i':
				case 'I':
					printf("%d-%d: 'I'\n", j, i);
					break;

				case 'o':
				case 'O':
					printf("%d-%d: 'O'\n", j, i);
					break;

				case 'u':
				case 'U':
					printf("%d-%d: 'U'\n", j, i);
					break;

				case 'y':
				case 'Y':
					if(i > 2) {
						// It's only sometimes Y!
						printf("%d-%d: 'Y'\n", j, i);
						break;
					}

				default:
					printf("%d-%d: %c is not a vowel\n", j, i, letter);
			}
		}
	}

	return 0;
}
