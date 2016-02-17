#include <iostream>
#include <vector>
using namespace std;

int min(int a, int b)
{
	if (a > b){
		return b;
	}
	else{
		return a;
	}
}

void dfs(const vector<vector<int> >& adjMap, vector<int>& visited, const vector<int>& switchDefalutValue, int currentNode, int endNode, bool& found, int count, int& result)
{
	if (count >= result){
		return;
	}
	if (currentNode == endNode){
		found = true;
		result = count;
	}
	visited.at(currentNode) = 1;

	int returnValue = 101;
	for (int i = 1; i < adjMap.at(currentNode).size(); ++i){
		if (1 == adjMap.at(currentNode).at(i) && 0 == visited.at(i)){
			if (switchDefalutValue.at(currentNode) == i){
				dfs(adjMap, visited, switchDefalutValue, i, endNode, found, count, result);
			}
			else{
				dfs(adjMap, visited, switchDefalutValue, i, endNode, found, count + 1, result);
			}
		}
	}
	visited.at(currentNode) = 0;
}

int main()
{
	int nNode = 0;
	int startNode = 0;
	int endNode = 0;
	cin >> nNode >> startNode >> endNode;

	vector<vector<int> > adjMap(nNode + 1, vector<int>(nNode + 1, 0));
	vector<int> visited(nNode + 1, 0);
	vector<int> switchDefalutValue(nNode + 1, 0);

	for (int i = 1; i <= nNode; ++i){
		int nEdge = 0;
		cin >> nEdge;
		cin >> switchDefalutValue.at(i);
		adjMap.at(i).at(switchDefalutValue.at(i)) = 1;
		for (int j = 1; j < nEdge; ++j){
			int temp = 0;
			cin >> temp;
			adjMap.at(i).at(temp) = 1;
		}
	}

	bool found = false;
	int result = 101;
	dfs(adjMap, visited, switchDefalutValue, startNode, endNode, found, 0, result);
	if (true == found){
		cout << result << endl;
	}
	else{
		cout << -1 << endl;
	}

	return 0;
}