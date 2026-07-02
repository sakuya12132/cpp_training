#include <iostream>

class sum {
public:
	int count = 0;
	int fun(int last_n) {
		int n;
		std::cin >> n;
		if (n == 0) {
			return last_n;
		}
		else {
			count++;
		}
		
		fun(last_n + n);
	}

};
int main() {
	sum sum;
	int a = sum.fun(0);
	std::cout << sum.count << "个自然数的总数是" << a;

}