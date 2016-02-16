#include <iostream>
using namespace std;

int main()
{
	int size;
	int map[102][102] = { 0, };
	int map2[102][102] = { 0, };
	cin >> size;

	for (int i = 1; i <= size; i++){
		for (int j = 1; j <= size; j++){
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= size; i++){
		for (int j = 1; j <= size; j++){
			int bigger = map2[i][j - 1];
			if (bigger < map2[i - 1][j]) bigger = map2[i - 1][j];
			map2[i][j] = bigger + map[i][j];
		}
	}

	cout << map2[size][size] << endl;

	return 0;
}