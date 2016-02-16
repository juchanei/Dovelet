#include <iostream>
using namespace std;

int main()
{
	int n = 0;
	int m = 0;
	cin >> n >> m;

	int fixedSeat[41] = { 0, };
	for (int i = 0; i < m; i++) {
		cin >> fixedSeat[i];
	}
	fixedSeat[m] = n + 1;

	int valueMap[101] = { 0, };
	valueMap[0] = 1;
	valueMap[1] = 1;
	for (int i = 2; i <= n; i++) {
		valueMap[i] = valueMap[i - 1] + valueMap[i - 2];
	}
	
	long long int sum = valueMap[fixedSeat[0] - 1];
	for (int i = 1; i <= m; i++) {
		sum *= valueMap[fixedSeat[i] - fixedSeat[i - 1] - 1];
	}

	cout << sum << endl;

	return 0;
}