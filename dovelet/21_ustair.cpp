#include <iostream>
using namespace std;

int dpLog[1001][3] = { 0, };

int main()
{
	int num = 0;
	cin >> num;
	int stair[10001] = { 0, };
	for (int i = 1; i <= num; i++) {
		cin >> stair[i];
	}

	dpLog[1][2] = stair[1];
	dpLog[2][2] = stair[2];

	for (int i = 2; i <= num; i++) {
		int bigTemp = dpLog[i - 1][1];
		if (dpLog[i - 1][2] > bigTemp) bigTemp = dpLog[i - 1][2];
		dpLog[i][0] = bigTemp + stair[i];

		dpLog[i][1] = dpLog[i - 2][0] + stair[i];

		int bigTemp2 = dpLog[i - 2][2] + stair[i];
		if (dpLog[i][1] > bigTemp2) bigTemp2 = dpLog[i][1];
		dpLog[i][2] = bigTemp2;
	}

	int bigger = dpLog[num][0];
	if (dpLog[num][1] > bigger) bigger = dpLog[num][1];
	if (dpLog[num][2] > bigger) bigger = dpLog[num][2];
	cout << bigger << endl;

	return 0;
}