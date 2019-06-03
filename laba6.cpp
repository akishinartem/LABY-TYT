#include <stdio.h>
#define N 3
#define K 5

void main() {
	int x[N][K], i, ii1, ii2, j, min = 9999, max = -9999;
	
	for (i = 0; i < N; ++i) {
		for (j = 0; j < K; ++j) {
			scanf("%d", &x[i][j]);
		}
	}
	
	for (i = 0; i < N; ++i) {
		for (j = 0; j < K; ++j) {
			if (x[i][j] <= min) {
				min = x[i][j];
				ii1 = i;
			}
			if (x[i][j] >= max) {
				max = x[i][j];
				ii2 = i;
			}
		}
		if (ii1 != ii2) {
			ii1 = -1;
			ii2 = -2;
		}
	}
	
	if (ii1 == ii2) {
		for (i = 0; i < N; ++i) {
			for (j = 0; j < K; ++j) {
				if (i != ii1) {
					x[i][j] = 0;
				}
			}
		}
	}
	
	for (i = 0; i < N; ++i) {
		for (j = 0; j < K; ++j) {
			printf("%4d ", x[i][j]);
		}
	}
	printf("\n");
}
