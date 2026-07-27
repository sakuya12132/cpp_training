#include<iostream>
void Sreach(char *c) {
	long int h = 0, x = 0;
	int i;
	for (i = 0; c[i] != '\0'; i++) {
		x = 1;
		x = x << (c[i] - 97);
		if ((x & h) > 0) {
			printf("%cÊÇÖØ¸´×Ö·û\n", c[i]);
		}
		else {
			h = h | x;
		}
	}
}


int main(){
	
	char C[] = "findingwdsawg";
	Sreach(C);
}