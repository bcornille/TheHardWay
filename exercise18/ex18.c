#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/** Our old friend die from ex17. */
void die(const char *message)
{
	if(errno) {
		perror(message);
	} else {
		printf("ERROR: %s\n", message);
	}

	exit(1);
}

// A typedef creates a fake type,
// in this case for a function pointer.
typedef int (*compare_cb)(int a, int b);
typedef int *(*sort_cb)(int *numbers, int count, compare_cb cmp);

/**
 * A classic buble sort function that uses
 * the compare_cv to do the sorting.
 */
int *bubble_sort(int *numbers, int count, compare_cb cmp)
{
	int temp = 0;
	int i = 0;
	int j = 0;
	int *target = malloc(count*sizeof(int));

	if(!target) die("Memory allocation error.");

	memcpy(target, numbers, count*sizeof(int));

	for(i = 0; i < count; i++) {
		for(j = 0; j < count - 1; j++) {
			if(cmp(target[j], target[j+1]) > 0) {
				temp = target[j+1];
				target[j+1] = target[j];
				target[j] = temp;
			}
		}
	}

	return target;
}

/**
 * The comb sort.
 * It is a slight improvment over the bubble sort.
 */
int *comb_sort(int *numbers, int count, compare_cb cmp)
{
	int temp = 0;
	int gap = count;
	int i = 0;
	float shrink = 1.3;
	int swapped = 0;
	int *target = malloc(count*sizeof(int));

	if(!target) die("Memory allocation error.");

	memcpy(target, numbers, count*sizeof(int));

	for(gap = count-1; ((gap > 1) || swapped); gap = (int)(gap/shrink)) {
		if(gap < 1) {
			gap = 1;
		}

		for(i = 0, swapped = 0; i + gap < count; i++) {
			if(cmp(target[i], target[i+gap]) > 0) {
				temp = target[i+gap];
				target[i+gap] = target[i];
				target[i] = temp;
				swapped = 1;
			}
		}
	}

	return target;
}

int sorted_order(int a, int b)
{
	return a - b;
}

int reverse_order(int a, int b)
{
	return b - a;
}

int strange_order(int a, int b)
{
	if(a==0 || b == 0) {
		return 0;
	} else {
		return a % b;
	}
}

/**
 * Used to test that we are sorting things correctly
 * by doing the sort and printing it out.
 */
void test_sorting(int *numbers, int count, sort_cb sort, compare_cb cmp)
{
	int i = 0;
	int *sorted = sort(numbers, count, cmp);

	if(!sorted) die("Failed to sort as requested.");

	for(i = 0; i < count; i++) {
		printf("%d ", sorted[i]);
	}
	printf("\n");

	free(sorted);

	/*
	 * This code prints the hex code of the sort function.
	unsigned char *data = (unsigned char *)cmp;

	for(i = 0; i < 25; i++) {
		printf("%02x:", data[i]);
	}
	printf("\n");
	*/
}

int main(int argc, char *argv[])
{
	if(argc < 2) die("USAGE: ex18 <list of numbers>");

	int count = argc - 1;
	int i = 0;
	char **inputs = argv + 1;

	int *numbers = malloc(count*sizeof(int));
	if(!numbers) die("Memory allocation error.");

	for(i = 0; i < count; i++) {
		numbers[i] = atoi(inputs[i]);
	}

	test_sorting(numbers, count, bubble_sort, sorted_order);
	test_sorting(numbers, count, bubble_sort, reverse_order);
	test_sorting(numbers, count, bubble_sort, strange_order);
	test_sorting(numbers, count, comb_sort, sorted_order);
	test_sorting(numbers, count, comb_sort, reverse_order);
	// test_sorting(numbers, count, die); // The compiler complains if wrong function provided.
	// test_sorting(numbers, count, NULL); // This line compiles, but leads to segmentation fault. :(

	free(numbers);

	return 0;
}
