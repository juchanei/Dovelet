#include <iostream>
#include <string>
using namespace std;

void game(string out, int winCount, int loseCount, int* count, string str)
{
	str += out;
	if (winCount == 0) {
		cout << str << endl;
		(*count)++;
	}
	else if (loseCount == 0) {
		return;
	}
	else {
		game("o", winCount - 1, loseCount, count, str);
		game("x", winCount, loseCount - 1, count, str);
	}
}

int main()
{
	int num, count = 0;
	cin >> num;
	game("o", num - 1, num, &count, "");
	game("x", num, num - 1, &count, "");

	cout << "total " << count << " case(s)" << endl;
	return 0;
}