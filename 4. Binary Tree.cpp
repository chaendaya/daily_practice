// 4. Binary Tree (Array implementation)
#include <iostream>
using namespace std;

char tree[15];
int root(char key) {
	if (tree[0] != NULL)
		cout << "Tree already had root" << endl;
	else {
		tree[0] = key;
		cout << "'" << key << "' is at the root." << endl;
	}
	return 0;
}

int set_left(char key, int parentID) {
	if (tree[parentID] == NULL) {
		cout << "no parent found " << endl;
	}
	else if (tree[(parentID * 2) + 1] == NULL) {
		tree[(parentID * 2) + 1] = key;
		cout << "'" << key << "' is appended at the left of '" << tree[parentID] << "'" << endl;
	}
	else if (tree[(parentID * 2) + 1] != NULL) {
		cout << "'" << tree[parentID] << "' has already the left child." << endl;
	}
	return 0;
}

int set_right(char key, int parentID) {
	if (tree[parentID] == NULL) {
		cout << "no parent found " << endl;
	}
	else if (tree[(parentID * 2) + 2] == NULL) {
		tree[(parentID * 2) + 2] = key;
		cout << "'" << key << "'" << " is appended at the right of '" << tree[parentID] << "'" << endl;
	}
	else if (tree[(parentID * 2) + 2] != NULL) {
		cout << "'" << parentID << "'" << " has already the right child." << endl;
	}
	return 0;
}

void branch(int i) {
	int j = 2 * i;
	for (i; i <= j; i++) {	// �˻� ������ �ε��� i���� 2*i����
		if (i == 0) cout << " ";	// A[0] ��Ʈ�� �������� ������ ����
		else if (i % 2 != 0 && tree[i] != NULL) cout << "/ ";	// ���� �ִ� ���, ���� ���� ���
		else if (i % 2 == 0 && tree[i] != NULL) cout << " \\";	// ���� �ִ� ���, ������ ���� ���
	}
	cout << endl;
}

void leaf(int i) {
	int j = i * 2;
	for (i; i <= j; i++) {	// �˻� ������ �ε��� i���� 2*i����
		if (tree[i] != NULL) cout << tree[i] << "(" << i << ") ";	// ���� ������ ���
		else if (tree[i] == NULL) cout << "   ";	// ���� ������ ����
	}
	cout << endl;
}

void print_tree() {
	cout << endl;

	for (int i = 0; i < 15; i++) {
		static int height = 1;

		if (i == (height - 1)) {
			branch(i);
			leaf(i);
			height *= 2;
		}
	}
}

int main() {

	root('A');
	set_left('B', 0);
	set_left('C', 0);
	set_right('C', 0);
	set_left('D', 1);
	set_right('E', 3);
	print_tree();

	return 0;
}