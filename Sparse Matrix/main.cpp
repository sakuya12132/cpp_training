#include<iostream>
#include<stdlib.h>
struct Element {
	int i;
	int j;
	int x;
};
struct Sparse {
	int m;
	int n;
	int num;
	struct Element* e;
};
void Create(struct Sparse *s)
{
	int i;
	printf("Enter Dimension:");
	scanf("%d%d",& s->m, &s->n);
	printf("Enter num of bernon-zero");
	scanf("%d",&s->num);
	s->e = new Element[s->num];
	printf("Enter all elements:");
	for (i = 0; i < s->num; i++)
	{
		scanf("%d%d%d", s->e[i].i, s->e[i].j, s->e[i].x);
	}
}
int main() {
	struct Sparse s;
	Create(&s);
}