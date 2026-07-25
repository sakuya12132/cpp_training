#include <iostream>
#include <cstring>
void vowels_num(char *a,int & vcount,int &ccount){
	char  b[] = "aeiouAEIOU";
	vcount = 0;
	ccount = 0;
	bool isVowel = false;
	int len = strlen(a);
	for (int j = 0; j < len; j++) {
		isVowel = false;
		for (int i = 0; i < 10; i++) {
			if (a[j] == b[i]) {
				isVowel = true;
			}
		}
		if (isVowel) {
			vcount++;
		}
		else if (a[j] >= 65 && a[j] <= 90 || a[j] >= 97 && a[j] <= 122) {
			ccount++;
			}
	}
	
}

void display(char a) {
	printf("%c", a);
}
int main() {
	char a[] = "how ArE you";
	int v = 0, c = 0;
	vowels_num(a, v, c);
	printf("ÔªÒôÊý%d£¬¸¨ÒôÊý%d", v,c);
}