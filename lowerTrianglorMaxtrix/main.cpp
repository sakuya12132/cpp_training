#include<iostream>
#include <stdlib.h>
using namespace std;
struct Maxtrix{
	int n;
	int *A;
};
void Set(struct Maxtrix *m,int i, int j, int n) {
	if (i >= j) {
		m->A[m->n*(j-1)+(j-2) * (j - 1) / 2+i-j] = n;
	}
	
		
	

}
int Get(struct Maxtrix m,int i, int j) {
	if (i >= j) {
		return m.A[m.n * (j - 1) + (j - 2) * (j - 1) / 2 + i - j];
	}
	else {
		return 0;
	}
	
}
void Display(struct Maxtrix m) {
	int i, j;
	for (i = 1; i <= m.n; i++) {
		for (j = 1; j <= m.n; j++) {
			if (i >= j) {
				printf("%d ",m.A[m.n * (j - 1) + (j - 2) * (j - 1) / 2 + i - j]);
			}
			else {
				printf("0 ");
			}
		}
		printf("\n");
	}
}
int main() {
	struct Maxtrix m;
	int i, j, x;
	printf("Enter Dimension:");
	scanf_s("%d", &m.n);
	m.A = (int*)malloc(m.n * (m.n + 1) / 2 * sizeof(int));
	
	printf("Enter all elements\n");
	for (i = 1; i <= m.n; i++) {
		for (j = 1; j <= m.n; j++) {
			scanf_s("%d", &x);
			Set(&m, i, j, x);
		}
	}
	printf("\n\n");
	Display(m);
	return 0;
}

