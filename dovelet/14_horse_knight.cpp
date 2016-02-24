#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node{
	int x;
	int y;
	int count;
	Node(int x, int y, int count) : x(x), y(y), count(count) {}
};

const char MOVE[8][2] = {
	-1, -2,
	1, -2,
	-1, 2,
	1, 2,
	-2, 1,
	-2, -1,
	2, 1,
	2, -1
};

const char DIRECTION[4][2] = {
	0, -1,
	0, 1,
	-1, 0,
	1, 0
};

inline int index(int i)
{
	return i + 1;
}

void bfsChess(vector<vector<int> >& map, int startX, int startY)
{
	queue<Node> qq;
	Node startNode(startX, startY, 1);
	qq.push(startNode);
	map.at(startY).at(startX) = 1;

	while (!qq.empty()){
		Node here = qq.front();
		qq.pop();

		for (int i = 0; i < 8; ++i){
			int nextX = here.x + MOVE[i][0];
			int nextY = here.y + MOVE[i][1];
			if (0 == map.at(nextY).at(nextX)){
				Node nextNode(nextX, nextY, here.count + 1);
				qq.push(nextNode);
				map.at(nextY).at(nextX) = nextNode.count;
			}
		}

	}
}

void bfsJanggi(vector<vector<int> >& map, int startX, int startY)
{
	queue<Node> qq;
	Node startNode(startX, startY, 1);
	qq.push(startNode);
	map.at(startY).at(startX) = 1;

	while (!qq.empty()){
		Node here = qq.front();
		qq.pop();

		for (int i = 0; i < 8; ++i){
			int nextX = here.x + MOVE[i][0];
			int nextY = here.y + MOVE[i][1];
			int dirX = here.x + DIRECTION[i / 2][0];
			int dirY = here.y + DIRECTION[i / 2][1];
			if (0 == map.at(nextY).at(nextX) && 1 != map.at(dirY).at(dirX)){
				Node nextNode(nextX, nextY, here.count + 1);
				qq.push(nextNode);
				map.at(nextY).at(nextX) = nextNode.count;
			}
		}
	}
}

int main()
{
	int mapSize = 0;
	int nBlock = 0;
	cin >> mapSize >> nBlock;

	vector<vector<int> > chessMap(mapSize + 4, vector<int>(mapSize + 4, -1));
	for (int i = index(1); i < chessMap.size() - 2; ++i){
		for (int j = index(1); j < chessMap.at(i).size() - 2; ++j)
		{
			scanf("%d", &chessMap.at(i).at(j));
		}
	}
	vector<vector<int> > janggiMap = chessMap;

	int startX = 0;
	int startY = 0;
	cin >> startY >> startX;

	bfsChess(chessMap, index(startX), index(startY));
	bfsJanggi(janggiMap, index(startX), index(startY));

	int count = 0;
	for (int i = index(1); i < chessMap.size() - 2; ++i){
		for (int j = index(1); j < chessMap.at(i).size() - 2; ++j)
		{
			if (janggiMap.at(i).at(j) - chessMap.at(i).at(j) != 0){
				++count;
			}
		}
	}

	cout << count << endl;

	return 0;
}