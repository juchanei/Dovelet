#include <iostream>
using namespace std;

int main()
{
	char in[101] = { 0, };
	cin.getline(in, 101);

	int size = 0;
	while (in[size]){
		size++;
	}

	for (int i = 0; i < size; i++){
		if (in[i] != 'a' && in[i] != 'e' && in[i] != 'i' && in[i] != 'o' && in[i] != 'u'){
			cout << in[i];
		}
		else{
			if (in[i + 1] == 'p'){
				cout << in[i];
				i += 2;
			}
		}
	}

	return 0;
}