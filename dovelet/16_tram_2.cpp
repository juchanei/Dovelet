#include <iostream>
#include <vector>
using namespace std;

void dfs(const vector<vector<int> >& adjList, vector<int>& visitiedNode, int currentNode, int destNode, int count, int& result)
{
	if (0 <= result && count > result){
		return;
	}
	if (destNode == currentNode){
		result = count;
		return;
	}
	visitiedNode.at(currentNode) = 1;

	for (int i = 0; i < adjList.at(currentNode).size(); ++i){
		int nextNode = adjList.at(currentNode).at(i);
		if (0 == visitiedNode.at(nextNode)){
			if (0 == i){
				dfs(adjList, visitiedNode, nextNode, destNode, count, result);
			}
			else{
				dfs(adjList, visitiedNode, nextNode, destNode, count + 1, result);
			}
		}
	}

	visitiedNode.at(currentNode) = 0;
}

int main()
{
	int nNode = 0;
	int startNode = 0;
	int endNode = 0;
	cin >> nNode >> startNode >> endNode;

	vector<vector<int> > adjList(nNode + 1, vector<int>(0));
	vector<int> visitiedNode(nNode + 1, 0);

	for (int i = 1; i < adjList.size(); ++i){
		int nEdge = 0;
		cin >> nEdge;
		for (int j = 0; j < nEdge; j++)
		{	
			int nextNode = 0;
			cin >> nextNode;
			adjList.at(i).push_back(nextNode);
		}
	}

	int result = -1;
	dfs(adjList, visitiedNode, startNode, endNode, 0, result);
	cout << result << endl;

	return 0;
}