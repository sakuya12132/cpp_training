// C 风格实现：使用 malloc/realloc/free，并通过指针的指针修改调用者的指针
#include <stdio.h>
#include <stdlib.h>

// p_ptr: 指向数组指针的指针，old_count: 原长度，add_count: 要增加的长度
// 返回新的长度（失败时返回 old_count，且 *p_ptr 保持不变）
int addSize(int **p_ptr, int old_count, int add_count) {
	if (p_ptr == NULL) return old_count;
	int new_count = old_count + add_count;
	// 注意乘法优先级，并使用 realloc 简化实现
	int *q = (int *)realloc(*p_ptr, new_count * sizeof(int));
	if (q == NULL) {
		// 分配失败，保持原有指针不变
		return old_count;
	}
	// 初始化新扩展区域（可选）
	for (int i = old_count; i < new_count; ++i) q[i] = 0;
	*p_ptr = q;
	return new_count;
}

int main() {
	int old_count = 5;
	int add_count = 5;
	int *p = (int *)malloc(old_count * sizeof(int));
	if (p == NULL) return 1;
	p[0] = 1;
	p[1] = 3;
	for (int i = 2; i < old_count; ++i) p[i] = 0;

	int new_count = addSize(&p, old_count, add_count);

	for (int c = 0; c < new_count; ++c) {
		printf("%d ", p[c]);
	}
	printf("\n");

	free(p);
	return 0;
}
