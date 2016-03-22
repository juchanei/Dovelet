#include <iostream>
using namespace std;

int max(int a, int b)
{
	if (a > b)	return a;
	return b;
}

int main()
{
	int nStair = 0;
	cin >> nStair;
	int board[301][3] = { 0, };
	for (int i = 0; i < nStair; ++i){
		cin >> board[i][0];
	}

	board[0][1] = board[0][0];
	board[1][1] = board[0][1] + board[1][0];
	board[1][2] = board[1][0];

	for (int i = 2; i < nStair; ++i){
		board[i][1] = board[i - 1][2] + board[i][0];
		board[i][2] = max(board[i - 2][1], board[i - 2][2]) + board[i][0];
	}

	cout << max(board[nStair - 1][1], board[nStair - 1][2]) << endl;

	return 0;
}