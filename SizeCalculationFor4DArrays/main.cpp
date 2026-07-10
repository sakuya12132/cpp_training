#include<iostream>
#include<stdlib.h>
struct Array {
	int* A;
	int size;
	int lengthl;
};
void Display(struct Array arr) {
	int i;
	printf("\n元素是:\n");
	for (i = 0, i < arr.lengthl, i++) {
		printf("%d", arr.A[i]);
	}
}
int main() {
	struct Array arr;
	int n,i;
	printf("输入数组大小：");
	scanf("%d", &arr.size);
	arr.A = (int*)malloc(arr.size * sizeof(int));
	arr.lengthl = 0;
	printf("输入数量:");
	scanf("%d",n);
	printf("输入所有元素:\n");
	for (i = 0; i < n; i++) {
		scanf("%d", &arr.A[i]);
	}
	arr.lengthl = n;
	Display(arr);
	return 0;
}