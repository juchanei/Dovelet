#include <iostream>
using namespace std;

int main()
{
	// gcd : A의 약수이면서 B의 약수인 수를 순차적으로 검사하여
	//		 그 중 가장 큰 수를 gcd로 결정
	// lcm : A의 배수이면서 B의 배수인 수를 순차적으로 검사하여
	//		 그 중 최초로 발견 한 수를 lcm으로 결정

	int A, B;
	int	gcd = 1, lcm = 0;
	cin >> A >> B;

	//A가 B보다 작도록 조정
	if (A > B) {
		int temp = B;
		B = A;
		A = temp;
	}

	//gcd 찾기
	for (int i = 2; i <= A; i++) {
		if ((A%i == 0) && (B%i == 0)) {
			if (i > gcd) gcd = i;
		}
	}

	//lcm 찾기
	for (int j = B; j <= 1000000; j++) {
		if ((j%A == 0) && (j%B == 0)) {
			lcm = j;
			break;
		}
	}

	cout << gcd << " " << lcm;
	return 0;
}