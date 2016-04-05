#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
	int val;
	int count;
	Node(int val, int count) : val(val), count(count) {}
	Node() : val(0), count(0) {}
};

int bfs(int start, int dest)
{
	vector<int> visited(dest * 2 + 1, 0);
	Node startNode(start, 0);
	queue<Node> qq;
	qq.push(startNode);
	visited[startNode.val] = 1;

	while (!qq.empty()) {
		Node here = qq.front();
		qq.pop();

		if (here.val == dest) {
			return here.count;
		}

		if (here.val + 1 < visited.size() && 0 == visited[here.val + 1]) {
			Node next(here.val + 1, here.count + 1);
			qq.push(next);
			visited[next.val] = 1;
		}
		if (0 <= here.val - 1 && 0 == visited[here.val - 1]) {
			Node next(here.val - 1, here.count + 1);
			qq.push(next);
			visited[next.val] = 1;
		}
		if (here.val * 2 < visited.size() && 0 == visited[here.val * 2] && here.val < dest) {
			Node next(here.val * 2, here.count + 1);
			qq.push(next);
			visited[next.val] = 1;
		}
	}

	return 0;
}

int main()
{
	int start, dest;
	cin >> start >> dest;

	if (dest < start) {
		cout << start - dest << endl;
		return 0;
	}

	cout << bfs(start, dest) << endl;

	return 0;
}