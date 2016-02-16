// 미해결, 문제 접근이 잘못 됨

#include <iostream>
using namespace std;

char input[201] = { 0, };
char output[201] = { 0, };
int visited[201] = { 0, };
int size = 0;

void init()
{
	size = 0;

	for (int i = 0; i < 201; i++) {
		visited[i] = 0;
	}
}

void sort(char* input, int size)
{
	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++) {
			if (input[i] > input[j]) {
				char temp = input[i];
				input[i] = input[j];
				input[j] = temp;
			}
		}
	}
}

void dfs(int node, int count)
{
	visited[node] = 1;

	output[count] = (char)(input[node] + 'a');

	if (count == size - 1) {
		cout << output << endl;
		return;
	}

	for (int i = 0; i < size; i++)  {
		if (visited[i] == 0) {
			dfs(i, count + 1);
			visited[i] = 0;
			output[count + 1] = 0;
		}
	}
}

int main()
{
	cin >> input;

	while (input[size]) size++;

	sort(input, size);

	for (int i = 0; i < size; i++) {
		input[i] = input[i] - 'a';
	}

	int tree[201][201] = { 0, };

	for (int i = 0; i < size; i++) {
		dfs(i, 0);
		visited[i] = 0;
		output[0] = 0;
	}

	init();

	return 0;
}

/*
#include <iostream>
using namespace std;

int size = 0;
int alphabat[27] = { 0, };
char output[201] = { 0, };
 
void dfs(char in, int count)
{
    output[count] = in;
 
    if(count == size - 1){
		cout << output << endl;
    }

	for (int i = 0; i < 27; i++) {
        if(alphabat[i] != 0){
            alphabat[i]--;
			dfs(i + 'a', count + 1);
            alphabat[i]++;
        }
    }
 
}
 
int main()
{
	char input[201] = { 0, };
	cin >> input;
 
	while (input[size]) size++;
 
	for (int i = 0; i < size; i++) {
        alphabat[input[i] - 'a']++;
    }
 
	for (int i = 0; i < 27; i++) {
        if(alphabat[i] != 0){
            alphabat[i]--;
			dfs(i + 'a', 0);
            alphabat[i]++;
        }
    }
 
    return 0;
}
*/