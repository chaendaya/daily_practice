#include <iostream>
#include <cmath>
using namespace std;

double dist_2d(double x1, double y1, double x2, double y2) {

	double dist;

	dist = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

	return dist;
}

int main() {

	double x1, x2, y1, y2;
	cout << "input x1, y1 : ";
	cin >> x1 >> y1;

	cout << "input x2, y2 : ";
	cin >> x2 >> y2;

	cout << "Distance : " << dist_2d(x1, y1, x2, y2) << endl;

	return 0;
}
