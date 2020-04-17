#ifndef __BUFFER_H__
#define __BUFFER_H__

#include <stdint.h>
#include <stdio.h>

typedef struct buffer {
	uint16_t buffer;
	unsigned short int outBits;
	unsigned short int printCheck;
} Buffer;

void bufferInit(Buffer *b, unsigned short int n);

void setOutBits(Buffer *b, unsigned short int n);

void pushToBuffer(Buffer *b, uint16_t c, FILE *f);

void checkOut(Buffer *b, FILE *f);

void forceOut(Buffer *b, FILE *f);

#endif
