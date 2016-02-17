#include <iostream>
#include <vector>
#include <string>
using namespace std;

const char opcode[3] = { ' ', '+', '-'};

int calc(string str)
{
	vector<int> componants;

	for (int i = 0; i < str.size(); ++i){
		if (' ' == str.at(i)){
			int temp = componants.back();
			componants.pop_back();
			temp *= 10;
			++i;
			temp += static_cast<int>(str.at(i) - '0');
			componants.push_back(temp);
		}
		else{
			componants.push_back(static_cast<int>(str.at(i) - '0'));
		}
	}

	int sum = componants.at(0);
	for (int i = 1; i < componants.size(); i = i + 2){
		char opcode = componants.at(i) + '0';
		if ('+' == opcode){
			sum += componants.at(i + 1);
		}
		else if ('-' == opcode){
			sum -= componants.at(i + 1);
		}
	}

	return sum;
}

void dfs(string str, int nNumber, int current)
{
	if (current == nNumber){
		str.push_back(static_cast<int>(current + '0'));
		int result = calc(str);
		if (0 == result){
			cout << str << endl;
		}
		return;
	}

	str.push_back(static_cast<char>(current + '0'));

	for (int i = 0; i < 3; ++i){
		string nextStr = str;
		nextStr.push_back(opcode[i]);
		dfs(nextStr, nNumber, current + 1);
	}
}

int main()
{
	int nNumber = 0;
	cin >> nNumber;

	string outdata;

	dfs(outdata, nNumber, 1);

	return 0;
}