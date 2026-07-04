#include <iostream>
class TowerOfHanoi {
public:
	int TOH(int n, int A, int B, int C) {
		if (n == 0) {
			return 0;
		}
		TOH(n - 1, A, C, B);
		printf("(%d,%d)", A, C);
		TOH(n - 1, B, A, C);
		return 0;
	}
};
int main() {
	TowerOfHanoi r;
	r.TOH(3, 1, 2, 3);
	return 0;
}