#include <iostream>
using namespace std;

int main()
{
	// ����� ������ �𸣱� ������ �ϳ��� ������ �ڽ��� ������ ������� ����
	// ���� ����� �ڱ��ڽŰ� ������ Yes ���, �ƴϸ� No ���

	int in;
	int accumulate = 0;
	cin >> in;

	for (int i = 1; i < in; i++) {
		if (in%i == 0) {
			accumulate += i;
		}
	}

	if (accumulate == in) cout << "yes";
	else cout << "no";

	return 0;
}