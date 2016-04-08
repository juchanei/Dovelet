#include <iostream>
#include <vector>
using namespace std;

int min(int a, int b)
{
	return a < b ? a : b;
}

int max(int a, int b)
{
	return a < b ? b : a;
}

int main()
{
	int mapSize, nTree;
	cin >> mapSize >> nTree;

	vector<vector<int> > map(mapSize + 1, vector<int>(mapSize + 1, 0));
	for (int i = 0; i < nTree; ++i) {
		int xx, yy;
		cin >> xx >> yy;
		map[yy][xx] = -1;
	}

	for (int i = 1; i < map.size(); ++i) {
		for (int j = 1; j < map.size(); ++j) {
			if (0 == map[i][j]) {
				int minValue = min(map[i - 1][j - 1], min(map[i][j - 1], map[i - 1][j]));
				if (minValue == -1) {
					map[i][j] = 1;
					continue;
				}
				map[i][j] = minValue + 1;
			}
		}
	}

	int maxValue = 0;
	for (int i = 1; i < map.size(); ++i) {
		for (int j = 1; j < map.size(); ++j) {
			maxValue = max(maxValue, map[i][j]);
		}
	}

	cout << maxValue << endl;

	return 0;
}