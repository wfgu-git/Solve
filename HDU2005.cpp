#include <iostream>
#include <cstdio>
using namespace std;

int date_nor[] = {0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int date_leap[] = {0,31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool is_leap(int y)
{
	if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) return true;
	return false;
}

int main(int argc, char const **argv)
{
	int year, month, day;
	while (~scanf("%d/%d/%d", &year, &month, &day)) {
		int res = 0;
		if (is_leap(year)) {
			for (int i = 1; i < month; i++) {
				res += date_leap[i];
			}
		} else {
			for (int i = 1; i < month; i++) {
				res += date_nor[i];
			}
		}
		printf("%d\n", res + day);
	}
	return 0;
}
