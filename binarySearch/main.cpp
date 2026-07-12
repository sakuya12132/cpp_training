#include<iostream>

int Search(int A[],int target, int l, int h) {
	
	if (l > h) {
		printf("未找到该元素");
		return -1;
	}
	int mid = (l + h) / 2;
	if (target > A[mid]) {
		return Search(A, target, mid + 1, h);
	}
	else if (target < A[mid]) {
		return Search(A, target, l, mid-1);
	}
	else {
		printf("%d在%d的位置", target, mid);
		return A[mid];
	}
	
	
	
};
int main() {
	int A[] = { 2,4,5,7,8,9,12,32,44,66,77,88 };
	int b = Search(A,31,0,11);
	return 0;
}