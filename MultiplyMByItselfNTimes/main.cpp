#include <iostream>

class fun {
public:
	int func(int m,int n) {
		if (n == 0) {
			return 1;
		}
		else {
			return func(m, n - 1)* m;
		}
		

	}


};
int main() {
	fun r;
	int a = r.func(2, 3);
	printf("%d", a);
}