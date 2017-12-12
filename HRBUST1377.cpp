/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 60 + 20;

int dp[maxn][32005];
int w[maxn][3];
int p[maxn][3];
void work() {
  int n, V;
  while (cin >> V >> n) {
    memset(w, 0, sizeof(w));
    memset(p, 0, sizeof(p));
    for (int i = 1; i <= n; ++i) {
      int v, tp, q;
      cin >> v >> tp >> q;
      if (!q) {
        w[i][0] = v;
        p[i][0] = tp;
      } else {
        if (!w[q][1]) {
          w[q][1] = v;
          p[q][1] = tp;
        } else {
          w[q][2] = v;
          p[q][2] = tp;
        }
      }
    }

    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; ++i) {
      for (int j = V; j >= 0; --j) {
        int c0 = w[i][0];
        int c1 = w[i][1];
        int c2 = w[i][2];
        int w0 = c0 * p[i][0];
        int w1 = c1 * p[i][1];
        int w2 = c2 * p[i][2];
        if (j >= c0) {
          dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - c0] + w0);
          if (j >= c0 + c1) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j - c0 - c1] + w0 + w1);
          }
          if (j >= c0 + c2) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j - c0 - c2] + w0 + w2);
          }
          if (j >= c0 + c1 + c2) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j - c0 - c1 - c2] + w0 + w1 + w2);
          }
        } else {
          dp[i][j] = dp[i - 1][j];
        }
      }
    }
    cout << dp[n][V] << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  // freopen("data.in", "r", stdin);
  work();
}
