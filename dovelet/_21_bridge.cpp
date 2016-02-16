// ¹ÌÇØ°á

#include <iostream>
using namespace std;

int main()
{
	char log[21] = { 0, };
	cin >> log;
	int logSize = 0;
	while (log[logSize]) logSize++;

	char bridge[2][101] = { 0, };
	cin >> bridge[0];
	cin >> bridge[1];
	int bridgeSize = 0;
	while (bridge[0][bridgeSize]) bridgeSize++;



	return 0;
}