CC = gcc
CFLAGS = -Wall -std=c99
Main: main.o memManager.o memHelper.o
	$(CC) $(CFLAGS) -o main main.o memManager.o memHelper.o -lm

main.o: main.c memManager.h memHelper.h
	$(CC) $(CFLAGS) -c main.c

memManager.o: memManager.c memManager.h
	$(CC) $(CFLAGS) -c memManager.c

memHelper: memHelper.c memHelper.h
	$(CC) $(CFLAGS) -c memHelper.c
