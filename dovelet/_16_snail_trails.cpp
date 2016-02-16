#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum DIRECTION
{
	UP = 0,
	DOWN,
	LEFT,
	RIGHT,
	UNDEFINED
};

const int moveValue[4][2] = {
	{ 0, -1 },	//up
	{ 0, 1 },	//down
	{ -1, 0 },	//left
	{ 1, 0 }	//right
};

inline int max(const int a, const int b)
{
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}

int dfs(const vector<vector<int> >& square, vector<vector<int> >& visited, int xx, int yy, DIRECTION dir)
{

	visited.at(yy).at(xx) = 1;
	int returnValue = 0;
	int directMoveValue = 0;
	while (0 == square.at(yy + moveValue[dir][1]).at(xx + moveValue[dir][0])
		&& 0 == visited.at(yy + moveValue[dir][1]).at(xx + moveValue[dir][0])) {
		xx = xx + moveValue[dir][0];
		yy = yy + moveValue[dir][1];
		visited.at(yy).at(xx) = 1;
		++directMoveValue;
	}

	for (int i = 0; i < 4; ++i) {
		if (0 == square.at(yy + moveValue[i][1]).at(xx + moveValue[i][0])
			&& 0 == visited.at(yy + moveValue[i][1]).at(xx + moveValue[i][0])) {
			returnValue = max(returnValue, dfs(square, visited, xx, yy, static_cast<DIRECTION>(i)));
		}
	}

	visited.at(yy).at(xx) = 0;
	while (1 == visited.at(yy + moveValue[dir][1]).at(xx + moveValue[dir][0])) {
		xx = xx + moveValue[dir][0];
		yy = yy + moveValue[dir][1];
		visited.at(yy).at(xx) = 0;
	}
	return returnValue + directMoveValue;
}

int str2int(string input)
{
	int result = 0;
	for (int i = 0; i < input.size(); ++i) {
		result *= 10;
		result += input.at(i) - '0';
	}
	return result;
}

int main()
{
	int squareSize = 0;
	int nBlock = 0;
	cin >> squareSize >> nBlock;

	vector<vector<int> > square(squareSize + 2, vector<int>(squareSize + 2, 0));
	vector<vector<int> > visited(squareSize + 2, vector<int>(squareSize + 2, 0));
	for (int i = 1; i <= squareSize; ++i) {
		square.at(0).at(i) = 1;
		square.at(squareSize + 1).at(i) = 1;
		square.at(i).at(0) = 1;
		square.at(i).at(squareSize + 1) = 1;
	}

	char xx = 0;
	string yy;
	for (int i = 0; i < nBlock; ++i) {
		cin >> xx;
		cin >> yy;
		square.at(str2int(yy)).at(xx - 'A' + 1) = 1;
	}

	int result = 0;
	result = max(result, dfs(square, visited, 1, 1, RIGHT));
	result = max(result, dfs(square, visited, 1, 1, DOWN));
	cout << result + 1<< endl;;

	return 0;
}