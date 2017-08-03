#include <bits/stdc++.h>
using namespace std;
int solve(const string &s) {
  int ret = 0;
  for (char ch : s) {
    if (ch >= 'A' && ch <= 'Z') {
      ++ret;
    }
  }
  return ret;
}
int main() {
  int n;
  cin >> n;
  string s;
  int ans = 0;
  while (cin >> s) {
    ans = max(ans, solve(s));
  }
  printf("%d\n", ans);
  return 0;
}
