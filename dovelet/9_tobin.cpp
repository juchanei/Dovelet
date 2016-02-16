#include <iostream>
using namespace std;

void printAsBinary(int n)
{
	if (n >= 2) printAsBinary(n / 2);

	cout << n % 2;
}

int main()
{
	int n;
	cin >> n;
	printAsBinary(n);
	return 0;
}