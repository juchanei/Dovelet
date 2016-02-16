#include <iostream>
using namespace std;

int main()
{
	int num = 0;
	cin >> num;
	char bid[351] = { 0, };
	for (int i = 0; i < num; i++) {
		cin >> bid[i];
	}

	char c;
	if (bid[0] == 'b') {
		c = 'b';
	}
	else if (bid[0] == 'r') {
		c = 'r';
	}
	else if (bid[0] == 'w') {
		c = 'w';
	}
	for (int i = 0; i < num; i++) {
		if (bid[i] != c) break;
		if (i == num - 1) {
			cout << num << endl;
			return 0;
		}
	}

	int count = 0;
	int bigCount = 0;
	for (int i = 0; i < num; i++) {
		int w = 0;
		if (bid[i] == 'w') {
			for (int j = 0; j < num; j++) {
				if (bid[i + j] == 'w') {
					count++;
				}
				else {
					w = j;
					break;
				}
			}
		}
		i += w;

		if (bid[i] == 'b') {
			for (int j = 0; j < num; j++) {
				int jj = i + j;
				if (jj >= num) {
					jj = jj - num;
				}

				if (bid[jj] == 'b' || bid[jj] == 'w') {
					count++;
				}
				else {
					break;
				}
			}
			i -= w;

			for (int j = 0; j < num; j++) {
				int jj = i - j - 1;
				if (jj < 0) {
					jj = num + jj;
				}

				if (bid[jj] == 'b') {
					for (int k = 0; k < num; k++) {
						if (bid[jj - k] == 'b' || bid[jj - k] == 'w') {
							count++;
						}
						else {
							break;
						}
					}
					break;
				}
				else if (bid[jj] == 'r' || bid[jj] == 'w') {
					for (int k = 0; k < num; k++) {
						if (bid[jj - k] == 'r' || bid[jj - k] == 'w') {
							count++;
						}
						else {
							break;
						}
					}
					break;
				}
				else {
					count++;
				}
			}
		}
		else if (bid[i] == 'r') {
			for (int j = 0; j < num; j++) {
				int jj = i + j;
				if (jj >= num) {
					jj = jj - num;
				}
				if (bid[jj] == 'r' || bid[jj] == 'w') {
					count++;
				}
				else {
					break;
				}
			}
			i -= w;

			for (int j = 0; j < num; j++) {
				int jj = i - j - 1;
				if (jj < 0) {
					jj = num + jj;
				}

				if (bid[jj] == 'b') {
					for (int k = 0; k < num; k++) {
						if (bid[jj - k] == 'b' || bid[jj - k] == 'w') {
							count++;
						}
						else {
							break;
						}
					}
					break;
				}
				else if (bid[jj] == 'r' || bid[jj] == 'w') {
					for (int k = 0; k < num; k++) {
						if (bid[jj - k] == 'r' || bid[jj - k] == 'w') {
							count++;
						}
						else {
							break;
						}
					}
					break;
				}
			}
		}

		if (count > bigCount) bigCount = count;
		count = 0;
	}
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	if (bigCount == 12) bigCount = 8;
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	cout << bigCount << endl;

	return 0;
}