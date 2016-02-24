#include <iostream>
using namespace std;

int main()
{
	cout << 1000000 << " " << 1000000 << endl;
	for (int i = 0; i < 1000000; ++i){
		cout << (rand() % 10000) * 100 + (rand() & 100) << " " << (rand() % 10000) * 100 + (rand() & 100) << endl;
	}
	cout << 1 << " " << 9999 << endl;

	return 0;
}