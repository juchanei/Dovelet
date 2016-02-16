// 해결, 도블릿에 뭔가 문제있음

#include <iostream>
using namespace std;

int main()
{
	while (1){
		char in[10] = { 0, };
		int num[10] = { 0, };
		cin >> in;
		if (in[0] == '0') break;

		int size = 0;
		while (in[size]){
			num[size] = in[size] - 48;
			size++;
		}

		int fINC = 0;
		if (num[0] - num[1] > 0) fINC = 0;
		else fINC = 1;

		if (fINC == 1){
			int flag = 0;
			for (int i = 0; i < size - 1; i++){
				if (num[i] - num[i + 1] < 0){
					cout << "bouncy" << endl;
					flag = 1;
					break;
				}
			}
			if (flag == 0) cout << "no bouncy" << endl;
		}
		else{
			int flag = 0;
			for (int i = 0; i < size - 1; i++){
				if (num[i] - num[i + 1] < 0){
					cout << "bouncy" << endl;
					flag = 1;
					break;
				}
			}
			if (flag == 0) cout << "no bouncy" << endl;
		}
	}
	return 0;
}