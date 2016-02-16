#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int> >& adjMap, vector<int>& genderList, int currentBug, bool& flag)
{
	if (true == flag) {
		return;
	}

	for (int i = 1; i < adjMap.size(); ++i) {
		if (1 == adjMap.at(currentBug).at(i)) {

			if (0 == genderList.at(i)) {
				if (1 == genderList.at(currentBug)) {
					genderList.at(i) = 2;
				}
				else if (2 == genderList.at(currentBug)){
					genderList.at(i) = 1;
				}
				dfs(adjMap, genderList, i, flag);
			}
			else {
				if (genderList.at(currentBug) == genderList.at(i)) {
					flag = true;
					return;
				}
			}

		}
	}

}

int main()
{
	int nBug = 0;
	int nCouple = 0;
	cin >> nBug >> nCouple;

	vector<int> genderList(nBug + 1, 0);
	vector<vector<int> > adjMap(nBug + 1, vector<int>(nBug + 1, 0));

	int bugA = 0;
	int bugB = 0;
	for (int i = 0; i < nCouple; ++i){
		cin >> bugA >> bugB;
		adjMap.at(bugA).at(bugB) = 1;
		adjMap.at(bugB).at(bugA) = 1;
	}
	
	//����� ���� �Ǿ��� �� ��� ��͸� ���������� ���. �������� ��������� ������ �� �������� �ʾ�����?
	bool flag = false;

	//�׷����� ������Ʈ�� �������� �� �ִ�
	for (int i = 1; i <= nBug; ++i) {
		if (0 == genderList.at(i)) {
			genderList.at(i) = 1;
			dfs(adjMap, genderList, i, flag);
		}
		if (true == flag) {
			break;
		}
	}

	if (true == flag) {
		cout << "Suspicious bugs found!" << endl;
	}
	else {
		cout << "No suspicious bugs found!" << endl;
	}

	return 0;
}