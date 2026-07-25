#include <iostream>
int main() {
	char A[] = "python";
	char B[7]{};
	int i,j =0;
	for (i = 0; A[i] != '\0'; i++) {
		continue;
	}
	i -= 1;
	for (j = 0; i>=0; i--,j++) {
		B[j] = A[i];
	}
	
	B[j] = '\0';
 	printf("%s", B);
}