#include <iostream>
#include <vector>
using namespace std;

class Position{
public:
	int x;
	int y;
	Position(int xx, int yy) : x(xx), y(yy){}
	bool operator ==(const Position& rhs)
	{
		if (x == rhs.x && y == rhs.y)
			return true;
		else
			return false;
	}
};

const char DIRECTION[4][2] = {
	0, -1,
	0, 1,
	-1, 0,
	1, 0
};

void dfs(vector<vector<int> >& map, Position here, Position dest, int count, int& result)
{
	if (count >= result){
		return;
	}
	if (here == dest){
		if (count < result){
			result = count;
		}
		return;
	}
	map.at(here.y).at(here.x) = 3;

	for (int i = 0; i < 4; ++i){
		if (0 == map.at(here.y + DIRECTION[i][1]).at(here.x + DIRECTION[i][0])){
			Position there(here.x + DIRECTION[i][0], here.y + DIRECTION[i][1]);
			dfs(map, there, dest, count + 1, result);
		}
	}

	map.at(here.y).at(here.x) = 0;
}

int main()
{
	int width = 0;
	int height = 0;
	cin >> width >> height;

	vector<vector<int> > map(height + 2, vector<int>(width + 2, 1));

	for (int i = 1; i <= height; ++i){
		char buffer[22] = { 0, };
		cin >> buffer;
		for (int j = 0; j < width; ++j){
			map.at(i).at(j + 1) = buffer[j] - '0';
		}
	}

	Position start(1, height);
	Position end(width, 1);
	int result = width * height + 1;
	dfs(map, start, end, 1, result);

	cout << result << endl;

	return 0;
}