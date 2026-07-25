#include <iostream> 
bool verify(char *A) {
	//第一次写不小心把A[i] != '\0'写成了i != '\0'
	for (int i = 0; A[i] != '\0'; i++) {
		if (A[i] < 48 || A[i]>57 && A[i] < 65 || A[i]>90 && A[i] < 97 || A[i]>122) {
			return false;
		}
	}
	return true;
}


int main() {
	char A[] = "adsw??*123";
	bool b = verify(A);
	printf("%d", b);
}