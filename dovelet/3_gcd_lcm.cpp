#include <iostream>
using namespace std;

int main()
{
	// gcd : A�� ����̸鼭 B�� ����� ���� ���������� �˻��Ͽ�
	//		 �� �� ���� ū ���� gcd�� ����
	// lcm : A�� ����̸鼭 B�� ����� ���� ���������� �˻��Ͽ�
	//		 �� �� ���ʷ� �߰� �� ���� lcm���� ����

	int A, B;
	int	gcd = 1, lcm = 0;
	cin >> A >> B;

	//A�� B���� �۵��� ����
	if (A > B) {
		int temp = B;
		B = A;
		A = temp;
	}

	//gcd ã��
	for (int i = 2; i <= A; i++) {
		if ((A%i == 0) && (B%i == 0)) {
			if (i > gcd) gcd = i;
		}
	}

	//lcm ã��
	for (int j = B; j <= 1000000; j++) {
		if ((j%A == 0) && (j%B == 0)) {
			lcm = j;
			break;
		}
	}

	cout << gcd << " " << lcm;
	return 0;
}