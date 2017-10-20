/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

set<int> S[21];
int main() {
#ifndef ONLINE_JUDGE
freopen("/home/wfgu/Documents/solve/data.in", "r", stdin);
freopen("/home/wfgu/Documents/solve/data.out", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  string line;
  cin >> line;
  int n = line.size();
  for (int i = 1; i <= 20; ++i) {
    for (int j = 0; j + i - 1 < n; ++j) {
      int k = j + i - 1;
      int hs_val = 0;
      for (int i = j; i <= k; ++i) {
        hs_val <<= 1;
        hs_val |= (line[i] - '0');
      }
      S[i].insert(hs_val);
    }
  }
  for (int i = 1; i <= 20; ++i) {
    if (S[i].size() != (1 << i)) {
      cout << i;
      return 0;
    }
  }
}
