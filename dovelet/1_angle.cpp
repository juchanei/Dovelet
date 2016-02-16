#include <iostream>
using namespace std;

int main()
{
	int n, inner, outer;
	cin >> n;

	inner = (n - 2) * 180;
	outer = 180 * n - inner;

	cout << inner << " " << outer;
	return 0;
}