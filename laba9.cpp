#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define YES	1
#define NO	0
#define MAXLINE	1000

int main(void)
{
	FILE *fpin;
	FILE *fpout;
	char line[MAXLINE];
	char *ptr;
	char *begin;
	char *end;
	char *src;
	char *dst;
	int N;
	int i = 0;
	int flag = NO;
	if (!(fpin = fopen("test.txt", "r"))) return 1;
	if (!(fpout = fopen("result.txt", "w"))) return 1;
	printf("N = ");
	scanf("%d", &N);

	while (ptr = fgets(line, sizeof(line), fpin))
	{
		i = 0;
		begin = ptr;
		while (*ptr != '\0')
		{
			if (!((*ptr >= 'a' && *ptr <= 'z') || (*ptr >= 'A' && *ptr <= 'Z') || (*ptr >= '0' && *ptr <= '9')))
			{
				if (flag == YES)
				{
					end = ptr - 1;
					if (i == N)
					{
						src = end + 1;
						dst = begin;
						while ((*dst++ = *src++) != '\0');
						ptr = begin;
					}
				}
				flag = NO;
			}
			else
			{
				if (!flag)
				{
					i++;
					begin = ptr;
				}
				flag = YES;
			}
			ptr++;
		}
	fputs(line, fpout);
	}
}
