#include <iostream>
struct Hashtable {
	int H[26];
};
void Finding(Hashtable *Hash,char *c) {
	int i,j;
	//≥ı ºªØ
	for (i = 0; i < 26; i++) {
		(*Hash).H[i] = 0;
	}
	
	for (j = 0; c[j] != '\0'; j++) {
		(*Hash).H[c[j] - 97] += 1;
	}
}

int main() {
	char C[] = "finding";
	struct Hashtable Hash;
	Finding(&Hash, C);
	for (int b = 0; b < 26; b++) {
		printf("%c:%d\n", b+97,Hash.H[b]);
	}
}