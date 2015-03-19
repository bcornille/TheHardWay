#include <stdio.h>

int main(int argc, char const *argv[])
{
	int numbers[4] = {1};
	char name[6] = "Brian";

	// First, print them out raw.
	printf("numbers: %d %d %d %d\n",
		numbers[0], numbers[1],
		numbers[2], numbers[3]);

	printf("name each: %c %c %c %c %c %c\n",
		name[0], name[1],
		name[2], name[3],
		name[4], name[5]);

	// Setup the numbers.
	numbers[0] = 1;
	numbers[1] = 2;
	numbers[2] = 'A';
	numbers[3] = 4;

	// Setup the name.
	name[0] = 'B';
	name[1] = 'r';
	name[2] = 'i';
	name[3] = 'a';
	name[4] = 'n';
	name[5] = '\0';

	// Then print them out initialized.
	printf("numbers: %d %d %c %d\n",
		numbers[0], numbers[1],
		numbers[2], numbers[3]);

	printf("name each: %c %c %c %c %c %c\n",
		name[0], name[1],
		name[2], name[3],
		name[4], name[5]);

	// Print the name like a string.
	printf("name: %s\n", name);

	// Another way to use name
	char *another = "Brian S. Cornille";

	printf("another: %s\n", another);

	printf("another each: %c %c %c %c %c %c\n",
		another[0], another[1],
		another[2], another[3],
		another[4], another[5]);

	int another_size = sizeof(another);

	printf("Size of another: %d\n", another_size);

	return 0;
}