#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void searchMap(vector<vector<int> >& map, vector<vector<int> >& visited, int x, int y, int& count)
{
	visited.at(y).at(x) = 1;
	++count;

	if (1 == map.at(y + 1).at(x) && 0 == visited.at(y + 1).at(x)) {
		searchMap(map, visited, x, y + 1, count);
	}
	if (1 == map.at(y - 1).at(x) && 0 == visited.at(y - 1).at(x)) {
		searchMap(map, visited, x, y - 1, count);
	}
	if (1 == map.at(y).at(x + 1) && 0 == visited.at(y).at(x + 1)) {
		searchMap(map, visited, x + 1, y, count);
	}
	if (1 == map.at(y).at(x - 1) && 0 == visited.at(y).at(x - 1)) {
		searchMap(map, visited, x - 1, y, count);
	}

	return;
}

int main()
{
	int mapSize = 0;
	cin >> mapSize;

	vector<vector<int> > map(mapSize+2, vector<int>(mapSize+2, 0));
	vector<vector<int> > visited(mapSize+2, vector<int>(mapSize+2, 0));
	for (int i = 1; i <= mapSize; ++i) {
		for (int j = 1; j <= mapSize; ++j) {
			cin >> map.at(i).at(j);
		}
	}

	vector<int> outdata;
	for (int i = 1; i <= mapSize; ++i) {
		for (int j = 1; j <= mapSize; ++j) {
			if (1 == map.at(i).at(j) && 0 == visited.at(i).at(j)) {
				int count = 0;
				searchMap(map, visited, j, i, count);
				outdata.push_back(count);
			}
		}
	}

	sort(outdata.begin(), outdata.end());
	cout << outdata.size() << endl;
	for (int i = 0; i < outdata.size(); ++i) {
		cout << outdata.at(i) << endl;
	}

	return 0;
}