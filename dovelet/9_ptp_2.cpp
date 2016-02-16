#include <iostream>
using namespace std;

void print(int current)
{
	if (current == 0) {
		return;
	}

	print(current - 1);
	cout << current;
	print(current - 1);
}

int main()
{
	int nn = 0;
	cin >> nn;

	print(nn);

	return 0;
}