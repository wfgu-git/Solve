#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 20;
int N, M;
int info[maxn][maxn];
int dp[maxn];
inline void work() {
  int V = M;
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= M; ++j) {
      scanf("%d", &info[i][j]);
    }
  }
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i <= N; ++i) {
    for (int v = V; v >= 0; --v) {
      for (int j = 1; j <= M; ++j) if (v >= j){
        dp[v] = max(dp[v], dp[v - j] + info[i][j]);
        // dp[i][v] = max(dp[i - 1][v], dp[i - 1][v - j] + info[i][j]);
      }
    }
  }
  printf("%d\n", dp[M]);
}
int main() {
  while (scanf("%d%d", &N, &M) != EOF && (N + M)) {
    work();
  }
  return 0;
}
