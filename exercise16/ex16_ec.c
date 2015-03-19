#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person {
	char *name;
	int age;
	int height;
	int weight;
	int grade;
};

struct Person Person_create(char *name, int age, int height, int weight, int grade)
{
	struct Person who;

	who.name = strdup(name);
	who.age = age;
	who.height = height;
	who.weight = weight;
	who.grade = grade;

	return who;
}

void Person_destroy(struct Person who)
{
	free(who.name);
}

void Person_print(struct Person who)
{
	printf("Name: %s\n", who.name);
	printf("\tAge: %d\n", who.age);
	printf("\tHeight: %d\n", who.height);
	printf("\tWeight: %d\n", who.weight);
	printf("\tGrade: %d\n", who.grade);
}

int main(int argc, char *argv[])
{
	// Make two people structures.
	struct Person joe = Person_create(
			"Joe Alexander Buffington Catapillar Maxwellington Farmer", 32, 64, 140, 95);

	struct Person frank = Person_create(
			"Frank Blank", 20, 72, 180, 67);

	printf("The size of struct Person is %zu.\n", sizeof(struct Person));
	printf("The size of char *name is %zu.\n", sizeof(joe.name));

	// Print them out and where they are in memory.
	printf("Joe is at memory location %p:\n", &joe);
	Person_print(joe);
	printf("Joe's name is at memory location %p:\n", joe.name);
	printf("Joe's name points from memory location %p:\n", &(joe.name));
	printf("Joe's age is at memory location %p:\n", &(joe.age));
	printf("Joe's height is at memory location %p:\n", &(joe.height));
	printf("Joe's weight is at memory location %p:\n", &(joe.weight));
	printf("Joe's grade is at memory location %p:\n", &(joe.grade));

	printf("Frank is at memory location %p:\n", &frank);
	Person_print(frank);

	// Make everyone age 20 years and pring them again.
	joe.age += 20;
	joe.height -= 2;
	joe.weight += 40;
	Person_print(joe);

	frank.age += 20;
	frank.weight += 20;
	Person_print(frank);

	// Destroy them both so we clean up.
	Person_destroy(joe);
	Person_destroy(frank);

	return 0;
}
