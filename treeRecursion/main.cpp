#include <iostream>
class func {
public:
	int a = 0;

	int fun(int n) {
		a++;
		if (n > 0) {
			
			printf("%d", n);
			fun(n - 1);
			fun(n - 1);
			
		}
		printf("\n当前a的值为%d\n", a);
		return 0;
	}
	

};




int main() {
	func func;
	func.fun(3);
	
	
	

}