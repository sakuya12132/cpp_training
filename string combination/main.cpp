#include <iostream>
//±©¡¶À„∑®
void Permute(char* c,int k) {
	static int n[10] = {0};
	static char a[10];
	int i;
	if (c[k] == '\0') {
		a[k] = '\0';
		printf("%s\n",a);
	}
	else {
		for (i = 0; c[i] != '\0'; i++) {
			if (n[i] == 0) {
				a[k] = c[i];
				n[i] = 1;
				Permute(c, k + 1);
				n[i] = 0;
			}
		}
	}
	

	
}
int main() {
	char c[] = "ABC";
	Permute(c, 0);
}