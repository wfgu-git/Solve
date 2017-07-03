#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6;
int dp[2][maxn + 2];
int a[maxn + 2];

int main() {
  int n, m;
  while (scanf("%d%d", &m, &n) == 2) {
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
    }
    memset(dp, 0, sizeof(dp));

    int cur = 0;
    for (int i = 1; i <= m; i++) {
      dp[cur][i] = dp[cur ^ 1][i - 1] + a[i];
      int Max = dp[cur ^ 1][i - 1];
      for (int j = i + 1; j <= n - m + i; j++) {
        Max = max(Max, dp[cur ^ 1][j - 1]);
        dp[cur][j] = max(dp[cur][j - 1], Max) + a[j];
      }
      cur ^= 1;
    }
    cur ^= 1;
    int ans = -INT_MAX;
    for (int i = m; i <= n; i++) {
      ans = max(ans, dp[cur][i]);
    }
    printf("%d\n", ans);
  }
  return 0;
}
