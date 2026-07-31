#include<iostream>
using namespace std;
class Diagonal {
private :
	int n;
	int* A;
public:
	
	
	Diagonal(int n) {
		this->n = n;
		A = new int[n];
	}
	void Set(int i, int j, int n);
	int Get(int i, int j);
	void Display();
	~Diagonal() {
		delete[] A;
	}
};
void Diagonal::Set(int i, int j, int n) {
	if (i == j) {
		A[i - 1] = n;
	}
}
int Diagonal::Get(int i, int j) {
	if (i == j) {
		return A[i - 1];
	}
	else {
		return 0;
	}
}
void Diagonal::Display() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				printf("%d ", A[i]);
			}
			else {
				printf("0 ");
			}
			
		}
		printf("\n");
	}
}
int main() {
	Diagonal d(4);
	d.Set(1, 1, 12);
	d.Set(3, 3, 66);
	d.Set(2, 2, 32);
	d.Set(4, 4, 44);
	d.Display();
}

