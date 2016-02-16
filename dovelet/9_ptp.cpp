#include <iostream>
using namespace std;

void drawMnt(int top)
{
	if (top == 1) {
		cout << 1;
		return;
	}
	while (top > 1) {
		drawMnt(top - 1);
		cout << top;
		drawMnt(top - 1);
		return;
	}
}


int main()
{
	int num;
	cin >> num;

	drawMnt(num);

	return 0;
}