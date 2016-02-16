#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	double r, n, pi;
	cin >> r >> n;

	pi = atan(1) * 4;

	cout.precision(3);
	cout << std::fixed;
	cout << r*r*n*sin(2 * pi / n) / 2;
	return 0;
}