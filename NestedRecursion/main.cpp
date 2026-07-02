#include <iostream>

class Nested {
public:
	int fun(int n) {
		if (n > 100) {
			return n - 10;

		}
		else {
			return fun(fun(n + 11));
		}
		
	}



};
int main() {
	Nested func;
	int a = func.fun(95);
	printf("%d", a);
}