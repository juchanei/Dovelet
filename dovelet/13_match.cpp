#include <iostream>
using namespace std;

char stack[101] = { 0, };
int stackPointer = 0;

void pushStack(char inChar)
{
	if (stackPointer >= 0 && stackPointer < 101){
		stack[stackPointer] = inChar;
		stackPointer++;
	}
	else{
		cout << "stack push error : out of range" << endl;
	}
}

char popStack()
{
	if (stackPointer > 0){
		char outChar = 0;
		stackPointer--;
		outChar = stack[stackPointer];

		return outChar;
	}
	else{
		cout << "stack pop error : out of range" << endl;
		return 0;
	}
}

int isStackEmpty()
{
	if (stackPointer == 0){
		return 1;
	}
	else{
		return 0;
	}
}

int main()
{
	char in[51] = { 0, };
	cin >> in;

	// 길이 계산
	int size = 0;
	while (in[size]){
		size++;
	}

	// 괄호가 유효한지 확인
	int checker = 0;
	for (int i = 0; i < size; i++){
		if (in[i] == '('){
			checker += 1;
		}
		else if (in[i] == ')'){
			if (checker == 0){
				cout << "not match" << endl;
				return 0;
			}
			else{
				checker -= 1;
			}
		}
	}

	// 괄호가 유효하다면 위치 출력
	if (checker == 0){
		for (int i = 0; i < size; i++){
			if (in[i] == '('){
				pushStack(in[i]);
				pushStack(i);
			}
			else if (in[i] == ')'){
				cout << (int)popStack() << " " << i << endl;
				popStack();
			}
		}
		return 0;
	}
	else{
		cout << "not match" << endl;
		return 0;
	}

}