#include "buffer.h"

void bufferInit(Buffer *b, unsigned short int n)
{
	b->buffer = 0;
	b->printCheck = 0;
	b->outBits = n;
}

void setOutBits(Buffer *b, unsigned short int n)
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
	if(b->printCheck != 0)
	{
		b->buffer = b->buffer << (16 - b->printCheck);
		b->printCheck = 15;
		checkOut(b, f);
	}
}

int checkRefill(Buffer *b, FILE *f)
{
	if(b->printCheck++ == 0)
	{
		// refill buffer;
		if((fread(&b->buffer, sizeof(b->buffer), 1, f)) != 1)
			return -1;
	}

	if(b->printCheck == 16)
		b->printCheck = 0;

	return 1;
}

int getNextCode(uint16_t *o, Buffer *b, FILE *f)
{
	uint16_t out = 0;

	for(int i = 0; i < b->outBits; i++)
	{
		b->buffer = b->buffer << 1;
		if(checkRefill(b, f) == -1)
			return -1;
		out = out << 1;
		uint16_t newbit = b->buffer & 32768;
		newbit = newbit >> 15;
		out = out | newbit;
	}
	*o = out;

	return 1;

}
