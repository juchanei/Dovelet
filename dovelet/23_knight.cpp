#include <iostream>
#include <queue>
using namespace std;

int map[1001][1001] = { 0, };

class Point
{
public:
	int x;
	int y;
	int count;
	Point(int x, int y, int count)
	{
		this->x = x;
		this->y = y;
		this->count = count;
	}
};

int main()
{
	cout << "#testcase" << (itr + 1) << endl;

	int startX = 0;
	int startY = 0;
	int endX = 0;
	int endY = 0;
	cin >> startX >> startY;
	cin >> endX >> endY;

	queue<Point> pointQueue;
	Point current(startX, startY, 0);
	pointQueue.push(current);

	while (1) {
		if (pointQueue.empty()) {
			cout << "stack is empty" << endl;
			break;
		}

		if (current.x == endX && current.y == endY) {
			cout << current.count << endl;
			return 0;
		}

		current = pointQueue.front();
		pointQueue.pop();

		if (current.x + 1 <= 1000 && current.y + 2 <= 1000 && map[current.x + 1][current.y + 2] == 0) {
			Point newPoint(current.x + 1, current.y + 2, current.count + 1);
			pointQueue.push(newPoint);
			map[current.x + 1][current.y + 2] = 1;
		}
		if (current.x + 2 <= 1000 && current.y + 1 <= 1000 && map[current.x + 2][current.y + 1] == 0) {
			Point newPoint(current.x + 2, current.y + 1, current.count + 1);
			pointQueue.push(newPoint);
			map[current.x + 2][current.y + 1] = 1;
		}

		if (current.y + 2 <= 1000 && current.x - 1 >= 0 && map[current.x - 1][current.y + 2] == 0) {
			Point newPoint(current.x - 1, current.y + 2, current.count + 1);
			pointQueue.push(newPoint);
			map[current.x - 1][current.y + 2] = 1;
		}
		if (current.y + 1 <= 1000 && current.x - 2 >= 0 && map[current.x - 2][current.y + 1] == 0) {
			Point newPoint(current.x - 2, current.y + 1, current.count + 1);
			pointQueue.push(newPoint);
			map[current.x - 2][current.y + 1] = 1;
		}

		if (current.x + 1 <= 1000 && current.y - 2 >= 0 && map[current.x + 1][current.y - 2] == 0) {
			Point newPoint(current.x + 1, current.y - 2, current.count + 1);
			pointQueue.push(newPoint);
			map[current.x + 1][current.y - 2] = 1;
		}
		if (current.x + 2 <= 1000 && current.y - 1 >= 0 && map[current.x + 2][current.y - 1] == 0) {
			Point newPoint(current.x + 2, current.y - 1, current.count + 1);
			pointQueue.push(newPoint);
			map[current.x + 2][current.y - 1] = 1;
		}

		if (current.x - 1 >= 0 && current.y - 2 >= 0 && map[current.x - 1][current.y - 2] == 0) {
			Point newPoint(current.x - 1, current.y - 2, current.count + 1);
			pointQueue.push(newPoint);
			map[current.x - 1][current.y - 2] = 1;
		}
		if (current.x - 2 >= 0 && current.y - 1 >= 0 && map[current.x - 2][current.y - 1] == 0) {
			Point newPoint(current.x - 2, current.y - 1, current.count + 1);
			pointQueue.push(newPoint);
			map[current.x - 2][current.y - 1] = 1;
		}
	}

	return 0;
}