#include <iostream>
class pascal{
public:
	int fun(int n) {
		if (n == 0) {
			return 1;
		}
		else {
			return fun(n - 1) * n;
		}
	}
	int nrc(int n, int r) {
		int num, den;
		num = fun(n);
		den = fun(r) * fun(n - r);
		return num/den ;
	}
	int NCR(int n, int r) {
		if ((r == 0) or (n == r)) {
			return 1;
		}
		return nrc(n - 1, r - 1) + nrc(n - 1, r);
	}

};
int main() {
	pascal r;
	int a = r.NCR(4, 2);
	printf("%d", a);
}