#include <iostream>
using namespace std;
#define SIZE 10

int sizeRow, sizeCol, step = 0;
char arr[SIZE][SIZE] = { 0, };
int visited[SIZE][SIZE] = { 0, };

void robotMove(int row, int col, char c)
{
	if (row<0 || col<0 || row >= sizeRow || col >= sizeCol) {
		cout << step << " step(s) to exit" << endl;
		return;
	}
	if (visited[row][col] != 0) {
		cout << visited[row][col] - 1 << " step(s) before a loop of " << step - visited[row][col] + 1 << " step(s)" << endl;
	}
	else {
		step++;
		visited[row][col] = step;
		switch (c) {
		case 'N':
			robotMove(row - 1, col, arr[row - 1][col]);
			break;
		case 'S':
			robotMove(row + 1, col, arr[row + 1][col]);
			break;
		case 'E':
			robotMove(row, col + 1, arr[row][col + 1]);
			break;
		case 'W':
			robotMove(row, col - 1, arr[row][col - 1]);
			break;
		}
	}
}


int main()
{
	int start;
	cin >> sizeRow >> sizeCol >> start;

	for (int i = 0; i < sizeRow; i++) {
		for (int j = 0; j < sizeCol; j++) {
			cin >> arr[i][j];
		}
	}

	int row = 0;
	int col = start - 1;
	robotMove(row, col, arr[row][col]);

	return 0;
}