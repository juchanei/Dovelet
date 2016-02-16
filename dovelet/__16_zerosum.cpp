#include <iostream>
#include <vector>
#include <string>
using namespace std;

int calcResult(string input)
{
	int result = 0;

	// 파싱해서 계산결과 리턴

	return result;
}

void dfs(int nOperand, int depth, string str)
{
	if (nOperand + 1 == depth) {
		int result = calcResult(str);
		if (0 == result) {
			cout << result << endl;
		}
		return;
	}

	{
		string tempStr = str;
		char temp = '0' + depth + 1;
		tempStr.push_back('+');
		tempStr.push_back(temp);
		dfs(nOperand, depth + 1, tempStr);
	}
	{
		string tempStr = str;
		char temp = '0' + depth + 1;
		tempStr.push_back('-');
		tempStr.push_back(temp);
		dfs(nOperand, depth + 1, tempStr);
	}
	{
		string tempStr = str;
		char temp = '0' + depth + 1;
		tempStr.push_back(' ');
		tempStr.push_back(temp);
		dfs(nOperand, depth + 1, tempStr);
	}
}

int main()
{
	int num = 0;
	cin >> num;

	dfs(num - 1, 1, "1");

	return 0;
}