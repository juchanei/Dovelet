#include <iostream>
using namespace std;

int main()
{
	// �и�� ���ڸ� ���� �������� 10�� ���Ͽ� �ش� �ڸ����� ���� ���
	// �־��� k�� ��ŭ �� ����� �ݺ��Ͽ� ���

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