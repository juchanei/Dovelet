#include <iostream>
using namespace std;

int max(int x, int y)
{
	if (x > y) return x;
	else if (x < y) return y;
	else return x;
}

int min(int x, int y)
{
	if (x > y) return y;
	else if (x < y) return x;
	else return x;
}

int main()
{
	int x, y, out;
	cin >> x >> y;

	out = max(min(x, y), x);

	cout << out;
	return 0;
}