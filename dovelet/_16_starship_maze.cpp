// ¹ÌÇØ°á

#include <iostream>
using namespace std;

int numRoom = 0;
int numDoor = 0;

int** map = NULL;
int visited[100000] = { 0, };
//int map[100000][100000] = { 0, };

void dfs(int node)
{
	visited[node] = 1;
	cout << node << " ";
	for (int i = 1; i <= numRoom; i++){
		if ((map[node][i] == 1) && (visited[i] != 1)){
			dfs(i);
		}
	}

	return;
}

int main()
{	cin >> numRoom >> numDoor;

	map = new int*[numRoom + 2];
	for (int i = 0; i < numRoom + 2; i++){
		map[i] = new int[numRoom + 2];
	}

	for (int i = 0; i < numRoom + 2; i++){
		for (int j = 0; j < numRoom + 2; j++){
			map[i][j] = 0;
		}
	}

	for (int i = 1; i <= numDoor; i++){
		int temp1 = 0, temp2 = 0;
		cin >> temp1 >> temp2;

		map[temp1][temp2] = 1;
		map[temp2][temp1] = 1;
	}

	dfs(1);

	return 0;
}