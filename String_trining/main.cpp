#include<iostream>
int main() {
	char A[10];
	A[0] = 'h'; A[1] = 'e'; A[2] = 'l';
	A[3] = 'l'; A[4] = 'o'; A[5] = '\0'; A[6] = 'l';
	for (int i = 0; A[i] != '\0'; i++) {
		printf("%c", A[i]);
	}
	
}