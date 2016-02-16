#include <iostream>
using namespace std;

int main()
{
	// 분모로 분자를 나눈 나머지에 10을 곱하여 해당 자릿수의 몫을 계산
	// 주어진 k값 만큼 위 계산을 반복하여 출력

	int num, den, k;
	cin >> num >> den >> k;

	cout << "0.";

	for (int i = 0; i < k; i++) {
		num *= 10;
		cout << (num / den);
		num = num%den;
	}

	return 0;
}