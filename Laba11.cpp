#include <stdio.h>
#include <string.h>
#include <windows.h>

#define LETTER 1
#define NOT_THE_LETTER 0
#define MAXLEN 1000

int main(void)
{
	HANDLE hStdout;
	FILE *fp;
	char line[MAXLEN];
	char word[MAXLEN];
	char mass[30][100] = { "auto","continue","break","case","char","default","do","double","else","enum","extern","float","for","goto","if","int","long","register","return","short","signed","sizeof","static","struct","switch","typedef","union","unsigned","void","while" };
	int i,j;
	int flag1;
	int flag;
	int prev_flag;
	char *ptr;
	WORD foregroundColor;
	WORD backgroundColor;
	WORD textAttribute;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	foregroundColor = FOREGROUND_INTENSITY | FOREGROUND_BLUE;
	backgroundColor = BACKGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED;
	fp = fopen("test.txt", "rt");
	if (fp == NULL)
		return 1;
	
	while (!feof(fp))
	{
		ptr = fgets(line, MAXLEN, fp);
		if (ptr == NULL)
			break;
		i = 0;
		prev_flag = flag = NOT_THE_LETTER;
		word[0] = '\0';
		while (*ptr != 0)
		{
			prev_flag = flag;
			if (*ptr == ' ' || *ptr == ',' || *ptr == '.' || *ptr == '\n' || *ptr == ';' || *ptr == '\t')
				flag = NOT_THE_LETTER;
			else
				flag = LETTER;
			if (flag != prev_flag)
			{
				word[i] = '\0';
				if (prev_flag)
				{
					for (j = 0; j < 30; j++)
					{
						if (!strcmp(word, mass[j]))
						{
							flag1 = 1;
						}
					}
				}
				if (flag1)
				{
					textAttribute = foregroundColor | backgroundColor;
					SetConsoleTextAttribute(hStdout, textAttribute);
					flag1 = 0;
				}
				else
				{
					SetConsoleTextAttribute(hStdout, 7);
				}
				printf("%s", word);
				i = 0;
			}
			word[i++] = *ptr++;
		}
	}
	if (i != 0)
	{
		word[i] = '\0';
		for (j = 0; j < 30; j++)
		{
			if (!strcmp(word, mass[j]))
			{
				flag1 = 1;
			}
		}
		if (flag1)
		{
			textAttribute = foregroundColor | backgroundColor;
			SetConsoleTextAttribute(hStdout, textAttribute);
			flag1 = 0;
		}
		else
		{
			SetConsoleTextAttribute(hStdout, 7);
		}
		printf("%s", word);
	}
	printf("\n");
	SetConsoleTextAttribute(hStdout, 7);
	system("pause");
	return 0;
}
