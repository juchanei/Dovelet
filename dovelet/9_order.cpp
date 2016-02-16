#include <iostream>
#include <string>
using namespace std;

char abc[12] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L' };
int visited[12] = { 0, };
int n, r, p = 0, q = 0;

void nPr(int index, int funcIter, int visited[], string str)
{
	str += abc[index];
	if (funcIter == n - r) {
		p--;
		if (p == 0)
			cout << str << endl;
		return;
	}
	else {
		for (int j = 0; j < n; j++) {
			if (visited[j] != 1) {
				visited[j] = 1;
				nPr(j, funcIter - 1, visited, str);
				visited[j] = 0;		//visited array를 인자로 넘겨줘도 포인터이기 때문에 값이 누적되므로 초기화해줘야함.
			}
		}
	}
}

void nCr(int index, int funcIter, int visited[], string str)
{
	str += abc[index];
	if (funcIter == n - r) {
		q--;
		if (q == 0)
			cout << str << endl;
		return;
	}
	else {
		for (int j = index; j < n; j++) {
			if (visited[j] != 1) {
				visited[j] = 1;
				nCr(j, funcIter - 1, visited, str);
				visited[j] = 0;
			}
		}
	}
}

int main()
{
	cin >> n >> r >> p >> q;

	for (int i = 0; i < n; i++) {
		visited[i] = 1;
		nPr(i, n - 1, visited, "");
		visited[i] = 0;
	}

	for (int i = 0; i < n; i++) {
		visited[i] = 1;
		nCr(i, n - 1, visited, "");
		visited[i] = 0;
	}

	return 0;
}