#include <bits/stdc++.h>
using namespace std;
// const int inf = 0x3f3f3f3f;
const int maxn = 15;
const int sz = 1 << maxn;
int n;
int dp[sz + 1];
int day[sz + 1];
int pre[sz + 1];
struct Course {
  string s;
  int d, c;
} info[maxn + 1];
void print(int k) {
  if (k == 0) return;
  print(pre[k]);
  k -= pre[k];
  for (int i = 0; i < n; i++) {
    if (k & (1 << i))
      cout << info[i].s << endl;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  for (int cas = 1; cas <= T; cas++) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      string s;
      int d, c;
      cin >> s >> d >> c;
      info[i] = {s, d, c};
    }
    memset(dp, 0x3f, sizeof(dp));
    int tot = (1 << n) - 1;
    dp[0] = 0, day[0] = 0;

    for (int i = 1; i <= tot; i++) {
      for (int j = 0; j < n; j++) {
        if ((i & (1 << j)) == 0) continue;
        int k = i - (1 << j);
        day[i] = day[k] + info[j].c;
        int cost = day[i] > info[j].d ? day[i] - info[j].d : 0;
        if (dp[k] + cost <= dp[i]) {
          dp[i] = dp[k] + cost;
          pre[i] = k;
        }
      }
    }
    cout << dp[tot] << endl;
    print(tot);
  }
  return 0;
}
