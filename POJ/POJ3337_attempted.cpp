/*
教练我要打ACM!
*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

int check(char c) {
	if (c >= 'a' && c <= 'z') {
		return c - 'a' + 1;
	}
	return -1;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	string raw;
	cin >> T;
	cin.ignore();
	while (T--) {
		getline(cin, raw);
		int n = raw.size();
		for (int i = 0; i + 1 < n; ++i) {
			if ((!i && check(raw[i + 2] != -1)) || check(raw[i - 1]) != -1 || ((i + 2 < n) && check(raw[i + 2]) != -1)) {
				if (raw[i] == '+' && raw[i + 1] == '+') {
					raw[i] = '#';
					raw[i + 1] = ' ';
					++i;
				} else if (raw[i] == '-' && raw[i + 1] == '-') {
					raw[i] = '$';
					raw[i + 1] = ' ';
					++i;
				}
			}
		}
		raw.erase(remove(raw.begin(), raw.end(), ' '), raw.end());
    cout << raw << endl;
  }
  return 0;
}
