#include <iostream>
using namespace std;

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	int a1, a2, b1, b2;
	cin >> a1 >> a2;
	cin >> b1 >> b2;

	// a2 must bigger than a1
	if (a1 > a2) {
		swap(a1, a2);
	}
	// b2 must bigger than b1
	if (b1 > b2) {
		swap(b1, b2);
	}
	// a2 must bigger than b2
	if (a2 < b2) {
		swap(a1, b1);
		swap(a2, b2);
	}

	// a2>a1>b2>b2 || a2>b2>b1>a1
	if (a1 > b2 || a1 < b1) {
		cout << "not cross" << endl;
	}
	// a2>b2>a1>b1
	else {
		cout << "cross" << endl;
	}

	return 0;
}