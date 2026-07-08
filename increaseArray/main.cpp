#include <iostream>
#include<stdlib.h>
int main() {
	int* p, *q;
	p = (int*)malloc(5 * (sizeof(int)));
	p[0] = 3;p[1] = 5;p[2] = 7;p[3] = 9;p[4] = 11;
	q = (int*)malloc(10 * sizeof(int));
	for (int i = 0;i < 5;i++) {
		q[i] = p[i];
	}
	free(p);//将p指向的那块数组释放
	p = q;//将q的指向的地址复制给p，现在两个指针指向同一个地方
	q = NULL;//将q变为空指针
	for (int i =0;i < 5;i++) {
		printf("%d\n", p[i]);
	}
	return 0;
}