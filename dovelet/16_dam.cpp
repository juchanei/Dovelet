#include <iostream>
using namespace std;

class Point
{
public:
	int x;
	int y;
	int time;
};

int damCount[101] = { 0, };
Point queue[10001];
int front = 0;
int rear = 0;

void enqueue(Point a)
{
	queue[rear] = a;
	rear++;
}

Point dequeue()
{
	Point out = queue[front];
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
	int size = 0;
	cin >> size;

	int map[102][102] = { 0, };
	for (int i = 1; i <= size; i++) {
		for (int j = 1; j <= size; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < size + 2; i++) {
		map[i][0] = 1;
		map[i][size + 1] = 1;
		map[0][i] = 1;
		map[size + 1][i] = 1;
	}

	Point lake;
	cin >> lake.x >> lake.y;
	lake.time = 0;
	map[lake.x][lake.y] = 1;

	int buildingTime = 0;
	cin >> buildingTime;

	enqueue(lake);
	Point current;
	while (1) {
		current = dequeue();
		int x = current.x;
		int y = current.y;
		int time = current.time;
		if (map[x + 1][y] != 1) {
			current.x = x + 1;
			current.y = y;
			current.time = time + 1;
			map[current.x][current.y] = 1;
			damCount[time + 1]++;
			enqueue(current);
		}
		if (map[x - 1][y] != 1) {
			current.x = x - 1;
			current.y = y;
			current.time = time + 1;
			map[current.x][current.y] = 1;
			damCount[time + 1]++;
			enqueue(current);
		}
		if (map[x][y + 1] != 1) {
			current.x = x;
			current.y = y + 1;
			current.time = time + 1;
			map[current.x][current.y] = 1;
			damCount[time + 1]++;
			enqueue(current);
		}
		if (map[x][y - 1] != 1) {
			current.x = x;
			current.y = y - 1;
			current.time = time + 1;
			map[current.x][current.y] = 1;
			damCount[time + 1]++;
			enqueue(current);
		}
		if (isEmptyQueue())
		{
			if (damCount[buildingTime]) {
				cout << damCount[buildingTime] << endl;
				break;
			}
			else {
				cout << "OH, MY GOD" << endl;
				break;
			}
		}
		if (damCount[buildingTime+1]) {
			cout << damCount[buildingTime] << endl;
			break;
		}
	}

	return 0;
}