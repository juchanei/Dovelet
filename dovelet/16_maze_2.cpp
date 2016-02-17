#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int> >& map, int currentX, int currentY)
{
	
}

int main()
{
	int width = 0;
	int height = 0;
	cin >> width >> height;

	vector<vector<int> > map(height + 2, vector<int>(width + 2, 0));

	for (int i = 1; i <= height; ++i){
		char buffer[22] = { 0, };
		cin >> buffer;
		for (int j = 0; j < width; ++j){
			map.at(i).at(j + 1) = buffer[j] - '0';
		}
	}



	return 0;
}