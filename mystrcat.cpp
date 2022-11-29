#include <iostream>
#include <string>
using namespace std;

char* mystrcat(const char* str1, const char* str2);

int main() {
	char* str = mystrcat("Hello!", "World!");
	cout << str << endl;
}

char* mystrcat(const char* str1, const char* str2) {
	size_t len1 = strlen(str1);
	size_t len2 = strlen(str2);

	char* newStr = new char[len1 + len2 +1];

	for (int i = 0; i < len1 && i < len2; i++) {
		if (i < len1)
			newStr[i] = str1[i];
		if (i < len2)
			newStr[len1 + i] = str2[i];
	}

	newStr[len1 + len2] = '\0';

	return newStr;
}
