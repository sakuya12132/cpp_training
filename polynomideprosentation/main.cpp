#include<iostream>

struct team {
	int coe;
	int exp;
};

struct poly {
	int n;
	team* t; // 修改为指针类型
};

int main() {
	poly p;
	printf("输入想要的项数:");
	if (scanf_s("%d", &p.n) != 1) {
		printf("输入无效，程序终止。\n");
		return 1;
	}
	p.t = new team[p.n]; // 分配内存
	for (int i = 0; i < p.n; i++) {
		printf("输入第%d个系数和指数\n",i+1);
		std::cin >> p.t[i].coe >> p.t[i].exp;

	}
	for (int j = 0; j < p.n; j++) {
		printf("%dx%d", p.t[j].coe, p.t[j].exp);
		if (j < p.n - 1) {
			printf("+");
		}
		
		
		
	}
	// 建议后续释放内存
	delete[] p.t;
}