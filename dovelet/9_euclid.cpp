#include <iostream>
using namespace std;

int compare(int a, int b)
{
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}

int main()
{
	int a = 0, b = 0;
	cin >> a >> b;

	if (a > b) {
		int temp;
		temp = a;
		a = b;
		b = temp;
	}

	int big = 0;
	for (int i = 1; i <= a; i++) {
		if (a%i == 0 && b%i == 0) {
			big = compare(big, i);
		}
	}

	cout << big << " " << (a / big) * (b / big)*big << endl;

	return 0;
}