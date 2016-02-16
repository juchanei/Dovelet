#include <iostream>
using namespace std;

int main()
{
	char alpha[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
	char out[4] = { 0, };
	
	for (int i = 0; i < 26; i++){
		for (int j = 0; j < 26; j++){
			for (int k = 0; k < 26; k++){
				out[0] = alpha[i];
				out[1] = alpha[j];
				out[2] = alpha[k];

				cout << out << " ";
				for (int l = 0; l < 3; l++){
					out[l] = 0;
				}
			}
		}
	}
	cout << endl;

	return 0;
}