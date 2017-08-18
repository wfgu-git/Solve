#include <bits/stdc++.h>
using namespace std;
const int moder = 1000000007;
void work() {
  string s;
  cin >> s;
  string ret = "", tmp = "";
  int cont = 0;
  int n = (int)s.size();
  int p = 0, kind = 0;
  while (p < n) {
    if (kind == 0 && s[p] != '(') {
      ret += s[p];
    } else if (kind == 0 && s[p] == '(') {
      kind = 1;
    } else if (kind == 1 && s[p] != ')') {
      tmp += s[p];
    } else if (kind == 1 && s[p] == ')') {
      kind = 2;
    } else if (kind == 2 && s[p] == '#') {
      kind = 3;
    } else if (kind == 3 && s[p] == '(') {
      kind = 4;
    } else if (kind == 4 && s[p] != ')') {
      cont = s[p] - '0';
    } else if (kind == 4 && s[p] == ')') {
      kind = 0;
      for (int i = 0; i < cont; ++i) {
        ret += tmp;
      }
      tmp = "";
      cont = 0;
    }
    ++p;
  }
  // cout << ret << endl;
  long long ans = 0;
  for (char& c : ret) {
    ans = (ans * 10 % moder + 1LL * (c - '0')) % moder;
  }
  printf("%lld\n", ans);
}
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  for (int cas = 1; cas <= T; ++cas) {
    work();
  }
  return 0;
}
