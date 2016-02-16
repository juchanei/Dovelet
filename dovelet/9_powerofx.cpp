#include <iostream>
using namespace std;

int power(int num, int iter)
{
	if (iter == 0)
		return 1;

	return num*power(num, iter - 1);
}

int main()
{
	int a = 0, b = 0;
	cin >> a >> b;
	cout << power(a, b) << endl;

	return 0;
}