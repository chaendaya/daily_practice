#include <iostream>
#include <random>
using namespace std;

void graph(int len, int dot)
{
	for (int i = 0; i < len; i++)
	{
		if (i < dot)  cout << "@";
		else 
			cout << "*";
	}
}

int main() {

	random_device rd;
	mt19937 gen(rd());

	int num;
	cout << "Roll a dice 'n' times : ";
	cin >> num;

	int n1, n2, n3, n4, n5, n6;

	n1 = (gen() % num + 1);
	n2 = (gen() % num + 1);
	n3 = (gen() % num + 1);
	n4 = (gen() % num + 1);
	n5 = (gen() % num + 1);
	n6 = (gen() % num + 1);

	cout << "1 : ";
	graph(num, n1); cout << endl;
	cout << "2 : ";
	graph(num, n2); cout << endl;
	cout << "3 : " ;
	graph(num, n3); cout << endl;
	cout << "4 : " ;
	graph(num, n4); cout << endl;
	cout << "5 : " ;
	graph(num, n5); cout << endl;
	cout << "6 : " ;
	graph(num, n6); cout << endl;

	return 0;
}

