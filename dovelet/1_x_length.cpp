#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	double r1, r2, pi;
	cin >> r1 >> r2;
	pi = 3.14159;

	cout.precision(3);
	cout << std::fixed;
	cout << (r1 + r2)*(pi + sqrt(2));
	return 0;
}