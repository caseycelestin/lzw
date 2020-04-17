CC = gcc
CFLAGS = -g -Wall -pedantic

all: encode

encode: encode.o fileIO.o struct.o buffer.o encode.h
	$(CC) $(CFLAGS) -fsanitize=address -fno-omit-frame-pointer -o encode encode.c fileIO.o struct.o buffer.o

fileIO.o: fileIO.c fileIO.h
	$(CC) $(CFLAGS) -c fileIO.c

struct.o: struct.c struct.h
	$(CC) $(CFLAGS) -c struct.c

buffer.o: buffer.c buffer.h
	$(CC) $(CFLAGS) -c buffer.c

