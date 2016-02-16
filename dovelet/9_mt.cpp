#include <iostream>
using namespace std;

void printMountain(int start, int n)
{
	if (start < n) {
		cout << start;
		printMountain(start + 1, n);
	}
	cout << start;

}

int main()
{
	int n;
	cin >> n;
	printMountain(1, n);
	return 0;
}