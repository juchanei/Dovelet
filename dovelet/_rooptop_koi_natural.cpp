//¹ÌÇØ°á

#include <iostream>
using namespace std;

int inputNumbers[5000000] = { 0, };
int visited[5000000] = { 0, };
int valueMap[5000000] = { 0, };

int findAbsoluteSum(int numInputNumbers, int theNumber)
{
	for (int i = 0; i < theNumber; i++) {
		valueMap[i] = theNumber - i;
	}
	for (int i = theNumber; i < numInputNumbers; i++) {
		valueMap[i] = i - theNumber;
	}

	int sum = 0;
	for (int i = 0; i < numInputNumbers; i++) {
		sum += valueMap[inputNumbers[i]];
	}

	return sum;
}

void initArray(int numInputNumbers)
{
	for (int i = 0; i < numInputNumbers; i++) {
		valueMap[i] = 0;
		visited[i] = 0;
	}
}

int main()
{
	int numInputNumbers = 0;
	cin >> numInputNumbers;
	for (int i = 0; i < numInputNumbers; i++) {
		cin >> inputNumbers[i];
	}
	

	int minValue = findAbsoluteSum(numInputNumbers, 0);
	int iter = 0;
	for (int i = 1; i < numInputNumbers; i++) {
		if (visited[i] != 1) {
			int currentValue = findAbsoluteSum(numInputNumbers, i);
			if (currentValue < minValue) {
				minValue = currentValue;
				iter = i;
			}
			else if (currentValue == minValue) {
				if (inputNumbers[i] < inputNumbers[iter]) {
					iter = i;
				}
			}
		}
	}

	cout << inputNumbers[iter] << endl;



	return 0;
}