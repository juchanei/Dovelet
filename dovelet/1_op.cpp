#include <iostream>
using namespace std;

int main()
{
	int in1, in2, plus, minus, multi, div, reminder;
	cin >> in1 >> in2;

	plus = in1 + in2;
	minus = in1 - in2;
	multi = in1 * in2;
	div = in1 / in2;
	reminder = in1 % in2;

	cout << in1 << "+" << in2 << "=" << plus << endl
		<< in1 << "-" << in2 << "=" << minus << endl
		<< in1 << "*" << in2 << "=" << multi << endl
		<< in1 << "/" << in2 << "=" << div << endl
		<< in1 << "%" << in2 << "=" << reminder << endl;
	return 0;
}