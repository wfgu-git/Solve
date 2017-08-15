#include <cstdio>
#include <cstring>
#include <algorithm>
using std::max;
const int maxv = 32000 + 20;
const int maxn = 60 + 20;
int dp[maxn][maxv];
int w[maxn][3];
int p[maxn][3];
int V, N;
inline void work() {
  memset(w, 0, sizeof(w));
  memset(p, 0, sizeof(p));
  for (int i = 1; i <= N; ++i) {
    static int v, ex, belong;
    scanf("%d%d%d", &v, &ex, &belong);
    if (!belong) {
      w[i][0] = v;
      p[i][0] = ex;
    } else {
      if (!w[belong][1]) {
        w[belong][1] = v;
        p[belong][1] = ex;
      } else {
        w[belong][2] = v;
        p[belong][2] = ex;
      }
    }
  }

  memset(dp, 0, sizeof(dp));
  for (int i = 1; i <= N; ++i) {
    for (int j = V; j >= 0; --j) {
      int cm = w[i][0];
      int c1 = w[i][1];
      int c2 = w[i][2];
      int wm = cm * p[i][0];
      int w1 = c1 * p[i][1];
      int w2 = c2 * p[i][2];
      if (j >= cm) {
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cm] + wm);
        if (j - cm - c1 >= 0) {
          dp[i][j] = max(dp[i][j], dp[i - 1][j - cm - c1] + wm + w1);
        }
        if (j - cm - c2 >= 0) {
          dp[i][j] = max(dp[i][j], dp[i - 1][j - cm - c2] + wm + w2);
        }
        if (j - cm - c1 - c2 >= 0) {
          dp[i][j] = max(dp[i][j], dp[i - 1][j - cm - c1 - c2] + wm + w1 + w2);
        }
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }
  printf("%d\n", dp[N][V]);
}
int main() {
  // freopen("data.in", "r", stdin);
  while (scanf("%d%d", &V, &N) != EOF) {
    work();
  }
  return 0;
}
