#include <stdio.h>
void main() {
	int massive[10];
	int i;
	int chetnie = 0;
	int nechetnie = 0;

	for (i = 0; i < 10; i++) {
		scanf("%d", &massive[i]);
	}
	
	for (i = 0; i < 10; i += 2) {
		chetnie = chetnie + massive[i];
	}
	
	for (i = 1; i < 10; i += 2) {
		nechetnie = nechetnie + massive[i];
	}
	
	if (nechetnie < chetnie) {
		for (i = 1; i < 10; i += 2) {
			massive[i] = 0;
		}	
	}
	else {
		for (i = 0; i < 10; i += 2) {
			massive[i] = 0;
		}
	}
	
	printf("chetnie:%d, nechetnie:%d \n", chetnie, nechetnie);
	
	for (i = 0; i < 10; i++) {
		printf("%d ", massive[i]);
	}
}
