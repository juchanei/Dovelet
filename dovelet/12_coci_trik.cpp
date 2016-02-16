#include <iostream>
using namespace std;

void swap(int* cups, int a, int b)
{
	int temp = cups[a];
	cups[a] = cups[b];
	cups[b] = temp;
}

int main()
{
	char in[51] = { 0, };
	int cups[3] = { 1, 0, 0 };
	cin >> in;

	int size = 0;
	while(in[size]){
		size++;
	}

	for (int i = 0; i < size; i++){
		switch (in[i]){
		case 'A':
			swap(cups, 0, 1);
			break;
		case 'B':
			swap(cups, 1, 2);
			break;
		case 'C':
			swap(cups, 0, 2);
			break;
		}
	}

	int ballPosition = 0;
	while (cups[ballPosition] != 1){
		ballPosition++;
	}
	cout << ballPosition + 1 << endl;

	return 0;
}