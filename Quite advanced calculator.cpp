#include <iostream>
using namespace std;

int n, m;
int A[3][3];
int B[3][3];
int C[3][3];
// 행렬의 크기는 3x3으로 고정

char op;
int add_matrix(int n, int m);
int mul_matrix(int n, int m);


int main() {

	cout << "---------------------" << endl;
	cout << " + : addition" << endl;
	cout << " * : multiplication" << endl;
	cout << "---------------------" << endl;


	cout << "Select an operator : ";		// 연산자 입력받기
	cin >> op;


	cout << "Input matrix1 : ";
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {		// 3x3 각각의 자리에 대한
			cin >> A[i][j];					// 행렬 A 입력받기
		}
	}

	cout << "Input matrix2 : ";

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {		// 3x3 각각의 자리에 대한
			cin >> B[i][j];					// 행렬 B 입력받기
		}
	}


	if (op == '+') {						// op == '+' 인 경우

		for (int n = 0; n < 3; n++) {
			for (int m = 0; m < 3; m++) {	// 3x3 각각의 자리에 대한
				add_matrix(n, m);			// 행렬의 합 연산
			}
		}

		cout << "Answer : " << endl;

		for (int n = 0; n < 3; n++) {
			for (int m = 0; m < 3; m++) {	// 3x3 각각의 자리에 대한
				cout << C[n][m] << " ";		// 연산 결과 행렬 출력
			}
			cout << endl;
		}
	}


	else if (op == '*') {					// op == '*' 인 경우

		for (int n = 0; n < 3; n++) {
			for (int m = 0; m < 3; m++) {	// 3x3 각각의 자리에 대한
				mul_matrix(n, m);			// 행렬의 곱 연산
			}
		}

		cout << "Answer : " << endl;

		for (int n = 0; n < 3; n++) {
			for (int m = 0; m < 3; m++) {	// 3x3 각각의 자리에 대한
				cout << C[n][m] << " ";		// 연산 결과 행렬 출력
			}
			cout << endl;
		}

	}
	
	else {
		cout << "수행할 수 없는 연산입니다.";
	}

	return 0;
}

int add_matrix(int n, int m) {			// 행렬 합 함수

	C[n][m] = A[n][m] + B[n][m];

	return C[n][m];
}

int mul_matrix(int n, int m) {			// 행렬 곱 함수

	for (int k = 0; k < 3; k++) {

		C[n][m] += A[n][k] * B[k][m];
	}

	return C[n][m];
}

/*
	행렬 곱에 대한 관찰

	A[0][0] A[0][1] A[0][2]		B[0][0] B[0][1] B[0][2]
	A[1][0] A[1][1] A[1][2]		B[1][0] B[1][1] B[1][2]
	A[2][0] A[2][1] A[2][2]		B[2][0] B[2][1] B[2][2]

	C[0][0] = A[0][0]*B[0][0] + A[0][1]*B[1][0] + A[0][2]*B[2][0]
	               ^    ^             ^   ^            ^    ^
*/