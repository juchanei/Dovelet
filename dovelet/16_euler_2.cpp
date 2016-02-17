#include <iostream>
#include <vector>
using namespace std;

bool isEuler(vector<vector<int> > adjMat, int& startNode, int& endNode)
{
	int nOddOrderNode = 0;
	for (int i = 1; i < adjMat.size(); ++i){
		int sum = 0;
		for (int j = 1; j < adjMat.at(i).size(); ++j){
			if (1 == adjMat.at(i).at(j)){
				++sum;
			}
		}
		if (sum % 2){
			++nOddOrderNode;
			if (1 == nOddOrderNode){
				startNode = i;
			}
			else if (2 == nOddOrderNode){
				endNode = i;
			}
			else {
				return false;
			}
		}
	}

	return true;
}

void dfs(vector<vector<int> >& adjMat, int currentNode, vector<int>& outdata)
{
	for (int i = 1; i < adjMat.at(currentNode).size(); ++i){
		if (1 == adjMat.at(currentNode).at(i))
		{
			adjMat.at(currentNode).at(i) = 0;
			adjMat.at(i).at(currentNode) = 0;
			dfs(adjMat, i, outdata);
		}
	}

	outdata.push_back(currentNode);
}

int main()
{
	int nNode = 0;
	int nEdge = 0;
	cin >> nNode >> nEdge;

	vector<vector<int> > adjMat(nNode + 1, vector<int>(nNode + 1, 0));

	for (int i = 0; i < nEdge; ++i){
		int nodeA = 0;
		int nodeB = 0;
		cin >> nodeA >> nodeB;

		adjMat.at(nodeA).at(nodeB) = 1;
		adjMat.at(nodeB).at(nodeA) = 1;
	}

	int startNode = 1;
	int endNode = 0;
	vector<int> outdata;
	if (isEuler(adjMat, startNode, endNode)){
		dfs(adjMat, startNode, outdata);
	}
	
	for (int i = outdata.size() - 1; i >= 0; --i){
		cout << outdata.at(i) << " ";
	}
	cout << endl;

	return 0;
}