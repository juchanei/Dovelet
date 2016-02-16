#include <iostream>
using namespace std;

int main()
{
	int in[7], outOne = 0, outTen = 0, outHundred = 0;

	for (int i = 0; i<7; i++) {
		cin >> in[i];
		if ((in[i] / 100) > 0) {
			outHundred += in[i];
		}
		else if (in[i] / 10 > 0) {
			outTen += in[i];
		}
		else {
			outOne += in[i];
		}
	}

	cout << outOne << " " << outTen << " " << outHundred;
	return 0;
}