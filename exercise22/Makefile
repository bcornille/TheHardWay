CFLAGS= -Wall -g -DNDEBUG

default: ex22_main

ex22_main: ex22.o

ex22_main.c: ex22.o

ex22.o: ex22.h dbg.h

all:
	cd ../; make

clean:
	rm -f ex22_main ex22.o
