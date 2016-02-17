#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int> > adjMat, vector<int>& visitedNode, int currentNode)
{
	visitedNode.at(currentNode) = 1;
	cout << currentNode << " ";

	for (int i = 0; i < adjMat.at(currentNode).size(); ++i){
		if (1 == adjMat.at(currentNode).at(i) && 0 == visitedNode.at(i)){
			dfs(adjMat, visitedNode, i);
		}
	}
}

int main()
{
	int nNode = 0;
	int startNode = 0;
	cin >> nNode >> startNode;

	vector<vector<int> > adjMat(nNode + 1, vector<int>(nNode + 1, 0));
	vector<int> visitedNode(nNode + 1, 0);

	while (!cin.eof()){
		int nodeA = 0;
		int nodeB = 0;
		cin >> nodeA >> nodeB;
		adjMat.at(nodeA).at(nodeB) = 1;
		adjMat.at(nodeB).at(nodeA) = 1;
	}

	dfs(adjMat, visitedNode, startNode);
	cout << endl;

	return 0;
}