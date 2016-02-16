#include <iostream>
using namespace std;

int main()
{
int in1, in2, out1, out2;
cin>>in1>>in2;

out1 = in1/in2;
out2 = in1%in2;

cout << out1 << " " << out2;
return 0;
}