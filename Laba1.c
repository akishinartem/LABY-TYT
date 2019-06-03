#include <stdio.h>
void main() {
	int V1 = 0;
	int V2 = 0;
	int V = 0;
	int T = 0;
	int S = 0;

	printf("V1 = ");
	scanf("%d", &V1);
	printf("V2 = ");
	scanf("%d", &V2);
	printf("T = ");
	scanf("%d", &T);

	V = V1 + V2;
	S = T * V;

	printf("distance = %d\n", S);
}
