#include <iostream>
using namespace std;

int main()
{
	int in[8];
	for (int i = 0; i < 8; i++) {
		cin >> in[i];
	}

	if (in[0] == 1) {
		for (int j = 1; j < 8; j++) {
			if (in[j] != (j + 1)) {
				cout << "mixed" << endl;
				return 0;
			}
		}
		cout << "ascending" << endl;
		return 0;
	}
	else if (in[0] == 8) {
		for (int k = 1; k < 8; k++) {
			if (in[k] != (8 - k)) {
				cout << "mixed" << endl;
				return 0;
			}
		}
		cout << "descending" << endl;
		return 0;
	}
	else {
		cout << "mixed" << endl;
	}
	return 0;
}