#include <stdio.h>

#define YES 1
#define NO 0

void main() {
	char massive[1000];
	char c = ' ';
	int k;
	int i = 0;
	int g = 0;
	int s = 0;
	int flag = NO;
	int found = NO;

	while ((c = getchar()) != '\0') {
		massive[i] = c;
		if (c == 'A' || c == 'a' || c == 'E' || c == 'e' || c == 'I' || c == 'i' ||
			c == 'O' || c == 'o' || c == 'U' || c == 'u' || c == 'Y' || c == 'y') {
			g = g + 1;
			i = i + 1;
		}
		else if (c == ' ' || c == '\n') {
			if (g <= s) {
				for (k = 0; k < i; k++) {
					printf("%c", massive[k]);
				}
				printf(" ");
				g = 0;
				s = 0;
				i = 0;
			}
			else {
				g = 0;
				s = 0;
				i = 0;
			}
		}
		else {
			s++;
			i = i + 1;
		}
	}
}
