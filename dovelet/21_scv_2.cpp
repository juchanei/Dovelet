#include <iostream>
using namespace std;

int main()
{
	int n = 0;
	int map[102][102] = { 0, };

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}

	int valueMap[102][102] = { 0, };
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int bigThing = valueMap[i - 1][j];
			if (valueMap[i][j - 1] > bigThing) bigThing = valueMap[i][j - 1];
			valueMap[i][j] = bigThing + map[i][j];
		}
	}

	cout << valueMap[n][n] << endl;

	return 0;
}