// 자리수 많은 숫자 다루기
#include <iostream>
using namespace std;

int powered(int number, int power)
{
	int out = 1;
	for (int i = 0; i < power; i++) {
		out *= number;
	}

	return out;
}

int convert2Number(int* arr, int start, int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += arr[start + i] * powered(10, size - i - 1);
	}

	return sum;
}

int main()
{
	char in[301] = { 0, };
	int number[301] = { 0, };
	cin >> in;

	int size = 0;
	while (in[size]) size++;

	for (int i = 0; i < size; i++) number[i] = (int)in[i] - 48;

	int divisionSize = 5;
	int headSize = size % divisionSize;
	int numDivision = size / divisionSize;

	int temp = convert2Number(number, 0, headSize);
	int reminder = temp % 11;

	for (int i = 0; i < numDivision; i++) {
		unsigned long long int sum = 0;
		sum += reminder * powered(10, divisionSize);
		sum += convert2Number(number, headSize + i * divisionSize, divisionSize);
		reminder = sum % 11;
	}

	if (reminder == 0) {
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}

	return 0;
}