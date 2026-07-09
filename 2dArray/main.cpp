#include<iostream>
#include<stdlib.h>
int main() {
	int** A;
	int i, n;
	A = (int**)malloc(3 * sizeof(int*));
	A[0] = (int*)malloc(4 * sizeof(int));
	A[1] = (int*)malloc(4 * sizeof(int));
	A[2] = (int*)malloc(4 * sizeof(int));
	
	for (i = 0; i < 3; i++) {
		for (n = 0; n < 4; n++) {
			printf("%d", A[i][n]);
		}
		printf("\n");
	}
	for (i = 0; i < 3; i++) {
		free(A[i]);
	}
	free(A);
	return 0;
}
  