#include <iostream>
#include <thread>
#include<chrono>
#include <cstdio>

void clrscr()
{
	// ANSI转义序列清屏，适用于大多数现代终端
	std::cout << "\033[2J\033[1;1H";
}
void LeftShift(char*A) {
	char B[10];
	char temp = A[0];
	for (int i = 1; i < 8; i++) {
		
		B[i-1] = A[i];
	}
	B[7] = temp;
	for (int i = 0; i < 8; i++) {
		A[i] = B[i];
	}
}
int main() {
	char A[] = { 'H','E','L','L','O','-','-','-'};
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 8; j++) {
			printf("%c", A[j]);
		}
		LeftShift(A);
		std::this_thread::sleep_for(std::chrono::seconds(1));
		clrscr();
	}
	return 0;

}