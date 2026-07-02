#include <iostream>

class sum {
public:
	int count = 0;
	int fun(int n) {
		count++;
		if (n == 0) {
			return 0;
		}
		else {
			int total = fun(n - 1) + n;
			return total;
		}
	}

};
int main() {
	sum sum;
	int a = sum.fun(5);
	std::cout << sum.count << "个自然数的总数是" << a;

}