#include <iostream>
using namespace std;

int main()
{
	int in, change, out100, out50, out10;

	cin >> in;
	change = 1000 - in;

	out100 = change / 100;
	change = change % 100;

	out50 = change / 50;
	change = change % 50;

	out10 = change / 10;

	cout << out100 << " " << out50 << " " << out10 << endl;
	return 0;
}
