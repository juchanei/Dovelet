#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int orderCheck(vector<vector<int> >& adjMap, int point)
{
	int nLine = 0;
	for (int i = 0; i < adjMap.size(); ++i) {
		if (1 == adjMap.at(point).at(i)) {
			++nLine;
		}
	}

	return nLine;
}

void dfs(vector<vector<int> >& adjMap, vector<int>& outdata, int currentPoint)
{
	for (int i = 1; i < adjMap.size(); ++i) {
		if (1 == adjMap.at(currentPoint).at(i)) {
			adjMap.at(currentPoint).at(i) = 2;
			adjMap.at(i).at(currentPoint) = 2;
			dfs(adjMap, outdata, i);
		}
	}
	outdata.push_back(currentPoint);
}

int main()
{
	int nPoint = 0;
	int nLine = 0;
	cin >> nPoint >> nLine;
	vector<vector<int> > adjMap(nPoint + 1, vector<int>(nPoint + 1, 0));
	vector<int> visited(nPoint + 1, 0);

	int temp1 = 0;
	int temp2 = 0;
	for (int i = 0; i < nLine; ++i) {
		cin >> temp1 >> temp2;
		adjMap.at(temp1).at(temp2) = 1;
		adjMap.at(temp2).at(temp1) = 1;
	}

	int startPoint = 1;
	int endPoint = 1;
	int isStartPoint = 0;
	int isEndPoint = 0;
	for (int i = 0; i <= nPoint; ++i) {
		int order = orderCheck(adjMap, i);
		if (0 != order%2) {
			if (0 == isStartPoint) {
				startPoint = i;
				isStartPoint = 1;
			}
			else if (0 == isEndPoint) {
				endPoint = i;
				isEndPoint = 1;
			}
			if (0 == isStartPoint && 0 == isEndPoint) {
				cout << 0 << endl;
				return 0;
			}
		}
	}
	
	vector<int> outdata;
	dfs(adjMap, outdata, startPoint);

	reverse(outdata.begin(), outdata.end());
	for (int i = 0; i < outdata.size(); ++i) {
		cout << outdata.at(i) << " ";
	}
	cout << endl;

	return 0;
}
