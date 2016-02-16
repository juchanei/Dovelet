// 미해결 - 도블릿에 문제있음 - 확인중

#include <iostream>
using namespace std;

void printBlankLine(int n)
{
	char print1[3] = "  ";
	char print2[5] = "    ";

	cout << print1;
	for (int i = 0; i < n - 1; i++) {
		cout << print2;
	}
	cout << endl;
	cout << print1;
	for (int i = 0; i < n - 1; i++) {
		cout << print2;
	}
	cout << endl;
}

void printTriangleLine(int n)
{
	char blank1[3] = "  ";
	char blank2[5] = "    ";
	char print1[5] = " /\\ ";
	char print2[5] = "/__\\";

	for (int i = 0; i < n; i++) {
		cout << blank1;
	}
	for (int i = 0; i < n; i++) {
		cout << print1;
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << print2;
	}
	cout << endl;
}

int main()
{
	printBlankLine(1);
	printTriangleLine(1);
	printTriangleLine(2);
	return 0;
}