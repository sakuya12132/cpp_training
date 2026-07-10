#include<iostream>
//数组结构体
struct Data {
	int A[10];
	int size;
	int Length;

};
//展示
void Display(struct Data data) {
	int i;
	for (i = 0; i < data.Length; i++) {
		printf("%d\n", data.A[i]);
	}
}
//插入
void Insert(struct Data *data,int index,int n) {
	int i;
	for (i = (*data).Length; i > index; i--) {
		(*data).A[i] = (*data).A[i - 1];
	}
	(*data).A[index] = n;
}
//删除
void Delete(struct Data *data, int index) {
	int i;
	for (i = index; i < (*data).Length - 1; i++) {
		(*data).A[i] = (*data).A[i + 1];
	}
	(*data).Length--;
}
//在末尾添加
void Add(struct Data *data,int n) {
	(*data).Length++;
	(*data).A[(*data).Length-1] = n;
}
int main() {
    Data data;
    data.A[0] = 12; data.A[1] = 11; data.A[2] = 13; data.A[3] = 4;
    data.Length = 4;
    data.size = 10;
	Add(&data, 8);
	Insert(&data, 2, 432);
	Display(data);
}