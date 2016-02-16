#include <iostream>
using namespace std;

int main()
{
	char in[101] = { 0, };
	cin >> in;

	int size = 0;
	while (in[size]){
		size++;
	}

	int reminder = size % 3;

	if (reminder > 0){
		for (int i = 0; i < reminder; i++){
			cout << in[i];
		}
	}
	else{
		for (int i = 0; i < 3; i++){
			cout << in[i];
		}
		reminder = 3;
	}

	for (int i = reminder; i < size; i++){
		cout << "," << in[i];
		i++;
		cout << in[i];
		i++;
		cout << in[i];
	}

	return 0;
}