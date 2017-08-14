#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 20;
int N, V, K;
int w[maxn], c[maxn];
int dp[1010][35];
int tmp1[maxn], tmp2[maxn];
inline void work() {
  scanf("%d%d%d", &N, &V, &K);
  for (int i = 1; i <= N; ++i) {
    scanf("%d", w + i);
  }
  for (int i = 1; i <= N; ++i) {
    scanf("%d", c + i);
  }
  memset(dp, 0, sizeof(dp));

  for (int i = 1; i <= N; ++i) {
    for (int j = V; j >= c[i]; j--) {
      for (int k = 1; k <= K; ++k) {
        tmp1[k] = dp[j][k];
        tmp2[k] = dp[j - c[i]][k] + w[i];
      }
      tmp1[K + 1] = tmp2[K + 1] = -1;
      int p, q, cont;
      cont = p = q = 1;
      while (cont <= K && (p <= K || q <= K)) {
        if (tmp1[p] > tmp2[q]) {
          dp[j][cont] = tmp1[p++];
        } else {
          dp[j][cont] = tmp2[q++];
        }
        if (dp[j][cont - 1] != dp[j][cont]) {
          ++cont;
        }
      }
    }
  }
  printf("%d\n", dp[V][K]);
}
int main() {
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    work();
  }
}
