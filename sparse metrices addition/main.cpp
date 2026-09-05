#include <iostream>

struct Sparse {
	int m;
	int n;
	int num;
	struct Element* ele;
};

struct Element {
	int i;
	int j;
	int x;
};
void create(struct Sparse * s1) {
	int x;
	printf("输入维度:\n");
	std::cin >> s1->m;
	std::cin >> s1->n;
	printf("输入非零元素的数量");
	std::cin >> s1->num;
	if (s1->num > 0)
	{
		s1->ele = (struct Element*)malloc((s1->num) * sizeof(struct Element));
		if (s1->ele == NULL)
		{
			fprintf(stderr, "内存分配失败！\n");
			exit(1);
		}
	}
	else
	{
		s1->ele = NULL;
	}
	
	
	for (int i = 1;i<=s1->num;i++)
	{
		printf("输入第%d个非零元素的行 列 值: ", i);
		std::cin >> s1->ele[i-1].i >> s1->ele[i - 1].j >> s1->ele[i - 1].x;

	}
}
void dispaly(struct Sparse s1)
{	
	printf("这个矩阵是:\n");
	int i = 0;
	for (int x = 0; x < s1.m; x++)
	{
		for (int y = 0; y < s1.n; y++)
		{
			if  (i < s1.num && x == s1.ele[i].i && y == s1.ele[i].j)
			{
				std::cout << s1.ele[i].x << " ";
				i++;
			}
			else
			{
				std::cout << "0 ";
			}
		}
		std::cout << std::endl;
	}
}


struct Sparse* add(struct Sparse* s1, struct Sparse* s2) {
	if (s1->m != s2->m || s1->n != s2->n)
	{
		return 0;
	}
	struct Sparse* sum;
	int i, j, k;
	i = j = k = 0;

	sum = (struct Sparse*)malloc(sizeof(struct Sparse));
	if (sum == NULL)
	{
		fprintf(stderr, "内存分配失败！\n");
		exit(1);
	}
	sum->ele = (struct Element*)malloc((s1->num + s2->num) * sizeof(struct Element));
	if (sum->ele == NULL)
	{
		fprintf(stderr, "内存分配失败！\n");
		free(sum);
		exit(1);
	}
	while (i < s1->num && j < s2->num) {
		if (s1->ele[i].i < s2->ele[j].i)
			sum->ele[k++] = s1->ele[i++];
		else if (s1->ele[i].i > s2->ele[j].i)
			sum->ele[k++] = s2->ele[j++];
		else
		{
			if (s1->ele[i].j < s2->ele[j].j)
				sum->ele[k++] = s1->ele[i++];
			else if (s1->ele[i].j > s2->ele[j].j)
				sum->ele[k++] = s2->ele[j++];
			else
			{
				sum->ele[k] = s1->ele[i];
				sum->ele[k++].x = s1->ele[i++].x + s2->ele[j++].x;
			}


		}
	}
	for (; i < s1->num; i++)sum->ele[k++] = s1->ele[i];
	for (; j < s2->num; j++)sum->ele[k++] = s2->ele[j];
	sum->m = s1->m;
	sum->n = s2->n;
	sum->num = k;
	return sum;
}

int main() {
	struct Sparse s1,s2;
	struct Sparse * s3;
	create(&s1);
	
	create(&s2);
	s3 = add(&s1, &s2);
	dispaly(s1);
	dispaly(s2);
	dispaly(*s3); 
	return 0;
}