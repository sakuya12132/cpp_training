#include <iostream>

class sumOfNumber {
public:
	int count = 0;
	int sum() {
		
		int n;
		std::cin >> n;
		if (n == 0) {
			
		}
		else {
			count++;
		}
		
		return n;
	}

};
int main() {
	sumOfNumber sum;
	int total = 0;
	int num;
	while (1) {

		num = sum.sum();
		if (num == 0) {
			std::cout << sum.count << "个自然数相加的总数是" << total;
			break;
		}
		else {
			total += num;
		}
	}
}