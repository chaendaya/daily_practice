#include <iostream>
#include <random>
using namespace std;

int check();
int bonuscheck();
string ranking();
void lotto();

int gn1, gn2, gn3, gn4, gn5, gn6;
int n1, n2, n3, n4, n5, n6, n7;

int bonus = 0;
int match = 0;
string place;


int main() {

	

	cout << "Guess lottery numbers : " << endl;
	cout << endl;
	cin >> gn1; cout << endl;
	cin >> gn2; cout << endl;
	cin >> gn3; cout << endl;
	cin >> gn4; cout << endl;
	cin >> gn5; cout << endl;
	cin >> gn6; cout << endl;

	cout << "Number : ";
	lotto();
	cout << endl;
	cout << endl;
	cout << "You match " << check() << " numbers and "
		<< bonuscheck() << " bonus number!" << endl;
	cout << ranking() << endl;

	return 0;
}


void lotto()
{
	random_device rd;
	mt19937 gen(rd());

	while (true) {

		n1 = (gen() % 45 + 1);
		n2 = (gen() % 45 + 1);
		
		if (n1 != n2)
			break;
	}

	while (true) {

		n3 = (gen() % 45 + 1);

		if (n2 != n3 && n1 != n3)
			break;
	}

	while (true) {

		n4 = (gen() % 45 + 1);

		if (n3 != n4 && n2 != n4 && n1 != n4)
			break;
	}

	while (true) {

		n5 = (gen() % 45 + 1);

		if (n4 != n5 && n3 != n5 && n2 != n5 && n1 != n5)
			break;
	}

	while (true) {

		n6 = (gen() % 45 + 1);

		if (n5 != n6 && n4 != n6 && n3 != n6 && n2 != n6 && n1 != n6)
			break;
	}

	while (true) {

		n7 = (gen() % 45 + 1);

		if (n6 != n7 && n5 != n7 && n4 != n7 && n3 != n7 && n2 != n7 && n1 != n7)
			break;
	}
	cout << n1 << ", " << n2 << ", " << n3 << ", " << n4 << ", " 
		<< n5 << ", " << n6 << " | Bonus number : " << n7;
}

int bonuscheck() {
	if (n7 == gn1 || n7 == gn2 || n7 == gn3 || n7 == gn4 || n7 == gn5 || n7 == gn6)
		bonus++;
	return bonus;
}

int check() {

	if (n1 == gn1 || n1 == gn2 || n1 == gn3 || n1 == gn4 || n1 == gn5 || n1 == gn6) 
		match++;
	
	if (n2 == gn1 || n2 == gn2 || n2 == gn3 || n2 == gn4 || n2 == gn5 || n2 == gn6)
		match++;
	
	if (n3 == gn1 || n3 == gn2 || n3 == gn3 || n3 == gn4 || n3 == gn5 || n3 == gn6)
		match++;
	
	if (n4 == gn1 || n4 == gn2 || n4 == gn3 || n4 == gn4 || n4 == gn5 || n4 == gn6)
		match++;

	if (n5 == gn1 || n5 == gn2 || n5 == gn3 || n5 == gn4 || n5 == gn5 || n5 == gn6)
		match++;

	if (n6 == gn1 || n6 == gn2 || n6 == gn3 || n6 == gn4 || n6 == gn5 || n6 == gn6)
		match++;

	return match;
}

string ranking() {
	if (bonus == 0 && match == 6) place = "You are in 1th place";
	if (bonus == 1 && match == 5) place = "You are in 2nd place";
	if (bonus == 0 && match == 5) place = "You are in 3rd place";
	if (match == 4)	place = "You are in 4th place";
	if (match == 3)	place = "You are in 5th place";
	else place = "You didn't rank in the top five..";

	return place;
}