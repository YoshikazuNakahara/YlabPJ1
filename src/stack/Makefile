CC := gcc
CFLAGS := -g3 -O0 -Wall -Wextra

test : test.o stack.o
	$(CC) -o $@ test.o stack.o

test.o : test.c
	$(CC) $(CFLAGS) -c $*.c

stack.o : stack.c
	$(CC) $(CFLAGS) -DTEST -c $*.c
clean:
	rm test.o stack.o
