#include <iostream>
using namespace std;

void convDec2BinArray(int deci, char* binArray, int& index)
{
	int mask = 0x1;
	while (deci > 0) {
		binArray[index] = deci & mask;
		deci = deci >> 1;
		++index;
	}
	--index;
}

int main()
{
	int theNumber = 0;
	cin >> theNumber;

	char binArray[32] = { 0, };
	int index = 0;

	convDec2BinArray(theNumber + 1, binArray, index);

	for (int i = index - 1; i >= 0; i--) {
		if (binArray[i] == 0) {
			cout << '4';
		}
		else {
			cout << '7';
		}
	}
	cout << endl;

	return 0;
}