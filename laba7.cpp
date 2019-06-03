#include <stdio.h>
#define MASK 0x00000001
#define MASK2 0x80000000

int main() {
	unsigned long int N = 0, N1 = 0, N2 = 0, C1 = 0, C2 = 0;
	int k1 = 0, k2 = 0, i = 0, ii = 0, i1 = 0;

	printf("N = ");
	scanf("%lx", &N);

	N1 = N;
	N2 = N;
	
	for (i = 1; i < 33; ++i) {
		for (i1 = 0; i1 < i; ++i1) {
			C1 = N1 & MASK;
			if (C1 != 0) {
				k1++;
			}
		}
		N1 >>= 1;
		
		for (ii = 1; ii < (33 - i); ++ii) {
			C2 = N2 & MASK2;
			if (C2 != 0) {
				k2++;
			}
			N2 <<= 1;
		}
	}
	
	if (k1 == k2) {
		printf("result: %d\n", i);
		N1 = N;
		N2 = N;
		k1 = 0;
		k2 = 0;
	}
}
