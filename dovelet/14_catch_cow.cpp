#include <iostream>
using namespace std;

class Position
{
public:
	int position;
	int count;
	Position() {}
	Position(int position, int count)
	{
		this->position = position;
		this->count = count;
	}
};

Position queue[1000000];
int front = 0;
int rear = 0;

void enqueue(Position data)
{
	queue[rear] = data;
	rear++;
}

Position dequeue()
{
	Position outdata = queue[front];
	front++;
	return outdata;
}

int isEmpty()
{
	if (front == rear) {
		return 1;
	}
	else {
		return 0;
	}
}

void init()
{
	front = 0;
	rear = 0;
}

int main()
{
	int myPosition = 0;
	int cowPosition = 0;
	int visited[100001] = { 0, };
	cin >> myPosition >> cowPosition;

	if (cowPosition < myPosition) {
		cout << myPosition - cowPosition << endl;
		return 0;
	}

	Position currentPosition(myPosition, 0);
	enqueue(currentPosition);


	while (1) {
		currentPosition = dequeue();
		int position = currentPosition.position;
		int count = currentPosition.count;

		visited[position] = 1;
		if (position == cowPosition) {
			cout << count << endl;
			break;
		}

		if (position * 2 < 100000) {
			if (visited[position * 2] == 0) {
				Position nextPosition(position * 2, count + 1);
				enqueue(nextPosition);
			}
		}
		if (position + 1 < 100000) {
			if (visited[position + 1] == 0) {
				Position nextPosition(position + 1, count + 1);
				enqueue(nextPosition);
			}
		}
		if (visited[position - 1] == 0) {
			Position nextPosition(position - 1, count + 1);
			enqueue(nextPosition);
		}
		if (isEmpty()) {
			break;
		}
	}

	init();

	return 0;
}