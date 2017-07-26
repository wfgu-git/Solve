#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000000 + 20;
const double eps = 1e-7;
double res[maxn];
void init() {
  res[1] = 1 * 1.0;
  for (int i = 2; i < maxn; i++) {
    res[i] = res[i - 1] + 1.0 / ((double)i * (double)i);
  }
}
int get_num(const string &s) {
  int res = 0;
  for (auto i : s) {
    res = res * 10 + (i - '0');
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  init();
  string str;
  while (cin >> str) {
    if (str.size() >= 7) {
      cout << fixed << setprecision(5) << res[maxn - 1] << endl;
    } else {
      int n = get_num(str);
      //cout << n << endl;
      if (n < maxn) cout << fixed << setprecision(5) << res[n] << endl;
      else cout << fixed << setprecision(5) << res[maxn - 1] << endl;
    }
  }
  return 0;
}
