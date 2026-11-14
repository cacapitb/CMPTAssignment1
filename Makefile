#----------------------------------------
#Testing Document
#
#Author: Ben.C
#ID:3172656
#Lab/Lecture Instructor: Hanan S.
#----------------------------------------

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

.PHONY: clean, testOne testTwo testThree testFour testFive tar

clean:
	rm -f *.o main

testOne: Testing/test1input.txt Testing/correct1.txt
	./main <Testing/test1input.txt
	./main <Testing/test1input.txt>output1.txt
	diff output1.txt Testing/correct1.txt

testTwo: Testing/test2input.txt Testing/correct2.txt
	./main <Testing/test2input.txt
	./main <Testing/test2input.txt>output2.txt
	diff output2.txt Testing/correct2.txt

testThree: Testing/test3input.txt Testing/correct3.txt
	./main <Testing/test3input.txt
	./main <Testing/test3input.txt>output3.txt
	diff output3.txt Testing/correct3.txt

testFour: Testing/test4input.txt Testing/correct4.txt
	./main <Testing/test4input.txt
	./main <Testing/test4input.txt>output4.txt
	diff output4.txt Testing/correct4.txt

testFive: Testing/test5input.txt Testing/correct5.txt
	./main <Testing/test5input.txt
	./main <Testing/test5input.txt>output5.txt
	diff output5.txt Testing/correct5.txt

tar:
	tar -czvf A1BenC.tar.gc *.c *.h Makefile Testing/ design.txt