#include <iostream>
using namespace std;

int main()
{
	int in1, in2, in3, out;
	float total;

	cin >> in1 >> in2 >> in3;
	total = in1*2.5f + in2*2.0f + in3*0.5f;
	out = (int)(total * 2 + 9) / 10 * 10;

	cout << out << " amperes" << endl;
	return 0;
}