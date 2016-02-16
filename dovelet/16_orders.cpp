#include <iostream>
#include <vector>
#include <string>
using namespace std;

string preResult;

void dfs(vector<int> charList, vector<int>& visited, string result, int currentChar, int charCount)
{
	int& visitedValue = visited.at(currentChar);
	++visitedValue;
	result.at(result.size() - charCount - 1) = 'a' + currentChar;

	for (int i = 0; i < charList.size(); ++i) {
		if (0 != charList.at(i) && charList.at(i) != visited.at(i)) {
			dfs(charList, visited, result, i, charCount - 1);
		}
	}

	--visitedValue;
	if (0 == charCount) {
		if (result != preResult) {
			// 효율이 떨어지는 원인
			preResult = result;
			cout << result << endl;
		}
	}
}

int main()
{
	string inputData;
	cin >> inputData;

	vector<int> charList(26, 0);
	for (int i = 0; i < inputData.size(); ++i) {
		int& charValue = charList.at(inputData.at(i) - 'a');
		++charValue;
	}

	vector<int> visited(26, 0);
	string result(inputData.size(), ' ');

	for (int i = 0; i < charList.size(); ++i) {
		if (0 != charList.at(i) && charList.at(i) != visited.at(i)) {
			dfs(charList, visited, result, i, inputData.size() - 1);
		}
	}

	return 0;
}