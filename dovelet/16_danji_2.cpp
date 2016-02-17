#include <iostream>
#include <vector>
using namespace std;

const int direction[4][2] = {
	{ 0, -1 },	//up
	{ 0, 1 },	//down
	{ -1 , 0},	//left
	{ 1, 0}		//right
};

int dfs(vector<vector<int> >& square, int currentX, int currentY)
{
	square.at(currentY).at(currentX) = 3;

	int result = 0;
	for (int i = 0; i < 4; ++i){
		if (1 == square.at(currentY + direction[i][1]).at(currentX + direction[i][0])){
			result += dfs(square, currentX + direction[i][0], currentY + direction[i][1]);
		}
	}

	return result + 1;
}

void sort(vector<int>& outdata)
{
	for (int i = 0; i < outdata.size(); ++i){
		for (int j = i + 1; j < outdata.size(); ++j){
			if (outdata.at(i) > outdata.at(j))
			{
				int temp = outdata.at(i);
				outdata.at(i) = outdata.at(j);
				outdata.at(j) = temp;
			}
		}
	}
}

int main()
{
	int squareSize = 0;
	cin >> squareSize;

	vector<vector<int> > square(squareSize + 2, vector<int>(squareSize + 2, 0));
	vector<int> visited(squareSize + 2, 0);

	for (int i = 1; i < square.size() - 1; ++i){
		for (int j = 1; j < square.at(i).size() - 1; ++j){
			cin >> square.at(i).at(j);
		}
	}

	vector<int> outdata;
	for (int i = 1; i < square.size() - 1; ++i){
		for (int j = 1; j < square.at(i).size() - 1; ++j){
			if (1 == square.at(i).at(j)){
				outdata.push_back(dfs(square, j, i));
			}
		}
	}

	sort(outdata);

	cout << outdata.size() << endl;
	for (int i = 0; i < outdata.size(); ++i){
		cout << outdata.at(i) << endl;
	}

	return 0;
}