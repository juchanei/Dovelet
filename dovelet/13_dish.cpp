// 스택 고급?문제 주요 유형
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

	// 입력 문자열 길이 측정
	int size = 0;
	while (in[size]){
		size++;
	}

	// push와 pop 내역을 기록. push, pop, push, pop....
	char history[100] = { 0, };
	int countHistory = 0;

	// 스택에 넣을 접시. a,b,c,d,e...
	char dish[31] = { 0, };
	int countDish = 0;
	for (int i = 0; i < 31; i++) {
		dish[i] = 'a' + i;
	}

	// 일단 첫번째 접시는 push한다
	pushStack(dish[countDish]);
	countDish++;
	history[countHistory] = PUSH;
	countHistory++;

	// a,b,c,d 순서로, 스택에서 모든 접시를 push-pop 할 때 까지 반복
	for (int i = 0; i < size; i++) {
		if (countDish > size){						// 접시가 남으면 impossible
			cout << "impossible" << endl;
			return 0;
		}
		else if (isEmptyStack()) {					// 스택이 비면 push
			pushStack(dish[i]);
			countDish++;
			history[countHistory] = PUSH;
			countHistory++;
			// 아직 pop 하지 않았으므로 i를 증가시키지 않음
			i--;
		}
		else if (stack[topStack - 1] == in[i]) {		// 스택의 top이 이번 차례의 접시와 같으면 pop
			popStack();
			history[countHistory] = POP;
			countHistory++;
		}
		else if (stack[topStack - 1] != in[i]) {		// 스택의 top이 이번 차례의 접시와 다르면 push
			pushStack(dish[countDish]);
			countDish++;
			history[countHistory] = PUSH;
			countHistory++;
			i--;
		}
	}

	// 출력
	for (int i = 0; i < countHistory; i++) {
		if (history[i] == PUSH) cout << "push" << endl;
		else cout << "pop" << endl;
	}

	return 0;
}