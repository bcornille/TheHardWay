#include <stdio.h>

int main(int argc, char const *argv[])
{
	int areas[] = {10, 12, 13, 14, 20};
	char name[] = "Brian";
	char full_name[] = {
		'B', 'r', 'i', 'a', 'n',
		' ', 'S', '.', ' ',
		'C', 'o', 'r', 'n', 'i', 'l', 'l', 'e', '\0'
	};

	// Warning:  On some systems you may have to change the
	// %ld in this code to a %u since it will use unsigned ints.
	printf("The size of an int: %ld\n", sizeof(int));
	printf("The size of areas (int[]): %ld\n", sizeof(areas));
	printf("The number of ints in areas: %ld\n",
		sizeof(areas) / sizeof(int));
	printf("The first area is %d; the 2nd is %d.\n",
		areas[0], areas[1]);

	areas[0] = 100;
	areas[1] = 120;

	printf("Now:\n");
	printf("the first area is %d; the 2nd is %d.\n",
		areas[0], areas[1]);

	printf("The size of a char: %ld\n", sizeof(char));
	printf("The size of name (char[]): %ld\n", sizeof(name));
	printf("The number of chars: %ld\n",
		sizeof(name) / sizeof(char));

	printf("The size of full_name (char[]): %ld\n",
		sizeof(full_name));
	printf("The number of chars: %ld\n",
		sizeof(full_name) / sizeof(char));

	printf("name=\"%s\" and full_name=\"%s\"\n",
		name, full_name);

	name[2] = 'y';
	full_name[6] = 'T';

	printf("Changed my name to:\n");
	printf("name=\"%s\" and full_name=\"%s\"\n",
		name, full_name);

	return 0;
}