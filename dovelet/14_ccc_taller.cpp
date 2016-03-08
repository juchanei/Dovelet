#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool bfs(const vector<vector<int> >& adjList, const int start, const int end)
{
	queue<int> qq;
	qq.push(start);
	vector<int> visitedNode(adjList.size(), 0);

	while (!qq.empty()){
		const int here = qq.front();
		qq.pop();

		if (here == end){
			return true;
		}

		for (int i = 0; i < adjList.at(here).size(); ++i){
			const int next = adjList.at(here).at(i);
			if (0 == visitedNode.at(next)){
				qq.push(next);
				visitedNode.at(next) = 1;
			}
		}
	}
	
	return false;
}

int main()
{
	int nNode = 0;
	int nEdge = 0;
	cin >> nNode >> nEdge;

	vector<vector<int> > adjList(nNode + 1, vector<int>(0));

	for (int i = 0; i < nEdge; ++i){
		int nodeA = 0;
		int nodeB = 0;
		scanf("%d%d", &nodeA, &nodeB);

		adjList.at(nodeA).push_back(nodeB);
	}

	int bigNode = 0;
	int smallNode = 0;
	cin >> bigNode >> smallNode;

	if (bfs(adjList, bigNode, smallNode)){
		cout << "yes" << endl;
		return 0;
	}
	else if (bfs(adjList, smallNode, bigNode)){
		cout << "no" << endl;
		return 0;
	}

	cout << "unknown" << endl;

	return 0;
}