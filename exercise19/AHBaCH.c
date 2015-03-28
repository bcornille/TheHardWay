#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "core.h"
#include <assert.h>

int Map_init(void *self)
{
	Map *map = self;

	// Make some rooms for a small map.
	Room *foyer = NEW(Room, "The Foyer");
	Room *hall = NEW(Room, "The Great Hall");
	Room *study = NEW(Room, "The Lord's Study");
	Room *library = NEW(Room, "The library, look at all the books.");
	Room *kitchen = NEW(Room, "Kitchen, something smells great.");
	Room *bed = NEW(Room, "The Master's Bedroom");

	// No bad guys here.

	// Setup the map rooms. Every room leads to 4 others...
	foyer->north = hall;
	foyer->south = bed;
	foyer->east = library;
	foyer->west = study;

	hall->north = kitchen;
	hall->south = foyer;
	hall->east = library;
	hall->west = study;

	kitchen->north = bed;
	kitchen->south = hall;
	kitchen->east = library;
	kitchen->west = study;

	bed->north = foyer;
	bed->south = kitchen;
	bed->east = library;
	bed->west = study;

	study->north = kitchen;
	study->south = foyer;
	study->east = hall;
	study->west = bed;

	library->north = kitchen;
	library->south = foyer;
	library->east = bed;
	library->west = hall;

	// Start the map and the character off in the hall.
	map->start = foyer;
	map->location = foyer;

	return 1;
}

Object MapProto = {
	.init = Map_init,
	.move = Map_move,
	.attack = Map_attack
};

int main(int argc, char *argv[])
{
	// Simple way to setup the randomness.
	srand(time(NULL));

	// Make our map to work with.
	Map *game = NEW(Map, "The Crooked House.\n"
			"There's something strange about it..");

	game->_(describe)(game);
	printf("You enter the ");
	game->location->_(describe)(game->location);

	while(process_input(game)) {
	}

	return 0;
 }
