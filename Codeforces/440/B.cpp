/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;
const int mxlg = 20 + 5;

int n, k;
int a[maxn];
int dp[maxn][mxlg];
// [l, r]
int query(int l, int r) {
  // // int k = 0;
  // while ((1 << k + 1) <= r - l + 1) ++k;
  int k = log(r - l + 1) / log(2.0);
  return min(dp[l][k], dp[r - (1 << k) + 1][k]);
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("/home/wfgu/Documents/solve/data.in", "r", stdin);
  freopen("/home/wfgu/Documents/solve/data.out", "w", stdout);
#endif
  // ios::sync_with_stdio(false);
  // cin.tie(0);

  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  if (k >= 3) {
    cout << *max_element(a, a + n);
    return 0;
  }
  if (k == 1) {
    cout << *min_element(a, a + n);
    return 0;
  }
  if (k == 2) {
    for (int i = 0; i < n; ++i) dp[i][0] = a[i];
    for (int j = 1; (1 << j) <= n; ++j) {
      for (int i = 0; i + (1 << j) - 1 < n; ++i) {
        dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
      }
    }

    int x, y, ans = -inf;
    for(int i = 0; i < n - 1; ++i) {
      x = query(0, i);
      y = query(i + 1, n - 1);
      ans = max(ans, max(x, y));
    }
    cout << ans;
    return 0;
  }
}
