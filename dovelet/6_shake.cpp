#include <iostream>
using namespace std;

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void sort(int* data, int* high, int* low)
{
	int tempHigh = *high;
	int tempLow = *low;
	for (int i = 1; i < *high; i++) {
		if (data[i]>data[i + 1]) {
			swap(data[i], data[i + 1]);
			tempHigh = i;
		}
	}


	for (int i = *high; i > 1; i--) {
		if (data[i]<data[i - 1]) {
			swap(data[i], data[i - 1]);
			tempLow = i;
		}
	}
	*high = tempHigh;
	*low = tempLow;
}

int main()
{
	int num = 0;
	cin >> num;
	int data[1001] = { 0, };
	for (int i = 1; i <= num; i++) {
		cin >> data[i];
	}

	int high = num;
	int low = 1;
	int preHigh = 0;
	int preLow = 0;
	int count = 0;
	while (1) {
		sort(data, &high, &low);
		count++;
		if (low + 1 == high) {
			cout << count << endl;
			break;
		}
	}

	return 0;
}