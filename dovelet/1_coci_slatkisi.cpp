#include <iostream>
using namespace std;

int main()
{
int in1,in2,out1, out2, out3;
int round = 1;

cin>>in1>>in2;

for (int i = 0; i < in2;i++){
round = round*10;
}

out1 = in1/round*round;
out2 = (in1+(round-1))/round*round;
out3 = (in1+(round/2))/round*round;

cout<<out3;
return 0;
}