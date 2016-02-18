#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> max(vector<int>a, vector<int>b)
{
	if (a.back() > b.back()){
		return a;
	}
	else{
		return b;
	}
}

int cutPaperFromBack(string& paper, int length)
{
	int result = 0;
	int digit = 1;
	for (int i = 1; i <= length; ++i){
		result += static_cast<int>(paper.back() - '0') * digit;
		digit *= 10;
		paper.pop_back();
	}

	return result;
}

vector<int> dfs(string paper, int targetNumber, int sum, int& result, bool& rejected, vector<int> outdata)
{
	if (sum > targetNumber){
		return vector<int>(1, 0);
	}

	if (0 == paper.size()){
		if (sum > result){
			outdata.push_back(sum);
			result = sum;
			return outdata;
		}
		if (sum == result){
			rejected = true;
			return  vector<int>(1, 0);
		}
	}

	vector<int> returnData(1, 0);
	for (int i = paper.size(); i > 0; --i){
		string cutPaper = paper;
		int cuttedPaperValue = cutPaperFromBack(cutPaper, i);
		vector<int> newOutdata = outdata;

		newOutdata.push_back(cuttedPaperValue);
		returnData = max(returnData, dfs(cutPaper, targetNumber, sum + cuttedPaperValue, result, rejected, newOutdata));
		if (true == rejected) return vector<int>(1, 0);
	}

	return returnData;
}

int main()
{
	int targetNumber = 0;
	string paper;
	cin >> targetNumber >> paper;

	int sum = 0;
	int result = 0;
	bool found = false;
	bool rejected = false;
	vector<int> outdata;
	vector<int> returnData = dfs(paper, targetNumber, sum, result, rejected, outdata);

	if (true == rejected){
		cout << "rejected" << endl;
	}
	else{
		if (0 == returnData.back()){
			cout << "error" << endl;
		}
		else{
			for (int i = returnData.size() - 1; i >= 0; --i){
				cout << returnData.at(i) << " ";
			}
			cout << endl;
		}
	}

	return 0;
}