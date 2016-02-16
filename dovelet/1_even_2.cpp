#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;

	cout << (b - a + 1) - (static_cast<int>(sqrt(b)) - static_cast<int>(sqrt(a))) << endl;

	return 0;
}