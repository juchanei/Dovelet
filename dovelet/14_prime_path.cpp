#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node{
	int value;
	int count;
	Node(int value, int count) :value(value), count(count){}
};

int changeNumber(int targetValue, int digit, int value)
{
	int temp = targetValue;
	int tempdigit = 1;
	for (int i = 0; i < digit; ++i){
		tempdigit *= 10;
	}
	temp /= tempdigit;
	temp %= 10;

	targetValue -= tempdigit * temp;
	targetValue += tempdigit * value;

	return targetValue;
}

int bfs(queue<Node>& qq, vector<int>& visitedNode, vector<bool>& prime, const int& destination)
{
	while (1){
		Node here = qq.front();
		qq.pop();

		if (here.value < 1000){
			continue;
		}

		if (1 == visitedNode.at(here.value)){
			continue;
		}
		else{
			visitedNode.at(here.value) = 1;
		}
		if (destination == here.value){
			return here.count;
		}

		for (int i = 0; i < 4; ++i){
			for (int j = 0; j < 10; ++j){
				int newNumber = changeNumber(here.value, i, j);
				if (prime.at(newNumber)){
					Node next(newNumber, here.count + 1);
					qq.push(next);
				}
			}
		}
	}
}

int main()
{
	int startPrime = 0;
	int endPrime = 0;
	cin >> startPrime >> endPrime;

	queue<Node> qq;
	Node start(startPrime, 0);
	qq.push(start);

	vector<int> visitedNode(10000, 0);

	vector<bool> prime(10000, true);
	for (int i = 2; i < prime.size(); ++i){
		if (true == prime.at(i)){
			for (int j = 2 * i; j < prime.size(); j = j + i){
				prime.at(j) = false;
			}
		}
	}

	cout << bfs(qq, visitedNode, prime, endPrime) << endl;

	return 0;
}