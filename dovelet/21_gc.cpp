#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int dpLog[20] = { 0, };
	dpLog[0] = 1;
	dpLog[1] = 1;

	int i = 0;
	int j = 0;
	for (i = 2; i <= n; i++) {
		int sum = 0;
		for (j = 0; j < i / 2; j++) {
			sum += dpLog[j] * dpLog[i - j - 1];
		}

		if (i % 2 == 0) {
			dpLog[i] = sum * 2;
		}
		else {
			dpLog[i] = sum * 2 + dpLog[i / 2] * dpLog[j];
		}
	}

	cout << dpLog[n] << endl;

	return 0;
}