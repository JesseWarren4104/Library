CC = g++
CFLAGS = -g -Wall

default: test

test: book.o library.o main.o
	$(CC) $(CFlags) -o test book.o library.o main.o

book.o: book.cpp book.h
	$(CC) $(CFLAGS) -c book.cpp

library.o: library.cpp library.h
	$(CC) $(CFLAGS) -c library.cpp

main.o:	main.cpp library.h book.h
	$(CC) $(CFLAGS) -c main.cpp

clean:
	$(RM) test *.o *~
