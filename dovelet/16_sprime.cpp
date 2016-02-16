#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int number)
{
	//소수판별 알고리즘이 너무 느리다
	if (1 == number) {
		return false;
	}
	for (int i = 2; i < number; ++i) {
		if (0 == number%i) {
			return false;
		}
	}
	return true;
}

int makeFullNumber(vector<int> indata)
{
	int outdata = 0;
	for (int i = 0; i < indata.size(); ++i) {
		outdata *= 10;
		outdata += indata.at(i);
	}
	return outdata;
}

void dfs(const int nNumber, vector<int> outdata, int currentNumber)
{
	outdata.push_back(currentNumber);
	if (!isPrime(makeFullNumber(outdata))) {
		return;
	}
	if (outdata.size() > nNumber) {
		cout << makeFullNumber(outdata) << endl;
		return;
	}

	for (int i = 1; i < 10; ++i) {
		dfs(nNumber, outdata, i);
	}
}

int main()
{
	int nNumber = 0;
	cin >> nNumber;

	vector<int> outdata;

	for (int i = 1; i < 10; ++i) {
		dfs(nNumber - 1, outdata, i);
	}
	
	return 0;
}