#include <stdlib.h>
#include "ex22.h"
#include "dbg.h"

const char *MY_NAME = "Brian S. Cornille";

void scope_demo(int count)
{
	log_info("count is: %d", count);

	if(count > 10) {
		int count = 100; // BAD! BUGS!

		log_info("count in this scope is %d", count);
	}

	log_info("count after conditional exit: %d", count);

	count = 3000;

	log_info("count after assign: %d", count);

	/*
	 * This line would cause a stack overflow due to recursive call of scope_demo.
	scope_demo(count);
	*/
}

int main(int argc, char *argv[])
{
	// Test out THE_AGE accessors.
	log_info("My name is %s, age: %d", MY_NAME, get_age());

	set_age(100);

	log_info("My age is now: %d", get_age());

	/*
	 * This file does not have access to THE_AGE so these lines will not compile.
	THE_AGE = 1;

	log_info("My age is now: %d", get_age());
	*/

	// This uses a pointer to get at THE_AGE. This is not a good idea...
	int *age_ptr = get_age_ptr();
	*age_ptr = 1;
	log_info("My age is now: %d", get_age());

	// Test out THE_SIZE extern.
	log_info("THE_SIZE is: %d", THE_SIZE);
	print_size();

	THE_SIZE = 9;

	log_info("THE_SIZE is now: %d", THE_SIZE);
	print_size();

	// Test the raio function static.
	log_info("Ratio at first: %f", update_ratio(2.0));
	log_info("Ratio again: %f", update_ratio(10.0));
	log_info("Ratio once more: %f", update_ratio(300.0));

	// Test the scope demo.
	int count = 4;
	scope_demo(count);
	scope_demo(count*20);

	log_info("count after calling scope_demo: %d", count);

	return 0;
}
