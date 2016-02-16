#include <iostream>
using namespace std;

int queue[101] = { 0, };
int front = 0;
int rear = 0;
int visited[101] = { 0, };

void enqueue(int in)
{
	queue[rear] = in;
	rear++;
}

int dequeue()
{
	int out = queue[front];
	front++;
	return out;
}

int isEmptyQueue()
{
	if (front == rear) return 1;
	else return 0;
}

int main()
{
	int numComputer = 0;
	cin >> numComputer;
	int numEdge = 0;
	cin >> numEdge;

	int network[101][101] = { 0, };
	for (int i = 0; i < numEdge; i++) {
		int from = 0;
		int to = 0;
		cin >> from >> to;
		network[from][to] = 1;
		network[to][from] = 1;
	}

	int current = 1;
	enqueue(current);
	visited[current] = 1;
	int count = 0;

	while (1) {
		current = dequeue();
		for (int i = 1; i <= numComputer; i++) {
			if (network[current][i] == 1 && visited[i] == 0) {
				enqueue(i);
				visited[i] = 1;
				count++;
			}
		}

		if (isEmptyQueue()) {
			cout << count << endl;
			break;
		}
	}

	return 0;
}