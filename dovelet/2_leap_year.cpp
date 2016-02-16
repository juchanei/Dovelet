#include <iostream>
using namespace std;

int main()
{
	int in;
	cin >> in;

	if (((in % 4 == 0) && (in % 100 != 0)) || (in % 400 == 0)) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}

	return 0;
}