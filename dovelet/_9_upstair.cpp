// ¹ÌÇØ°á

#include <iostream>
using namespace std;

void upStair(int num, int current, int* count)
{
	if (current == num) {
		(*count)++;
		return;
	}
	else if (current > num) {
		return;
	}
	upStair(num, current + 1, count);
	upStair(num, current + 2, count);

	return;
}

int main()
{
	int num = 0;
	cin >> num;

	int count = 0;
	upStair(num, 0, &count);

	cout << count << endl;

	return 0;
}