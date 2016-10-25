
#Makefile for HW3   (Had to rewrite some of it myself)

default: prog test

cirListDeque.o: cirListDeque.c cirListDeque.h
	gcc -Wall -g -std=c99 -c cirListDeque.c	

testCirListDeque.o: cirListDeque.h testCirListDeque.c
	gcc -Wall -g -std=c99 -c testCirListDeque.c

prog: cirListDeque.o testCirListDeque.o
	gcc -Wall -g -std=c99 -o prog cirListDeque.o testCirListDeque.o

test: testLinkedList.o linkedList.o
	gcc -g -Wall -std=c99 -o test testLinkedList.o linkedList.o
clean:
	#rm cirListDeque.o
	#rm testCirListDeque.o
	rm testLinkedList.o
	rm linkedList.o
	
testLinkedList.o: testLinkedList.c linkedList.h
	gcc -g -Wall -std=c99 -c testLinkedList.c

linkedList.o: linkedList.c linkedList.h
	gcc -g -Wall -std=c99 -c linkedList.c
