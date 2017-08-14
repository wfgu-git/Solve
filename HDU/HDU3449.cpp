#include <bits/stdc++.h>
using namespace std;
const int maxn = 50 + 20;
const int maxv = 100000 + 20;
int N, W;
int dp[maxv];
int tdp[maxv];
inline void work() {
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i <= N; ++i) {
    static int box, m;
    scanf("%d%d", &box, &m);
    memcpy(tdp, dp, sizeof(dp));
    for (int j = 1; j <= m; ++j) {
      static int c, w;
      scanf("%d%d", &c, &w);
      for (int v = W - box; v >= c; --v) {
        tdp[v] = max(tdp[v], tdp[v - c] + w);
      }
    }
    for (int v = box; v <= W; ++v) {
      dp[v] = max(dp[v], tdp[v - box]);
    }
  }
  printf("%d\n",dp[W]);
}
int main() {
  // freopen("data.in", "r", stdin);
  while (scanf("%d%d", &N, &W) != EOF) {
    work();
  }
  return 0;
}
