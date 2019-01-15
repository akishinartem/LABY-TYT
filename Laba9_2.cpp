#include <stdio.h>
void main(void)
{
	FILE *fpin;
	FILE *fpout;

	int N = 1;
	int i = 1;
	char ptr;

	fpin = fopen("test.txt", "r");
	fpout = fopen("result.txt", "w");

	while ((ptr = fgetc(fpin)) != EOF)
	{
		if (ptr == '_' || ptr == '.' || ptr == ',')
			i++;

		if (i == N){
			do
				ptr = fgetc(fpin);
			while (ptr != '_');
			i++;
		}

		if (ptr == '\n')
			i = 1;
		fprintf(fpout, "%c", ptr);
	}

	fclose(fpin);
	fclose(fpout);
