#include <string.h>
#include <stdio.h> 
#include <stdlib.h> 

#define YES 1
#define NO 0
#define MAXLEN 1000 
#define NLINES 100

int main(void)
{
	char str[32];
	FILE *f;
	char* strs;
	int count = 0, i, j;
	system("chcp 1251");
	system("cls");
	if ((f = fopen("test.txt", "r")) == NULL)
	{
		return 1;
	}
	strs = (char*)malloc(sizeof(char)*MAXLEN*NLINES);
	while (!feof(f))
	{
		fgets(strs + count++ * MAXLEN, MAXLEN, f);
	}
	fclose(f);
	for (i = 1; i < count; i++)
	{
		for (j = 0; j < count - i; j++)
		{
			if (strcmp(strs + j * MAXLEN, strs + (j + 1) * MAXLEN) > 0)
			{
				strcpy(str, strs + j * MAXLEN);
				strcpy(strs + j * MAXLEN, strs + (j + 1) * MAXLEN);
				strcpy(strs + (j + 1) * MAXLEN, str);
			}
		}
	}
	for (i = 0; i < count; i++)
	{
		printf("%s", strs + i * MAXLEN);
	}
	system("pause");
	return 0;
}
