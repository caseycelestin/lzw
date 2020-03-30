CC = gcc
CFLAGS = -g -Wall -pedantic

all: lzw

lzw: main.o fileIO.o
	$(CC) $(CFLAGS) -fsanitize=address -fno-omit-frame-pointer -o lzw main.c fileIO.o

fileIO.o: fileIO.c fileIO.h
	$(CC) $(CFLAGS) -c fileIO.c

