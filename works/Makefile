C := gcc
CFLAGS := -g -Wall -Wextra

checkBrackets : main.o func.o stack.o
	$(CC) -o $@ main.o func.o stack.o

main.o : main.c
	$(CC) -c $*.c

func.o : func.c stack.h
	$(CC) -c $*.c
stack.o : stack.c stack.h
	$(CC) -c $*.c
clean:
	rm checkBrackets main.o stack.o func.o
