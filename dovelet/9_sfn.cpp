#include <iostream>
using namespace std;

//Àç±Í
int calc10(int in, int sum)
{
	sum += in % 10;

	if (in > 0)
		return calc10(in / 10, sum);
	else
		return sum;
}

//¹İº¹¹®
int calc12(int in)
{
	int sum = 0;

	while (in > 0) {
		sum += in % 12;
		in = in / 12;
	}

	return sum;
}

int calc16(int in)
{
	int sum = 0;

	while (in > 0) {
		sum += in % 16;
		in = in / 16;
	}

	return sum;
}

int main()
{
	for (int i = 1000; i < 10000; i++) {
		int sum10 = calc10(i, 0), sum12 = calc12(i), sum16 = calc16(i);
		if (sum10 == sum12 && sum10 == sum16 && sum12 == sum16)
			cout /*<< sum10 << " " << sum12 << " " << sum16 << " "*/ << i << endl;
	}

	return 0;
}