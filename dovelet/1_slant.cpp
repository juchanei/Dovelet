#include <iostream>
using namespace std;

int main()
{
int x1,y1,x2,y2,out1,out2;
cin>>x1>>y1>>x2>>y2;
out1 = (y1-y2)/(x1-x2);
out2 = y1-x1*out1;

cout<<out1<<" "<<out2;

return 0;
}