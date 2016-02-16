// ���� ���?���� �ֿ� ����
#include <iostream>
using namespace std;

#define PUSH	1
#define POP		2

char stack[31] = { 0, };
int topStack = 0;

void pushStack(char in)
{
	stack[topStack] = in;
	topStack++;
}

char popStack()
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
	char in[31] = { 0, };
	cin >> in;

	// �Է� ���ڿ� ���� ����
	int size = 0;
	while (in[size]){
		size++;
	}

	// push�� pop ������ ���. push, pop, push, pop....
	char history[100] = { 0, };
	int countHistory = 0;

	// ���ÿ� ���� ����. a,b,c,d,e...
	char dish[31] = { 0, };
	int countDish = 0;
	for (int i = 0; i < 31; i++) {
		dish[i] = 'a' + i;
	}

	// �ϴ� ù��° ���ô� push�Ѵ�
	pushStack(dish[countDish]);
	countDish++;
	history[countHistory] = PUSH;
	countHistory++;

	// a,b,c,d ������, ���ÿ��� ��� ���ø� push-pop �� �� ���� �ݺ�
	for (int i = 0; i < size; i++) {
		if (countDish > size){						// ���ð� ������ impossible
			cout << "impossible" << endl;
			return 0;
		}
		else if (isEmptyStack()) {					// ������ ��� push
			pushStack(dish[i]);
			countDish++;
			history[countHistory] = PUSH;
			countHistory++;
			// ���� pop ���� �ʾ����Ƿ� i�� ������Ű�� ����
			i--;
		}
		else if (stack[topStack - 1] == in[i]) {		// ������ top�� �̹� ������ ���ÿ� ������ pop
			popStack();
			history[countHistory] = POP;
			countHistory++;
		}
		else if (stack[topStack - 1] != in[i]) {		// ������ top�� �̹� ������ ���ÿ� �ٸ��� push
			pushStack(dish[countDish]);
			countDish++;
			history[countHistory] = PUSH;
			countHistory++;
			i--;
		}
	}

	// ���
	for (int i = 0; i < countHistory; i++) {
		if (history[i] == PUSH) cout << "push" << endl;
		else cout << "pop" << endl;
	}

	return 0;
}