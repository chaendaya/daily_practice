// 3. Find a string [Normal]
#include <iostream>
#include <string>
using namespace std;

string str1, str2;
bool checkFull(int i);
void findIndex();

int main() {

	cout << "string1 : ";
	getline(cin, str1);
	cout << "string2 : ";
	getline(cin, str2);

	findIndex();
}

bool checkFull(int i) {		// 찾은 str1 인덱스부터 str2 전체가 같은지 검사
	for (int j = 0; j < str2.length(); j++) {
		if (str1[i] == str2[j])
			i++;
		else
			return false;
	}
	return true;
}

void findIndex() {		// str1에서 str2의 첫글자와 같은 인덱스 찾기
	for (int i = 0; i < str1.length(); i++) {
		if (str1[i] == str2[0]) {	// str2의 첫글자가 발견되면
			if (checkFull(i) == true) {		// 전체 검사, true이면
				cout << i << endl;			// 처음 일치하는 인덱스 반환
				return;
			}
			else			// 전체 검사, false이면 
				continue;	// 다시 첫글자와 같은 인덱스 찾기
		}
	}
	cout << "Not found" << endl;
	return;
}

/*#include <iostream>
#include <string>
using namespace std;

int main() {

	string str1, str2;

	cout << "string1 : ";
	getline(cin, str1);

	cout << "string2 : ";
	getline(cin, str2);

	if (str1.find(str2) != string::npos) {
		int index = str1.find(str2);
		cout << index << endl;
	}
	else {
		cout << "Not found" << endl;
	}

	return 0;
}
*/
