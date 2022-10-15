#include <iostream>
#include <cmath>
using namespace std;

int dist_2d(int x1, int y1, int x2, int y2) {

	int sum, dist;
	sum = pow(x2 - x1, 2) + pow(y2 - y1, 2);
	dist = sqrt(sum);

	return dist;
	
}
int main() {

	int x1, x2, y1, y2;
	cout << "input x1, y1 : ";
	cin >> x1 >> y1;

	cout << "input x2, y2 : ";
	cin >> x2 >> y2;

	cout << "Distance : " << dist_2d(x1, y1, x2, y2);

	return 0;
}