#include <stdio.h>

int main(int arg, char *argv[])
{
	int distance = 110;
	float power = 2.345f;
	double super_power = 56789.4532;
	char initial = 'S';
	char first_name[] = "Brian";
	char last_name[] = "Cornille";

	printf("You are %d miles away.\n", distance);
	printf("You are %o miles away.\n", distance);
	printf("You are %X miles away.\n", distance);
	printf("You have %f levels of power.\n", power);
	printf("You have %f awesome super powers.\n", super_power);
	printf("You have %A awesome super powers.\n", super_power);
	printf("You have %p awesome super powers.\n", &super_power);
	printf("I have an initial %c.\n", initial);
	printf("I have a first name %s.\n", first_name);
	printf("I have a last name %s.\n", last_name);
	printf("My whole name is %s %c. %s.\n",
			first_name, initial, last_name);

	return 0;
}
