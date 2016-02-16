// 미해결 - 잘 되는거 같은데 안된다...

#include <iostream>
using namespace std;

char stack[1001] = { 0, };
int pointerStack = 0;

void pushStack(int in)
{
	stack[pointerStack] = in;
	pointerStack++;
}

int popStack()
{
	pointerStack--;
	return stack[pointerStack];
}

int isEmptyStack()
{
	if (pointerStack == 0) return 1;
	else return 0;
}

int main()
{
	int inputSize = 0;
	cin >> inputSize;

	int iter = 0;
	while (1) {
		int in[1001] = { 0, };
		for (int i = 0; i < inputSize; i++)	cin >> in[i];
		if (in[0] == 0) return 0;

		int size = 0;
		while (in[size]) size++;

		char train[1001] = { 0, };
		int countTrain = 0;
		for (int i = 0; i < size; i++) {
			train[i] = i + 1;
		}

		pushStack(train[0]);
		countTrain++;
		int flag = 0;
		for (int i = 0; i < size; i++) {
			if (countTrain > size) {
				cout << "No" << endl;
				flag = 1;
				break;
			}
			else if (isEmptyStack()) {
				pushStack(train[countTrain]);
				countTrain++;
				i--;
			}
			else if (in[i] == stack[pointerStack - 1]) {
				popStack();
			}
			else if (in[i] != stack[pointerStack - 1]) {
				pushStack(train[countTrain]);
				countTrain++;
				i--;
			}
		}
		if (flag == 0) {
			cout << "Yes" << endl;
		}
		iter++;
	}


	return 0;
}