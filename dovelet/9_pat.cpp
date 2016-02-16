#include <iostream>
#include <string>
using namespace std;

void printBin(string out, int n, int k, string str)
{
	if (n == 0 && k == 0)
		cout << str << endl;
	else if (n != 0 && k == 0) {
		str += "0";
		n--;
	}
	else if (n == 0 && k != 0) {
		return;
	}
	else {
		str += out;
		printBin("1", n - 1, k - 1, str);
		printBin("0", n - 1, k, str);
	}
	return;
}

int main()
{
	int n, k;
	cin >> n >> k;

	printBin("1", n, k, "");
	printBin("0", n, k + 1, "");

	return 0;
}