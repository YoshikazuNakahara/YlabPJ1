C := gcc
CFLAGS := -g -Wall -Wextra

checkBrackets : main.o checkBrackets.o stack.o
	$(CC) -o $@ main.o checkBrackets.o stack.o

main.o : main.c
	$(CC) -c $*.c

checkBrackets.o : checkBrackets.c stack.h
	$(CC) -c $*.c
stack.o : stack.c stack.h
	$(CC) -c $*.c
clean:
	rm checkBrackets main.o stack.o checkBrackets.o
