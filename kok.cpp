#include <stdio.h>
#include <string.h>
#include <windows.h>
#define LETTER 1
#define NOT_THE_LETTER 0
#define MAXLEN 1000

int main(void)
{
	HANDLE hStdout; // дескриптор консольного окна
	FILE *fp; // входной файл
	char line[MAXLEN]; // строчка из файла
	char word[MAXLEN];// слово
	char mass[30][100] = { "auto","continue","break","case","char","default","do","double","else","enum","extern","float","for","goto","if","int","long","register","return","short","signed","sizeof","static","struct","switch","typedef","union","unsigned","void","while" };
	int i,j;
	int flag1;
	int flag; // флаг слово/разделитель
	int prev_flag; // предыдущее значение флага
	char *ptr; // указатель на строчку
	WORD foregroundColor; // цвет символа
	WORD backgroundColor; // цвет фона
	WORD textAttribute; // атрибут текста - цвет символа и фона

	// Получить стандартный дескриптор
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	// определить цвета символов, разделителей и фона
	foregroundColor = FOREGROUND_INTENSITY | FOREGROUND_BLUE;
	backgroundColor = BACKGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED;
	// открыть файл для чтения
	fp = fopen("test.txt", "rt");
	if (fp == NULL)
		return 1; // ошибка при открытии файла

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
			prev_flag = flag; // запомнить флаг
			if (*ptr == ' ' || *ptr == ',' || *ptr == '.' || *ptr == '\n' || *ptr == ';' || *ptr == '\t')
				flag = NOT_THE_LETTER;
			else
				flag = LETTER;
			if (flag != prev_flag)
			{
				word[i] = '\0'; // закрыть слово
				if (prev_flag)
				{
					for (j = 0; j < 30; j++)
					{
						if (!strcmp(word, mass[j]))
						{
							flag1 = 1;// Найдено слово в массиве
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
				printf("%s", word); // вывести слово
				i = 0; // начать новое слово
			}
			word[i++] = *ptr++; // запомнить символ
		}
	}
	if (i != 0)
	{
		word[i] = '\0'; // закрыть слово
		for (j = 0; j < 30; j++)
		{
			if (!strcmp(word, mass[j]))
			{
				flag1 = 1;// Найдено слово в массиве
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
		printf("%s", word); // вывести слово
	}
	printf("\n");
	// белые символы, черный фон
	SetConsoleTextAttribute(hStdout, 7);
	system("pause");
	return 0;
}