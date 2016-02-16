#include <iostream>
using namespace std;

class MapElem
{
public:
	int up;
	int down;
	int left;
	int right;
};

class Position
{
public:
	int x;
	int y;
	int count;
	Position() {
		this->x = 0;
		this->y = 0;
		this->count = 0;
	}
	Position(int x, int y, int count) {
		this->x = x;
		this->y = y;
		this->count = count;
	}
};

MapElem graph[22][22] = { 0, };
int visited[22][22] = { 0, };
Position queue[401];
int front = 0;
int rear = 0;

void enqueue(Position pos)
{
	queue[rear] = pos;
	rear++;
}

Position dequeue()
{
	Position out = queue[front];
	front++;
	return out;
}

int isEmptyQueue()
{
	if (front == rear) return 1;
	else return 0;
}

void intit()
{
	front = 0;
	rear = 0;
	for (int i = 0; i < 401; i++) {
		queue[i].x = 0;
		queue[i].y = 0;
	}
}


int main()
{
	int n = 0;
	int m = 0;
	cin >> n >> m;

	char map[22][22] = { 0, };
	for (int i = 0; i < 22; i++) {
		map[i][0] = '1';
		map[i][n+1] = '1';
		map[0][i] = '1';
		map[m+1][i] = '1';
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i + 1][j] == '0') {
				graph[i][j].right = 1;
			}
			if (map[i - 1][j] == '0') {
				graph[i][j].left = 1;
			}
			if (map[i][j + 1] == '0') {
				graph[i][j].down = 1;
			}
			if (map[i][j - 1] == '0') {
				graph[i][j].up = 1;
			}
		}
	}

	Position current(n, 1, 1);
	visited[n][1] = 1;
	enqueue(current);

	int count = 0;
	while (1) {
		if (isEmptyQueue()) {
			break;
		}

		current = dequeue();
		int x = current.x;
		int y = current.y;
		count = current.count;

		if (x == 1 && y == m) {
			cout << count << endl;
			break;
		}


		if (graph[x][y].up == 1 && visited[x][y - 1] == 0) {
			Position temp(x, y - 1, count + 1);
			enqueue(temp);
			visited[x][y - 1] = 1;
		}
		if (graph[x][y].down == 1 && visited[x][y + 1] == 0) {
			Position temp(x, y + 1, count + 1);
			enqueue(temp);
			visited[x][y + 1] = 1;
		}
		if (graph[x][y].left == 1 && visited[x - 1][y] == 0) {
			Position temp(x - 1, y, count + 1);
			enqueue(temp);
			visited[x - 1][y] = 1;
		}
		if (graph[x][y].right == 1 && visited[x + 1][y] == 0) {
			Position temp(x + 1, y, count + 1);
			enqueue(temp);
			visited[x + 1][y] = 1;
		}
	}

	return 0;
}