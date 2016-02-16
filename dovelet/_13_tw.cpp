// 미해결 - 시간초과ㅠ

#include <iostream>
using namespace std;

int stack[500001] = { 0, };
int topStack = 0;

void pushStack(int in)
{
	stack[topStack] = in;
	topStack++;
}

int popStack()
{
	topStack--;
	return stack[topStack];
}

int main()
{
	long long int numTower = 0;
	cin >> numTower;

	long long int tower[500001] = { 0, };
	for (int i = 0; i < numTower; i++) {
		cin >> tower[i];
	}

	for (int i = numTower - 1; i >= 0; i--) {
		int flag = 0;
		for (int j = 1; j <= i; j++) {
			if (tower[i] < tower[i - j]) {
				pushStack(i - j + 1);
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			pushStack(0);
		}
	}

	for (int i = 0; i < numTower; i++) {
		cout << popStack() << " ";
	}
	cout << endl;

	return 0;
}