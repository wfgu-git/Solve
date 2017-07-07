#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 500;
int dp[10000 + 1];
int w[maxn + 20];
int c[maxn + 20];
int main() {
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; cas++) {
    int e, f;
    scanf("%d%d", &e, &f);
    int tot = f - e;
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d%d", c + i, w + i);
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
      for (int v = w[i]; v <= tot; v++) {
        dp[v] = min(dp[v], dp[v - w[i]] + c[i]);
      }
    }
    if (dp[tot] != inf)
      printf("The minimum amount of money in the piggy-bank is %d.\n", dp[tot]);
    else
      printf("This is impossible.\n");
  }
  return 0;
}
