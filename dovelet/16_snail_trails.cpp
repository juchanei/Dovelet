#include <iostream>
#include <vector>
#include <string>
using namespace std;

enum Direction{
	UP = 0, DOWN, LEFT, RIGHT
};

const int directionValue[4][2] = {
	0, -1,	//up
	0, 1,	//down
	-1, 0,	//left
	1, 0	//right
};

vector<int> getPositonFromStr(const string str)
{
	vector<int> outData(2, 0);
	outData.at(0) = static_cast<int>(str.at(0) - 'A' + 1);

	outData.at(1) = 0;
	for (int i = 1; i < str.size(); ++i){
		outData.at(1) *= 10;
		outData.at(1) += static_cast<int>(str.at(i) - '0');
	}

	return outData;
}

int moveAndVisit(const vector<vector<int> >& square, vector<vector<int> >& visited, int& xx, int& yy, const Direction dir, bool& endFlag)
{
	int moveValue = 0;
	visited.at(yy).at(xx) = 1;
	while (0 == square.at(yy + directionValue[dir][1]).at(xx + directionValue[dir][0]) && 0 == visited.at(yy + directionValue[dir][1]).at(xx + directionValue[dir][0])){
		xx += directionValue[dir][0];
		yy += directionValue[dir][1];
		visited.at(yy).at(xx) = 1;
		++moveValue;
	}

	if (1 == visited.at(yy + directionValue[dir][1]).at(xx + directionValue[dir][0])){
		endFlag = true;
	}

	return moveValue;
}

void cancelVisit(const vector<vector<int> >& square, vector<vector<int> >& visited, int& xx, int& yy, const Direction dir, int moveValue)
{
	visited.at(yy).at(xx) = 0;
	for (int i = 0; i < moveValue; ++i){
		xx -= directionValue[dir][0];
		yy -= directionValue[dir][1];
		visited.at(yy).at(xx) = 0;
	}
}

int max(int aa, int bb)
{
	if (aa > bb){
		return aa;
	}
	else{
		return bb;
	}
}

int dfs(const vector<vector<int> >& square, vector<vector<int> >& visited, int xx, int yy, Direction dir)
{
	bool endFlag = false;
	int moveValue = moveAndVisit(square, visited, xx, yy, dir, endFlag);
	if (true == endFlag){
		cancelVisit(square, visited, xx, yy, dir, moveValue);
		return moveValue;
	}

	int returnValue = 0;
	for (int i = 0; i < 4; ++i){
		if (0 == square.at(yy + directionValue[i][1]).at(xx + directionValue[i][0]) && 0 == visited.at(yy + directionValue[i][1]).at(xx + directionValue[i][0])){
			returnValue = max(returnValue, dfs(square, visited, xx, yy, static_cast<Direction>(i)));
		}
	}

	cancelVisit(square, visited, xx, yy, dir, moveValue);
	return returnValue + moveValue;
}

int main()
{
	int squareSize = 0;
	int nBlock = 0;
	cin >> squareSize >> nBlock;

	vector<vector<int> > square(squareSize + 2, vector<int>(squareSize + 2, 0));
	vector<vector<int> > visited(squareSize + 2, vector<int>(squareSize + 2, 0));
	for (int i = 1; i <= squareSize; ++i){
		square.at(0).at(i) = 1;
		square.at(squareSize + 1).at(i) = 1;
		square.at(i).at(0) = 1;
		square.at(i).at(squareSize + 1) = 1;
	}

	for (int i = 0; i < nBlock; ++i){
		string inputStr;
		cin >> inputStr;
		vector<int> position = getPositonFromStr(inputStr);
		square.at(position.at(1)).at(position.at(0)) = 1;
	}

	int result = 0;
	int endflag = false;
	result = max(result, dfs(square, visited, 1, 1, RIGHT));
	result = max(result, dfs(square, visited, 1, 1, DOWN));

	cout << result + 1 << endl;

	return 0;
}