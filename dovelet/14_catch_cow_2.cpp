#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node{
	int position;
	int count;
	Node(int position, int count) :position(position), count(count){}
};

int bfs(queue<Node>& qq, vector<bool>& visitiedNode, int destination)
{
	while (1){
		Node here = qq.front();
		qq.pop();

		if (1 == visitiedNode.at(here.position)){
			continue;
		}
		else{
			visitiedNode.at(here.position) = 1;
		}

		if (here.position == destination){
			return here.count;
		}

		if (here.position - 1 > 0){
			Node next(here.position - 1, here.count + 1);
			qq.push(next);
		}
		{
			Node next(here.position + 1, here.count + 1);
			qq.push(next);
		};
		if (here.position < destination){
			Node next(here.position * 2, here.count + 1);
			qq.push(next);
		};
	}
}

int main()
{
	int johnPosition = 0;
	int cowPosition = 0;
	cin >> johnPosition >> cowPosition;

	if (johnPosition > cowPosition){
		cout << johnPosition - cowPosition << endl;
		return 0;
	}

	queue<Node> qq;
	Node start(johnPosition, 0);
	qq.push(start);

	vector<bool> visitiedNode(cowPosition * 2, 0);

	cout << bfs(qq, visitiedNode, cowPosition) << endl;

	return 0;
}