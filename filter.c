#include <stdlib.h>
#include <stdio.h>
#include <str.h>
int main(int argn, char* args[])
{
	FILE *fptr1 = fopen(".slures.txt", "rb");
	char slures[100000];
	fill(slures, 100000);
	fread(slures, 100000 - 1, 1, fptr1);
	fclose(fptr1);
	FILE *fptr2 = fopen(".negs.txt", "rb");
	char negs[100000];
	fill(negs, 100000);
	fread(negs, 100000 - 1, 1, fptr2);
	fclose(fptr2);
	FILE *fptr3 = fopen(".replacements.txt", "rb");
	char replacements[400000];
	fill(replacements, 400000);
	fread(replacements, 400000 - 1, 1, fptr3);
	return checkwords(args[1], slures, negs, replacements);
}