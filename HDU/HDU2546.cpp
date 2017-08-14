#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;
int dp[maxn][maxn];
int v[maxn];
int m;

int main() {
  int n;
  while (cin >> n && n) {
    memset(v, 0, sizeof(v));
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) cin >> v[i];
    sort(v + 1, v + n + 1);
    int maxv = v[n];
    cin >> m;
    if (m < 5)
      cout << m << endl;
    else {
      for (int i = 1; i <= n - 1; i++) {
        for (int j = m - 5; j >= 0; j--) {
          dp[i][j] = (i == 1 ? 0 : dp[i - 1][j]);
          if (j >= v[i]) dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i]] + v[i]);
        }
      }
      cout << m - (dp[n - 1][m - 5] + maxv) << endl;
    }
  }
  return 0;
}
