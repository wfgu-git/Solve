/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int moder = 1e9 + 7;

char grid[502][502];
int dp[2][252][252];
void work() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> grid[i][j];
    }
  }

  if (grid[1][1] != grid[n][m]) {
    cout << 0;
    return;
  }

  memset(dp, 0, sizeof(dp));
  dp[0][1][n] = 1;
  int k = 0;
  for (int step = 1; step <= (n + m - 2) / 2; ++step) {
    k ^= 1;
    memset(dp[k], 0, sizeof(dp[k]));
    for (int x1 = 1; x1 <= n && x1 - 1 <= step; ++x1) {
      int y1 = 1 + (step - (x1 - 1));
      if (y1 > m || y1 < 1) continue;
      for (int x2 = n; x2 >= 1 && n - x2 <= step; --x2) {
        int y2 = m - (step - (n - x2));
        if (y2 > m || y2 < 1) continue;
        if (grid[x1][y1] != grid[x2][y2]) continue;
        dp[k][x1][x2] = (dp[k][x1][x2] + dp[k ^ 1][x1][x2]) % moder;
        dp[k][x1][x2] = (dp[k][x1][x2] + dp[k ^ 1][x1 - 1][x2 + 1]) % moder;
        dp[k][x1][x2] = (dp[k][x1][x2] + dp[k ^ 1][x1][x2 + 1]) % moder;
        dp[k][x1][x2] = (dp[k][x1][x2] + dp[k ^ 1][x1 - 1][x2]) % moder;
      }
    }
  }

  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans = (ans + dp[k][i][i]) % moder;
  }
  if ((n + m) & 1) {
    for (int i = 1; i < n; ++i) {
      ans = (ans + dp[k][i][i + 1]) % moder;
    }
  }
  cout << ans << endl;
}
int main() {
  // freopen("data.in", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  work();
}
