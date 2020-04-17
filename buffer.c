#include "buffer.h"

void bufferInit(Buffer *b)
{
	b->buffer = 0;
	b->printCheck = 0;
	b->outBits = 8;
}

void setOutBits(Buffer *b, uint16_t n)
{
	b->outBits = n;
}

void pushToBuffer(Buffer *b, uint16_t c, FILE *f)
{
	for(int i = 0; i < b->outBits; i++)
	{
		b->buffer = b->buffer << 1;
		uint16_t newbit = c >> (b->outBits - i - 1);
		newbit = newbit & 1;
		b->buffer = b->buffer | newbit;
		checkOut(b, f);
	}
}

void checkOut(Buffer *b, FILE *f)
{
	if(++b->printCheck < 16)
		;
	else
	{
		//output buffer
		fwrite(&(b->buffer), sizeof(b->buffer), 1, f);
		b->printCheck = 0;
		b->buffer = 0;
	}
}

void forceOut(Buffer *b, FILE *f)
{
	b->buffer = b->buffer << (16 - b->printCheck);
	b->printCheck = 15;
	checkOut(b, f);
}
