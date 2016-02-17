#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(vector<vector<int> >& adjList, vector<int>& visitedNode, int here, int& count, bool& found)
{
	visitedNode.at(here) = 1;
	cout << here << " ";
	++count;

	if (count == adjList.size() - 1){
		found = true;
		return;
	}

	for (int i = 0; i < adjList.at(here).size(); ++i){
		if (0 == visitedNode.at(adjList.at(here).at(i))){
			dfs(adjList, visitedNode, adjList.at(here).at(i), count, found);
			if (true == found) return;
		}
	}
}

int main()
{
	int nNode = 0;
	int nEdge = 0;
	cin >> nNode >> nEdge;

	vector<vector<int> > adjList(nNode + 1, vector<int>(0, 0));
	vector<int> visitedNode(nNode + 1, 0);

	for (int i = 0; i < nEdge; ++i){
		int nodeA = 0;
		int nodeB = 0;
		cin >> nodeA >> nodeB;
		adjList.at(nodeA).push_back(nodeB);
		adjList.at(nodeB).push_back(nodeA);
	}

	for (int i = 1; i <= nNode; ++i){
		sort(adjList.at(i).begin(), adjList.at(i).end());
	}

	bool found = false;
	int count = 0;
	dfs(adjList, visitedNode, 1, count, found);
	cout << endl;

	return 0;
}