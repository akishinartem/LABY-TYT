#include <stdio.h> 
#define YES 1 
#define NO 0 

void main() {
	int c;
	int flag = NO;
	int cnt = 0;
	int s = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '.' || c == '\n' || c == ',' || c == '\0')	{
			if (flag == YES) {
				if (s % 2 != 0)	{
					cnt++;
				}
				s = 0;
			}
		}
		else {
			flag = YES;
			s = s + 1;
		}
	}
	printf("%d\n", cnt);
}
