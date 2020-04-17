#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "encode.h"
#include "fileIO.h"
#include "buffer.h"



void encode(char *argv[])
{
	Node dictionary;
	dictInit(&dictionary);

	Buffer b;
	bufferInit(&b, 16);

	uint16_t code = 128;

	FILE *inFile = fopen(argv[1], "r");
	FILE *outBinFile = fopen("outBin", "wb");
	FILE *outIntFile = fopen("outInt", "w");
	
	int prefixChar = fgetc(inFile);
	Node *prefixNode = &dictionary.children[prefixChar];

	int nextChar;
	while((nextChar = fgetc(inFile)) != EOF)
	{
		Node *nextNode = isChild(prefixNode, nextChar);
		if(nextNode != 0)
			prefixNode = nextNode;
		else
		{
			pushToBuffer(&b, prefixNode->code, outBinFile);	
			fprintf(outIntFile,"%u ", prefixNode->code);
			addChild(prefixNode, nextChar, code++);
			prefixNode = &dictionary.children[nextChar];
		}	
	}
	pushToBuffer(&b, prefixNode->code, outBinFile);	
	forceOut(&b, outBinFile);
// 	fwrite(&prefixNode->code, sizeof(prefixNode->code), 1, outBinFile);
	fprintf(outIntFile,"%u\n", prefixNode->code);
	

	//dictPrint(&dictionary);
	
//	printf("TABLE SIZE = %lu\n", code);

	dictFree(&dictionary);
	fclose(inFile);
	fclose(outBinFile);
	fclose(outIntFile);
}

int main(int argc, char *argv[])
{
	//openOriginal(&fp, argc, argv);


	encode(argv);
	

	//printNodes(&dictionary);	

}

