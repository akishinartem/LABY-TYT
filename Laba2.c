#include  <stdio.h>
void main() {
	float a, s, x;
	int n, i, sign;

	printf("n=");
	scanf("%d", &n);
	printf("x=");
	scanf("%f", &x);

	s = 0;
	sign = 1;
	i = 1;
	a = x;

	while (i < n + 1) {
		s = s + (a / i * sign);
		sign = -sign;
		a = (a*x);
		i = i + 1;
	}
	printf("s = %f\n", s);
}
