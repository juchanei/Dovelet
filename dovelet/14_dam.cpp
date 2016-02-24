#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Position{
	int x;
	int y;
	int t;
	Position(int x, int y, int t) :x(x), y(y), t(t) {}
};

const char DIRECTION[4][2] = {
	0, -1,
	0, 1,
	-1, 0,
	1, 0
};

int bfs(vector<vector<int> >& square, queue<Position>& qq, const int& timeLimit)
{
	int count = 0;
	while (!qq.empty()){
		Position here = qq.front();
		qq.pop();

		if (timeLimit == here.t){
			++count;
		}
		else if (timeLimit + 1 == here.t){
			return count;
		}

		for (int i = 0; i < 4; ++i){
			if (0 == square.at(here.y + DIRECTION[i][1]).at(here.x + DIRECTION[i][0]))
			{
				Position next(here.x + DIRECTION[i][0], here.y + DIRECTION[i][1], here.t + 1);
				qq.push(next);
				square.at(next.y).at(next.x) = 3;
			}
		}
	}

	return count;
}

int main()
{
	int squareSize = 0;
	cin >> squareSize;

	vector<vector<int> > square(squareSize + 2, vector<int>(squareSize + 2, 1));

	for (int i = 1; i < square.size() - 1; ++i){
		for (int j = 1; j < square.at(i).size() - 1; ++j){
			cin >> square.at(i).at(j);
		}
	}

	int lakeX = 0;
	int lakeY = 0;
	cin >> lakeX >> lakeY;
	Position lake(lakeX, lakeY, 0);
	square.at(lake.y).at(lake.x) = 3;

	int timeLimit = 0;
	cin >> timeLimit;

	queue<Position> qq;
	qq.push(lake);

	int result = bfs(square, qq, timeLimit);
	if (0 == result){
		cout << "OH, MY GOD" << endl;
	}
	else{
		cout << result << endl;
	}

	return 0;
}