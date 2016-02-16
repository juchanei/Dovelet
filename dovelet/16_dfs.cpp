// eof, graph dfs 배움

#include <iostream>
using namespace std;

int graph[11][11] = { 0, };
int visited[11] = { 0 };
int size = 0;

void dfs(int node)
{
	visited[node] = 1;
	cout << node << " ";
	for (int i = 1; i <= size; i++){
		if (graph[node][i] == 1 && visited[i] != 1){
			dfs(i);
		}
	}

	return;
}

int main()
{
	int start;
	cin >> size >> start;

	int in[10][2] = { 0, };

	int sizeOfIn = 0;
	while (!cin.eof()){
		for (int j = 0; j < 2; j++){
			cin >> in[sizeOfIn][j];;
		}
		sizeOfIn++;
	}
	sizeOfIn--;

	for (int i = 0; i < sizeOfIn; i++){
		graph[in[i][0]][in[i][1]] = 1;
		graph[in[i][1]][in[i][0]] = 1;
	}
	
	dfs(start);
	cout << endl;

	return 0;
}




//스택을 이용한 방법
//
//
//#include <iostream>
//using namespace std;
//
//class Stack
//{
//	int stackArray[100];
//	int top;
//public:
//	Stack()
//	{
//		for (int i = 0; i < 100; i++) {
//			stackArray[i] = 0;
//		}
//		top = 0;
//	}
//	void push(int data)
//	{
//		stackArray[top] = data;
//		top++;
//	}
//	int pop()
//	{
//		top--;
//		int outdata = stackArray[top];
//		stackArray[top] = 0;
//		return outdata;
//	}
//	int isEmpty()
//	{
//		if (top == 0) {
//			return 1;
//		}
//		else {
//			return 0;
//		}
//	}
//};
//
//int main()
//{
//	int nNode = 0;
//	int startNode = 0;
//	cin >> nNode >> startNode;
//
//	int edge[11][2] = { 0, };
//	int nEdge = 0;
//	while (!cin.eof()) {
//		cin >> edge[nEdge][0] >> edge[nEdge][1];
//		nEdge++;
//	}
//
//	int graphMap[11][11] = { 0, };
//	int visited[11] = { 0, };
//	for (int i = 0; i < nEdge; i++) {
//		int start = edge[i][0];
//		int end = edge[i][1];
//		graphMap[start][end] = 1;
//		graphMap[end][start] = 1;
//	}
//
//	Stack stack;
//	stack.push(startNode);
//
//	while (1) {
//		int currentNode = stack.pop();
//		if (visited[currentNode] == 0) {
//			visited[currentNode] = 1;
//			cout << currentNode << " ";
//		}
//
//		for (int i = 10; i >= 1; i--) {
//			if (graphMap[currentNode][i] == 1 && visited[i] == 0) {
//				int nextNode = i;
//				stack.push(nextNode);
//			}
//		}
//
//		if (stack.isEmpty()) {
//			break;
//		}
//
//	}
//
//	return 0;
//}