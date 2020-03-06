trout: trout.h trout.c util.c
	gcc -o trout trout.c util.c main.c
	
main: main.c trout.c util.c trout.h util.h
	gcc -g -o main main.c trout.c util.c
