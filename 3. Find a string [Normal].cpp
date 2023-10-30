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

bool checkFull(int i) {		// ã�� str1 �ε������� str2 ��ü�� ������ �˻�
	for (int j = 0; j < str2.length(); j++) {
		if (str1[i] == str2[j])
			i++;
		else
			return false;
	}
	return true;
}

void findIndex() {		// str1���� str2�� ù���ڿ� ���� �ε��� ã��
	for (int i = 0; i < str1.length(); i++) {
		if (str1[i] == str2[0]) {	// str2�� ù���ڰ� �߰ߵǸ�
			if (checkFull(i) == true) {		// ��ü �˻�, true�̸�
				cout << i << endl;			// ó�� ��ġ�ϴ� �ε��� ��ȯ
				return;
			}
			else			// ��ü �˻�, false�̸� 
				continue;	// �ٽ� ù���ڿ� ���� �ε��� ã��
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
