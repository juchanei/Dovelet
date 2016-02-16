#include <iostream>
using namespace std;

int visited[13] = { 0, };
int nNumber = 0;
int nSelect = 0;
int targetCount1 = 0;
int targetCount2 = 0;

void init()
{
	for (int i = 0; i < 13; i++) {
		visited[i] = 0;
	}
	nNumber = 0;
	nSelect = 0;
	targetCount1 = 0;
	targetCount2 = 0;
}

void dfs1(int currentValue, int preValue, int remainNumber, int& count, bool& escapeFlag, char* outdata)
{
	if (escapeFlag == true) return;
	if (remainNumber == 0) {
		++count;
		if (count == targetCount1) {
			cout << outdata << endl;
			escapeFlag = true;
		}
		return;
	}

	--remainNumber;

	for (int i = 0; i < nNumber; i++) {
		if (visited[i] == 0) {
			outdata[nSelect - remainNumber - 1] = (char)(i + 'A');
			visited[i] = 1;
			dfs1(i, currentValue, remainNumber, count, escapeFlag, outdata);
			visited[i] = 0;
		}
	}
}

void dfs2(int currentValue, int preValue, int remainNumber, int& count, bool& escapeFlag, char* outdata)
{
	if (escapeFlag == true) return;
	if (currentValue < preValue) return;
	if (remainNumber == 0) {
		++count;
		if (count == targetCount2) {
			cout << outdata << endl;
			escapeFlag = true;
		}
		return;
	}

	--remainNumber;

	for (int i = 0; i < nNumber; i++) {
		if (visited[i] == 0) {
			outdata[nSelect - remainNumber - 1] = (char)(i + 'A');
			visited[i] = 1;
			dfs2(i, currentValue, remainNumber, count, escapeFlag, outdata);
			visited[i] = 0;
		}
	}
}

int main()
{
	cin >> nNumber >> nSelect >> targetCount1 >> targetCount2;

	int count1 = 0;
	bool escapeFlag1 = false;
	char outdata1[13] = { 0, };
	for (int i = 0; i < nNumber; i++) {
		outdata1[0] = (char)(i + 'A');
		visited[i] = 1;
		dfs1(i, 0, nSelect - 1, count1, escapeFlag1, outdata1);
		visited[i] = 0;
	}

	for (int i = 0; i < 13; i++) {
		visited[i] = 0;
	}

	int count2 = 0;
	bool escapeFlag2 = false;
	char outdata2[13] = { 0, };
	for (int i = 0; i < nNumber; i++) {
		outdata2[0] = (char)(i + 'A');
		visited[i] = 1;
		dfs2(i, 0, nSelect - 1, count2, escapeFlag2, outdata2);
		visited[i] = 0;
	}

	init();

	return 0;
}