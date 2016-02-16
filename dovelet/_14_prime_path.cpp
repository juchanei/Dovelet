// ¹ÌÇØ°á

#include <iostream>
using namespace std;

class Elem
{
public:
	int value;
	int count;
	Elem()
	{
		this->count = 0;
		this->value = 0;
	}
	Elem(int value, int count)
	{
		this->count = count;
		this->value = value;
	}
};

Elem queue[10000];
int front = 0;
int rear = 0;
int visited[10000] = { 0, };

void enqueue(Elem in)
{
	queue[rear] = in;
	rear++;
}

Elem dequeue()
{
	Elem out = queue[front];
	front++;
	return out;
}

int isEmptyQueue()
{
	if (front == rear) return 1;
	else return 0;
}

int isPrime(int in)
{
	int temp = in;
	for (int i = 2; i<temp; i++) {
		if (in % i == 0) return false;
		temp = (in + 1) / i;
	}
	return true;
}

int main()
{
	int a = 0;
	int b = 0;
	cin >> a >> b;

	Elem current(a, 0);
	enqueue(current);
	visited[a] = 1;
	int count = 0;

	while (1) {
		current = dequeue();
		int value = current.value;


		for (int i = 1; i <= 9; i++) {
			int temp = (current.value % 10);
			temp = current.value - temp;
			temp += i;
			if (isPrime(temp) && visited[temp] == 0) {
				Elem newElem(temp, current.count + 1);
				enqueue(newElem);
				visited[temp] = 1;
			}
		}
		for (int i = 1; i <= 9; i++) {
			int temp = (current.value % 100) / 10 * 10;
			temp = current.value - temp;
			temp += (i * 10);
			if (isPrime(temp) && visited[temp] == 0) {
				Elem newElem(temp, current.count + 1);
				enqueue(newElem);
				visited[temp] = 1;
			}
		}
		for (int i = 1; i <= 9; i++) {
			int temp = (current.value % 1000) / 100 * 100;
			temp = current.value - temp;
			temp += (i * 100);
			if (isPrime(temp) && visited[temp] == 0) {
				Elem newElem(temp, current.count + 1);
				enqueue(newElem);
				visited[temp] = 1;
			}
		}
		for (int i = 1; i <= 9; i++) {
			int temp = current.value / 1000 * 1000;
			temp = current.value - temp;
			temp += (i * 1000);
			if (isPrime(temp) && visited[temp] == 0) {
				Elem newElem(temp, current.count + 1);
				enqueue(newElem);
				visited[temp] = 1;
			}
		}

		if (current.value == b) {
			cout << current.count << endl;
			break;
		}
		//if (isEmptyQueue()) {
		//	cout << 0 << endl;
		//	break;
		//}

	}

	return 0;
}