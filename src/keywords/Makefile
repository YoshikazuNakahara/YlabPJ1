CC := gcc
CFLAGS := -g3 -O0 -Wall -Wextra

test: test.o keywords.o stack.o
	$(CC) -o $@ test.o keywords.o stack.o
test.o : test.c
	$(CC) $(CFLAGS) -c $^
keywords.o : keywords.c
	$(CC) $(CFLAGS) -c $^
stack.o : ../stack/stack.c
	$(CC) $(CFLAGS) -c $^
clean:
	rm test test.o  keywords.o stack.o
