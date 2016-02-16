#include <iostream>
using namespace std;

int kapreka(int in)
{
	int big = 0, small = 0;
	int number[4];

	// �� �ڸ����� �и��Ͽ� �迭�� ����
	number[0] = in / 1000;
	in %= 1000;
	number[1] = in / 100;
	in %= 100;
	number[2] = in / 10;
	number[3] = in % 10;

	// �����Ͽ� ���� ū ��, ���� ���� �� ����
	bubbleSort(number);

	small += number[0] * 1000;
	small += number[1] * 100;
	small += number[2] * 10;
	small += number[3];

	big += number[3] * 1000;
	big += number[2] * 100;
	big += number[1] * 10;
	big += number[0];

	// �� ���� ���̸� ��ȯ
	return (big - small);
}

void bubbleSort(int* input)
{
	for (int i0 = 1; i0 < 4; i0++) {
		for (int i = 0; i < 3; i++) {
			if (input[i] > input[i + 1]) {
				swap(input[i], input[i + 1]);
			}
		}
	}
}

void swap(int* a, int* b)
{
	int temp = *b;
	*b = *a;
	*a = temp;
}