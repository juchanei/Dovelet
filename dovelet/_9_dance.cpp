// ¹ÌÇØ°á

#include <iostream>
using namespace std;

int sum = 0;

void dance(int start, int end)
{
	int temp = (end - start + 1) / 2;
	if (temp == 0) {
		return;
	}
	else if (temp == 1) {
		sum += start * end;
		return;
	}

	int mid = start + temp;
	dance(start, mid);
	dance(mid + 1, end);
}

int main()
{
	int n = 0;
	cin >> n;

	dance(1, n);
	cout << sum << endl;

	return 0;
}