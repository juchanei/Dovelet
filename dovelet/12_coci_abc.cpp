#include <iostream>
using namespace std;

void sort(int* arr)
{
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 2; j++){
			if (arr[i] < arr[j]){
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

}

int main()
{
	int number[3];
	for (int i = 0; i < 3; i++){
		cin >> number[i];
	}

	char abc[4] = { 0, };
	cin >> abc;

	sort(number);

	for (int i = 0; i < 3; i++){
		switch (abc[i]){
		case 'A':
			cout << number[0] << " ";
			break;
		case 'B':
			cout << number[1] << " ";
			break;
		case'C':
			cout << number[2] << " ";
			break;
		}
	}
	cout << endl;


	return 0;
}