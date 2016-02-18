#include <iostream>
#include <string>
#include <vector>
using namespace std;

void dfs(vector<int>& adjMat, int currentNode, int count, string& outdata)
{
	outdata.at(count) = currentNode + 'a';
	if (count == outdata.size() - 1){
		//cout << outdata << endl;
		printf("%s\n", outdata.c_str());
		return;
	}
	adjMat.at(currentNode) -= 1;

	for (int i = 0; i < adjMat.size(); i++)
	{
		if (0 < adjMat.at(i)){
			dfs(adjMat, i, count + 1, outdata);
		}
	}

	adjMat.at(currentNode) += 1;
}

int main()
{
	string inputStr;
	cin >> inputStr;

	vector<int> adjMat('z' - 'a' + 1, 0);
	for (int i = 0; i < inputStr.size(); i++)
	{
		adjMat.at(inputStr.at(i) - 'a') += 1;
	}

	for (int i = 0; i < adjMat.size(); i++)
	{
		if (0 < adjMat.at(i)){
			string outdata(inputStr.size(), 0);
			dfs(adjMat, i, 0, outdata);
		}
	}

	return 0;
}