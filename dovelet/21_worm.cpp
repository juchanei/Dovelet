#include <iostream>
using namespace std;

int wt[1010001][2] = { 0, };

int main()
{
	int aa, bb, dd, nn;
	cin >> aa >> bb >> dd >> nn;

	wt[0][0] = 1;
	wt[dd][1] = -1;

	int newWorms = 0;
	for (int i = aa; i < bb; ++i){
		newWorms = 0;
		for (int j = 0; j < bb - aa && 0 <= i - aa - j; ++j){
			newWorms += wt[i - aa - j][0];
		}
		wt[i][0] = newWorms % 1000;
		wt[i + dd][1] = -wt[i][0];
	}

	for (int i = bb; i <= nn; ++i){
		newWorms += wt[i - aa][0];
		newWorms -= wt[i - bb][0];
		wt[i][0] = newWorms % 1000;
		wt[i + dd][1] = -wt[i][0];
	}

	int nWorm = 0;
	for (int i = 0; i <= nn; ++i){
		nWorm += wt[i][0] + wt[i][1];
		nWorm = (nWorm + 1000) % 1000;
	}
	cout << nWorm << endl;

	return 0;
}