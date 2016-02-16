#include <iostream>
using namespace std;

int triangle[1001][1001] = { 0, };
int dpLog[1001][1001] = { 0, };

int main()
{
	int r = 0;
	cin >> r;

	for (int i = 0; i < r; i++) {
		for (int j = 1; j < i + 2; j++) {
			cin >> triangle[i][j];
		}
	}

	dpLog[0][1] = triangle[0][1];
	for (int i = 1; i < r; i++) {
		for (int j = 1; j < i + 2; j++) {
			int big = dpLog[i - 1][j - 1];
			if (dpLog[i - 1][j] > big) big = dpLog[i - 1][j];
			dpLog[i][j] = triangle[i][j] + big;
		}
	}

	int big = dpLog[r - 1][1];
	for (int i = 2; i <= r; i++) {
		if (dpLog[r - 1][i]>big) {
			big = dpLog[r - 1][i];
		}
	}

	cout << big << endl;

	return 0;
}