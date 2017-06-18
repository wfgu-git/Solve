#include <bits/stdc++.h>
using namespace std;
typedef pair < int, int > pii;

map < pii, bool > pali;
bool is_pali(int hour, int mint)
{
	if (hour % 10 == mint / 10 && hour / 10 == mint % 10) return true;
	return false;
}
int main()
{
	char t[10];
	scanf("%s", t);
	int hour = (t[0] - '0') * 10 + (t[1] - '0');
	int mint = (t[3] - '0') * 10 + (t[4] - '0');
	int cnt = 0;
	while (true) {
		if (!is_pali(hour, mint)) {
			mint++;
			cnt++;
			if (mint == 60) {
				mint = 0;
				hour += 1;
				if (hour == 24) {
					hour = 0;
				}
			}
		}
		else break;
	}
	printf("%d\n", cnt);
	return 0;
}
