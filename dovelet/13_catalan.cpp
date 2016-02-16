#include <iostream>
using namespace std;

int stack[101] = { 0, };
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

int isEmptyStack()
{
	if (topStack == 0) return 1;
	else return 0;
}

int main()
{
	int size = 0;
	cin >> size;
	
	int in[101] = { 0, };
	for (int i = 0; i < size; i++) {
		cin >> in[i];
	}

	int number[101] = { 0, };
	int countNumber = 0;
	for (int i = 0; i < size; i++) {
		number[i] = i + 1;
	}

	pushStack(number[0]);
	countNumber++;

	for (int i = 0; i < size; i++) {
		if (countNumber > size) {
			cout << "NO" << endl;
			return 0;
		}
		else if (isEmptyStack()) {
			pushStack(number[countNumber]);
			countNumber++;
			i--;
		}
		else if (stack[topStack - 1] == in[i]) {
			popStack();
		}
		else if (stack[topStack - 1] != in[i]) {
			pushStack(number[countNumber]);
			countNumber++;
			i--;
		}
	}

	cout << "YES" << endl;

	return 0;
}