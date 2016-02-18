#include <iostream>
#include <vector>
using namespace std;

void checkBugGender(const vector<vector<int> >& adjList, vector<int>& bugGender, int currentBug, bool& found)
{
	for (int i = 0; i < adjList.at(currentBug).size(); ++i){
		int nextBug = adjList.at(currentBug).at(i);
		if (0 == bugGender.at(nextBug)){
			if (1 == bugGender.at(currentBug)){
				bugGender.at(nextBug) = 2;
			}
			if (2 == bugGender.at(currentBug)){
				bugGender.at(nextBug) = 1;
			}
			checkBugGender(adjList, bugGender, nextBug, found);
			if (true == found) return;
		}
		else{
			if (bugGender.at(currentBug) == bugGender.at(nextBug)){
				found = true;
			}
		}
	}
}

int main()
{
	int nBug = 0;
	int nRelationship = 0;
	cin >> nBug >> nRelationship;

	vector<vector<int> > adjList(nBug + 1, vector<int>(0));
	vector<int> bugGender(nBug + 1, 0);
	for (int i = 0; i < nRelationship; i++)
	{
		int bugA = 0;
		int bugB = 0;
		cin >> bugA >> bugB;

		adjList.at(bugA).push_back(bugB);
		adjList.at(bugB).push_back(bugA);
	}

	bool found = false;
	for (int i = 1; i < adjList.size(); ++i){
		if (0 == bugGender.at(i)){
			bugGender.at(i) = 1;
			checkBugGender(adjList, bugGender, i, found);
		}
	}

	if (true == found){
		cout << "Suspicious bugs found!" << endl;
	}
	else{
		cout << "No suspicious bugs found!" << endl;
	}

	return 0;
}