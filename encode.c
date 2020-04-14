#include <stdio.h>
#include <stdlib.h>

#include "encode.h"
#include "fileIO.h"



void encode()
{
	Node dictionary;
	dictInit(&dictionary);

	Node *test = &dictionary.children[120];
	addChild(test, '$');
	dictPrint(&dictionary);

	dictFree(&dictionary);
}

int main(int argc, char *argv[])
{
	//openOriginal(&fp, argc, argv);


	encode();
	

	//printNodes(&dictionary);	

}

