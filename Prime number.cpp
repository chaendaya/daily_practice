#include <iostream>
#include <random>
using namespace std;

string checking();

int num;
string result;

int main() {

	while (true) {

		cout << "input number : ";
		cin >> num;

		if (num == -1) {
			cout << "Done.";
			break;
		}
		else {
			cout << num << checking() << endl;
			cout << endl;
		}

		}

	return 0;
	}

string checking() {

	int i = 2;
	int j = num - 1;

	while(true)
	{
		if (i <= j) {
			if (num % i == 0) {
				result = " is not a prime number.";
				break;
			}
			else {
				i++;
			}
		}
		else {
			result = " is a prime number.";
			break;
		}
		/*if (num % i == 0) {
			result = " is not a prime number.";
			break;
		}

		if (i = (num-1)) {
			result = " is a prime number.";
			break;
		}

		i++;
		continue;
		*/
	}

	return result;

}