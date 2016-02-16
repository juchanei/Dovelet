#include <iostream>
using namespace std;

int main()
{
	char in[26] = { 0, };
	cin >> in;

	int size = 0;
	while (in[size]){
		size++;
	}

	for (int i = 0; i < size; i++){
		switch (in[i]){
		case 'q' : 
		case 'Q' :
			cout << in << endl;
			break;
		case 'h' :
		case 'H' :
			cout << "Hello, world!" << endl;
			break;
		case '9' : 
			cout << "99 Bottles of Beer on the Wall" << endl;
			break;
		}
	}

	return 0;
}