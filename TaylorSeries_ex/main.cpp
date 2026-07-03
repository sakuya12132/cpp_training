#include <iostream>
class fun {
public:
	double fun1(int n,int m) {
		if (n == 0) {
			return 1;
		}
		else {

			return fun1(n - 1, m) + (1.0 / fun2(n)) * fun3(m, n);
		}
	}
	double fun2(int n) {
		if (n == 0) {
			return 1;

		}
		else {
			return fun2(n - 1) * n;
		}
	}
	double fun3(int m,int n) {
		if (n == 0) {
			return 1;
		}
		else {
			return fun3(m, n - 1) * m;
		}
	}

};
int main() {
	fun r;
	double a = r.fun1(5,3);
	printf("%f", a);

}