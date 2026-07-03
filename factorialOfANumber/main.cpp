#include <iostream>

class fun {
public:
	
	int func(int n) {
		if (n == 0) {
			return 1;
		}
		else {
			return func(n - 1) * n;
		}
		
		
		
	}
	

};
int main() {
	
	fun r;
	int b;
	b = r.func(5);
	printf("%d", b);

}