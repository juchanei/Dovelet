#include <iostream>
#include <vector>
using namespace std;

int dfs(vector<vector<int> > adjMat, vector<int>& visitedNode, int currentNode)
{
	visitedNode.at(currentNode) = 1;

	int returnValue = 0;
	for (int i = 1; i < adjMat.at(currentNode).size(); ++i){
		if (1 == adjMat.at(currentNode).at(i) && 0 == visitedNode.at(i)){
			returnValue += dfs(adjMat, visitedNode, i);
		}
	}
	
	return returnValue + 1;
}

int main()
{
	int nCompuer = 0;
	int nEdge = 0;
	cin >> nCompuer >> nEdge;

	vector<vector<int> > adjMat(nCompuer + 1, vector<int>(nCompuer + 1, 0));
	vector<int> visitedNode(nCompuer + 1, 0);

	for (int i = 0; i < nEdge; ++i){
		int nodeA = 0;
		int nodeB = 0;
		cin >> nodeA >> nodeB;

		adjMat.at(nodeA).at(nodeB) = 1;
		adjMat.at(nodeB).at(nodeA) = 1;
	}

	cout << dfs(adjMat, visitedNode, 1) - 1 << endl;

	return 0;
}