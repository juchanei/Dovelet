#include <iostream>
using namespace std;
#define SIZE 8
int arr[SIZE][SIZE] = { 0, };
int maxCount = 0;
int maxCase = 0;

void printArr(int arr[SIZE][SIZE])
{
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void copyArr(int src[SIZE][SIZE], int dst[SIZE][SIZE])
{
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			dst[i][j] = src[i][j];
		}
	}
}


void checkArr(int x, int y, int arr[SIZE][SIZE])
{
	for (int i = x + 1; i < SIZE; i++) {
		if (arr[i][y] != 1) arr[i][y] = 2; //하 체크
		else break;
	}
	for (int i = x - 1; i >= 0; i--) {
		if (arr[i][y] != 1) arr[i][y] = 2; //상 체크
		else break;
	}
	for (int i = y + 1; i < SIZE; i++) {
		if (arr[x][i] != 1) arr[x][i] = 2; //우 체크
		else break;
	}
	for (int i = y - 1; i >= 0; i--) {
		if (arr[x][i] != 1) arr[x][i] = 2; //좌 체크
		else break;
	}
	arr[x][y] = 2;
}
void dfs(int x, int y, int arr[SIZE][SIZE], int depth)
{
	int _arr[SIZE][SIZE] = { 0, };
	copyArr(arr, _arr);
	checkArr(x, y, _arr);

	if (maxCount < depth) {
		maxCase++;
	}
	if (maxCount < depth) {
		maxCount = depth;
		maxCase = 1;
	}
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (_arr[i][j] == 0) {
				dfs(i, j, _arr, depth + 1);
				_arr[i][j] = 1;
			}
		}
	}
}

int main()
{
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (arr[i][j] == 0) {
				dfs(i, j, arr, 1);
				arr[i][j] = 1;
			}
		}
	}

	cout << "maxCount : " << maxCount << endl;
	cout << "maxCase : " << maxCase << endl;

	return 0;
}