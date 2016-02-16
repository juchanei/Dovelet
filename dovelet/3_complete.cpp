#include <iostream>
using namespace std;

int main()
{
	// 약수의 개수를 모르기 때문에 하나에 변수에 자신을 제외한 약수값을 누적
	// 누적 결과가 자기자신과 같으면 Yes 출력, 아니면 No 출력

	int in;
	int accumulate = 0;
	cin >> in;

	for (int i = 1; i < in; i++) {
		if (in%i == 0) {
			accumulate += i;
		}
	}

	if (accumulate == in) cout << "yes";
	else cout << "no";

	return 0;
}