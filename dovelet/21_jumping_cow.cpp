#include <iostream>
using namespace std;

int dpLog[150001] = { 0, };
int medi[150001] = { 0, };
int main()
{
	int p = 0;
	cin >> p;

	for (int i = 0; i < p; i++) {
		cin >> medi[i];
	}

	dpLog[0] = medi[0];
	for (int i = 1; i < p; i++) {
		dpLog[i] = dpLog[i - 1];
		for (int j = 0; j < p - i; j++) {
			if (medi[i + j] > medi[i + j - 1]) {
				dpLog[i + j] = dpLog[i + j - 1] + medi[i + j] - medi[i + j - 1];
				break;
			}
			else {
				dpLog[i + j] = dpLog[i + j - 1];
				break;
			}
		}
	}
	cout << dpLog[p - 1] << endl;

	return 0;
}