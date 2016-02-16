#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	long in1, in2, num1, num2, out;
	cin >> in1 >> in2;

	num1 = (in1 - 1) - (long)sqrt((in1 - 1));
	num2 = in2 - (long)sqrt(in2);
	out = num2 - num1;

	cout << out << endl;
	return 0;
}