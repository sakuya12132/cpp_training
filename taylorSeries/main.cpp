#include <iostream>
class fun {
public:
	int e(int x, int n) {
		static int p = 1, b = 1;
		int r;
		if (n == 0) {
			return 1;
		}
		else {
			r = e(x, n - 1);
			p = p * x;
			b = b * n;
			return r + p / b;
		}
	}
};
int main() {
	fun a;
	int c = a.e(3, 5);
	printf("%d", c);
}
