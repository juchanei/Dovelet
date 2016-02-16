#include <iostream>
using namespace std;

void hanoi(int n, int x, int y, int z)
{
	if (n == 0) return;
	hanoi(n - 1, x, z, y);
	cout << x << " -> " << z << endl;
	hanoi(n - 1, y, x, z);
}

int main()
{
	int n = 0;
	cin >> n;

	hanoi(n, 1, 2, 3);

	return 0;
}