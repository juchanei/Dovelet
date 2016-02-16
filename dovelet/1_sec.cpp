#include <iostream>
using namespace std;

int main()
{
int in, outDay, outHour, outMinute, outSecond;
cin >> in;

outDay = in/86400;
in = in%86400;
outHour = in/3600;
in = in%3600;
outMinute = in/60;
outSecond = in%60;

cout << outDay << " " << outHour << " " << outMinute << " " << outSecond;
return 0;
}