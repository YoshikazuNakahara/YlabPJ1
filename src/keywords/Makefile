CC := gcc
CFLAGS := -g3 -O0 -Wall -Wextra

test: test.o checkKeywords.o
	$(CC) -o $@ test.o checkKeywords.o
test.o : test.c
	$(CC) $(CFLAGS) -c $*.c
checkKeywords.o : checkKeywords.c
	$(CC) $(CFLAGS) -c $*.c
clean:
	rm checkKeywords test.o  checkKeywords.o
