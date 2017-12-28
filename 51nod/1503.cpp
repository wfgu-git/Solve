/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int maxn = 500 + 20;
const int moder = 1e9 + 7;

int n, m;
char g[maxn][maxn];
int dp[2][maxn][maxn];
void work() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%s", g[i] + 1);
  }
  if (g[1][1] != g[n][m]) {
    cout << 0;
    return;
  }

  memset(dp, 0, sizeof(dp));
  dp[0][1][n] = 1;
  int t = 0;
  for (int k = 1; k <= (n + m - 2) / 2; ++k) {
    t ^= 1;
    memset(dp[t], 0, sizeof(dp[t]));
    for (int x1 = 1; x1 <= n && x1 - 1 <= k; ++x1) {
      int y1 = 1 + (k - (x1 - 1));
      if (y1 > m || y1 < 1) continue;
      for (int x2 = n; x2 >= 1 && n - x2 <= k; --x2) {
        int y2 = m - (k - (n - x2));
        if (y2 > m || y2 < 1) continue;
        if (g[x1][y1] != g[x2][y2]) continue;
        dp[t][x1][x2] = (dp[t][x1][x2] + dp[t ^ 1][x1][x2 + 1]) % moder;
        dp[t][x1][x2] = (dp[t][x1][x2] + dp[t ^ 1][x1 - 1][x2]) % moder;
        dp[t][x1][x2] = (dp[t][x1][x2] + dp[t ^ 1][x1 - 1][x2 + 1]) % moder;
        dp[t][x1][x2] = (dp[t][x1][x2] + dp[t ^ 1][x1][x2]) % moder;
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans = (ans + dp[t][i][i]) % moder;
  }
  if ((n + m) & 1) {
    for (int i = 1; i < n; ++i) {
      ans = (ans + dp[t][i][i + 1]) % moder;
    }
  }
  printf("%d\n", ans);
}
int main() {
  // freopen("data.in", "r", stdin);
  work();
}
