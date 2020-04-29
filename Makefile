CC=g++

heapmake: heap.o
	CC -o heap.out heap.o
