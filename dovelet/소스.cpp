//http://59.23.113.171/30stair/danji/danji.php?pname=danji

#include <iostream>
using namespace std;

int mapsize;
int map[30][30];
int visit[30][30];

void findGroup(int x, int y, int count)
{
	if (x > mapsize + 2 || y > mapsize + 2 || (visit[y][x] == 0 && x != 1 && y != 1)) {
		return;
	}

	visit[y][x] = 0;
	map[y][x] = count;

	//위
	if (visit[y][x - 1] == 1 && x > 1) {
		findGroup(x - 1, y, ++count);
	}
	//아래
	if (visit[y][x + 1] == 1 && x < mapsize + 2) {
		findGroup(x + 1, y, ++count);
	}
	//오른쪽
	if (visit[y + 1][x] == 1 && y < mapsize + 2) {
		findGroup(x, y + 1, ++count);
	}
	//왼쪽
	if (visit[y - 1][x] == 1 && y > 1) {
		findGroup(x, y - 1, ++count);
	}

}

void init()
{
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 30; j++) {
			map[i][j] = 0;
			visit[i][j] = 0;
		}
	}
}

int main()
{

	int tmp;
	cin >> mapsize;

	init();

	for (int i = 1; i <= mapsize; i++) {
		for (int j = 1; j <= mapsize; j++) {
			cin >> tmp;
			map[i][j] = tmp;
			visit[i][j] = tmp;
		}
	}
	//print
	cout << "기본" << endl;
	for (int i = 1; i <= mapsize; i++) {
		for (int j = 1; j <= mapsize; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;


	findGroup(1, 1, 1);

	//print
	cout << "바꾼후" << endl;
	for (int i = 1; i <= mapsize; i++) {
		for (int j = 1; j <= mapsize; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}


}