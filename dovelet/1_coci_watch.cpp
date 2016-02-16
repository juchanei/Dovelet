#include <iostream>
using namespace std;

int main()
{
int in1, in2, in3, in4, startSeconds, endSeconds, temp, out1, out2, out3;
cin>>in1>>in2>>in3>>in4;
startSeconds = in1*3600+in2*60+in3;
endSeconds = startSeconds + in4;

temp = endSeconds;
out1 = temp/3600;
if (out1 > 24) out1 = out1%24;
temp = temp%3600;
out2 = temp/60;
out3 = temp%60;

cout << out1 << " " << out2 << " " << out3;
return 0 ;
}