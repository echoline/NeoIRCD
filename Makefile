ALL=avl.o hash.o test

all: ${ALL}

test: avl.o hash.o test.cpp
	g++ -o test test.cpp avl.o hash.o -g

avl.o: avl.c avl.h

hash.o: hash.c hash.h

clean:
	rm -f *.o test
