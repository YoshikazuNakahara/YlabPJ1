C := gcc
CFLAGS := -g3 -O0 -Wall -Wextra

checkKeywords : main.o checkKeywords.o stack.o
	$(CC) -o $@ main.o checkKeywords.o stack.o

main.o : main.c
	$(CC) -c $*.c

checkKeywords.o : checkKeywords.c stack.h
	$(CC) -c $*.c
stack.o : stack.c
	$(CC) -c $*.c
clean:
	rm checkKeywords main.o stack.o checkKeywords.o
