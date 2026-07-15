#include <iostream>
struct Array{
	int A[10];
	int Length;
	int size;
};

void display(Array arr) {
	for (int i = 0; i < (arr.Length)-1; i++) {
		printf("%d\n",(arr.A[i]));
	}
	
}
int get(Array arr, int index) {
	return arr.A[index];
}
void set(Array* arr, int index, int n) {
	(*arr).A[index] = n;
}
int sum(Array arr) {
	int total = 0;
	for (int i = 0; i < arr.Length - 1; i++) {
		total += arr.A[i];
	}
	return total;
}
int avg(Array arr) {
	return sum(arr) / arr.Length;
}
int main() {
	Array arr = { {12,32,44,5,1,3,7,9}, 8, 10 };
	set(&arr, 2, 21);

	display(arr);
	printf("total:%d\n", sum(arr));
	printf("avg:%d", avg(arr));
	return 0;
}