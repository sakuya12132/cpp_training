#include <iostream>
#include <stdlib.h>
struct matrix {
	int rows;
	int cols;
	double* data;
};
void Set(struct matrix* m, int r, int c, double n) {
	if (r < 1 || r > m->rows || c < 1 || c > m->cols) {
		return;
	}
	m->data[(r - 1) * m->rows + (c - 1)] = n;
};

void Display(struct matrix m) {
	int i,j;
	for (i = 0; i < m.cols; i++) {
		for (j = 0; j < m.rows; j++) {
			printf("%.0lf ", m.data[i*m.rows+j]);
		}
		printf("\n");
	}
}

int main() {
	matrix mat;
	mat.rows = 3;
	mat.cols = 3;
	mat.data = (double*)malloc(mat.rows * mat.cols * sizeof(double));
	for (int i = 0; i < mat.cols*mat.rows; i++) {
		mat.data[i] = 0;
	}
	Set(&mat, 1, 1, 35); Set(&mat, 1, 2, 21); Set(&mat, 3, 3, 44);
	Display(mat);
}