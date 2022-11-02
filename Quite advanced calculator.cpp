#include <iostream>
using namespace std;

int n, m;
int A[3][3];
int B[3][3];
int C[3][3];
// ����� ũ��� 3x3���� ����

char op;
int add_matrix(int n, int m);
int mul_matrix(int n, int m);


int main() {

	cout << "---------------------" << endl;
	cout << " + : addition" << endl;
	cout << " * : multiplication" << endl;
	cout << "---------------------" << endl;


	cout << "Select an operator : ";		// ������ �Է¹ޱ�
	cin >> op;


	cout << "Input matrix1 : ";
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {		// 3x3 ������ �ڸ��� ����
			cin >> A[i][j];					// ��� A �Է¹ޱ�
		}
	}

	cout << "Input matrix2 : ";

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {		// 3x3 ������ �ڸ��� ����
			cin >> B[i][j];					// ��� B �Է¹ޱ�
		}
	}


	if (op == '+') {						// op == '+' �� ���

		for (int n = 0; n < 3; n++) {
			for (int m = 0; m < 3; m++) {	// 3x3 ������ �ڸ��� ����
				add_matrix(n, m);			// ����� �� ����
			}
		}

		cout << "Answer : " << endl;

		for (int n = 0; n < 3; n++) {
			for (int m = 0; m < 3; m++) {	// 3x3 ������ �ڸ��� ����
				cout << C[n][m] << " ";		// ���� ��� ��� ���
			}
			cout << endl;
		}
	}


	else if (op == '*') {					// op == '*' �� ���

		for (int n = 0; n < 3; n++) {
			for (int m = 0; m < 3; m++) {	// 3x3 ������ �ڸ��� ����
				mul_matrix(n, m);			// ����� �� ����
			}
		}

		cout << "Answer : " << endl;

		for (int n = 0; n < 3; n++) {
			for (int m = 0; m < 3; m++) {	// 3x3 ������ �ڸ��� ����
				cout << C[n][m] << " ";		// ���� ��� ��� ���
			}
			cout << endl;
		}

	}
	
	else {
		cout << "������ �� ���� �����Դϴ�.";
	}

	return 0;
}

int add_matrix(int n, int m) {			// ��� �� �Լ�

	C[n][m] = A[n][m] + B[n][m];

	return C[n][m];
}

int mul_matrix(int n, int m) {			// ��� �� �Լ�

	for (int k = 0; k < 3; k++) {

		C[n][m] += A[n][k] * B[k][m];
	}

	return C[n][m];
}

/*
	��� ���� ���� ����

	A[0][0] A[0][1] A[0][2]		B[0][0] B[0][1] B[0][2]
	A[1][0] A[1][1] A[1][2]		B[1][0] B[1][1] B[1][2]
	A[2][0] A[2][1] A[2][2]		B[2][0] B[2][1] B[2][2]

	C[0][0] = A[0][0]*B[0][0] + A[0][1]*B[1][0] + A[0][2]*B[2][0]
	               ^    ^             ^   ^            ^    ^
*/