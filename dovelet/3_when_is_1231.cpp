#include <iostream>
using namespace std;

int getFirstDayOfTheMonth(int month)
{
	int nDaysOfTheMonth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int sum = 0;
	for (int i = 1; i < month; i++) {
		sum += nDaysOfTheMonth[i];
	}
	return sum + 1;
}

int main()
{
	int month = 0;
	int nDate = 0;
	cin >> month;
	cin >> nDate;
	int sumTheDates = 0;
	for (int i = 0; i < nDate; i++) {
		int temp = 0;
		cin >> temp;
		sumTheDates += temp;
	}
	int sumTheDays = 0;
	cin >> sumTheDays;

	int firstDayOfTheMonth = getFirstDayOfTheMonth(month);
	int sundayOfTheWeek = (sumTheDays - sumTheDates) / nDate;
	int dateOf1231 = (365 - firstDayOfTheMonth - sundayOfTheWeek + 1) % 7;

	cout << dateOf1231 << endl;

	return 0;
}