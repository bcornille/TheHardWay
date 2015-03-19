#include <stdio.h>

int main(int argc, char *argv[])
{
	int bugs = 100;
	double bug_rate = 1.2;

	printf("You have %d bugs at the imaginary rate of %f.\n",
			bugs, bug_rate);

	long universe_of_defects = 32767L * 65536L * 65536L * 65536L;
	printf("The entire universe has %ld bugs.\n",
			universe_of_defects);

	double expected_bugs = bugs*bug_rate;
	printf("You are expected to have %f bugs.\n",
			expected_bugs);

	double part_of_universe = expected_bugs / universe_of_defects;
	printf("That is only a %e portion of the universe.\n",
			part_of_universe);

	// This makes no sense, just a demo of something weird.
	char nul_byte = '\0';
	int care_percentage = bugs * nul_byte;
	printf("Which means you shoul care %d%%.\n",
			care_percentage);

	printf("The null byte %s.\n",nul_byte);
	printf("The null byte %c.\n",nul_byte);
	printf("The null byte %d.\n",nul_byte);

	return 0;
}
