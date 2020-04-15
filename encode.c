#include <stdio.h>
#include <stdlib.h>

#include "encode.h"
#include "fileIO.h"



void encode(char *argv[])
{
	Node dictionary;
	dictInit(&dictionary);

	unsigned long int code = 128;

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
			fwrite(&prefixNode->code, sizeof(prefixNode->code), 1, outBinFile);
			fprintf(outIntFile,"%u ", prefixNode->code);
			addChild(prefixNode, nextChar, code++);
			prefixNode = &dictionary.children[nextChar];
		}	
	}
	fwrite(&prefixNode->code, sizeof(prefixNode->code), 1, outBinFile);
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

