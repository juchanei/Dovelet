//로직이 너무 복잡하다...

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int parse(const string str, const int start, const int end)
{
	int result = 0;
	for (int i = start; i <= end; ++i) {
		result *= 10;
		result += str.at(i) - '0';
	}

	return result;
}

int getSum(const vector<int>& shreddedPapers)
{
	int sum = 0;
	for (int i = 0; i < shreddedPapers.size(); ++i) {
		sum += shreddedPapers.at(i);
	}
	return sum;
}

void dfs(const string givenPaper, vector<int> shreddedPapers, vector<vector<int> >& results, const int targetNumber, const int numberPointer)
{
	if (givenPaper.size() == numberPointer) {
		results.push_back(shreddedPapers);
		return;
	}

	int parseValue = 0;
	int returnValue = 0;
	for (int i = numberPointer; i < givenPaper.size(); ++i) {
		parseValue = parse(givenPaper, numberPointer, i);
		vector<int> newShreddedPapers = shreddedPapers;
		newShreddedPapers.push_back(parseValue);
		if (getSum(newShreddedPapers) > targetNumber) {
			continue;
		}
		else {
			dfs(givenPaper, newShreddedPapers, results, targetNumber, i + 1);
		}
	}
}

int main()
{
	int targetNumber = 0;
	string givenPaper;
	cin >> targetNumber >> givenPaper;

	vector<int> shreddedPapers;
	vector<vector<int> > results;
	dfs(givenPaper, shreddedPapers, results, targetNumber, 0);

	if (0 == results.size()) {
		cout << "error" << endl;
		return 0;
	}
	else {
		for (int i = 0; i < results.size(); ++i) {
			int sum = getSum(results.at(i));
			results.at(i).push_back(sum);
		}

		for (int i = 0; i < results.size(); ++i) {
			for (int j = i; j < results.size(); ++j) {
				if (results.at(i).back() < results.at(j).back()) {
					results.at(i).swap(results.at(j));
				}
			}
		}

		if (1 < results.size() && results.at(0).back() == results.at(1).back()) {
			cout << "rejected" << endl;
			return 0;
		}
		else {
			cout << results.at(0).back();
			for (int i = 0; i < results.at(0).size() - 1; ++i) {
				cout << " " << results.at(0).at(i);
			}
			cout << endl;
			return 0;
		}
	}
}