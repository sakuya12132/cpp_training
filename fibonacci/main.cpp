#include <iostream>
#include <cstdio>
#include <cstring>
int F[11];
int fibonacci(int n) {
	if (n <= 1) {
		F[n] = n;
		return n;
	}
	else {
		if (F[n - 2] == -1) {
			F[n - 2] = fibonacci(n - 2);
		}
		if (F[n - 1] == -1) {
			F[n - 1] = fibonacci(n - 1);
		}
		return F[n - 2] + F[n - 1];
	}
	
	
}
int main() {
	memset(F, -1, sizeof(F));
	int a = fibonacci(7);
	printf("%d", a);

}