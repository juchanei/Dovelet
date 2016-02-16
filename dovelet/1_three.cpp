#include <iostream>
using namespace std;

int main()
{
int in1, in2, temp, one, ten, hundred, out1, out2, out3, out4;
cin>>in1>>in2;
temp = in2;
hundred = temp/100;
temp = temp%100;
ten = temp/10;
one = temp%10;

out1 = in1*one;
out2 = in1*ten;
out3 = in1*hundred;
out4 = in1*in2;

cout << out1 << endl << out2 << endl << out3 << endl << out4;
return 0;
}