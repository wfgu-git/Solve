#include <bits/stdc++.h>
using namespace std;
const long long inf = 0x3f3f3f3f;
const int maxn = 100000 + 5;
const int maxm = 1000 + 20;
int c[maxm], w[maxm];
int a[maxn], b[maxn];
int cont[25][2010];
long long dp[25][2010];
int main() {
  int n, m;
  while (scanf("%d%d", &n, &m) != EOF) {
    memset(cont, 0, sizeof(cont));
    int max_atk = -1;
    for (int i = 0; i < n; ++i) {
      static int hp, shield;
      scanf("%d%d", &hp, &shield);
      a[i] = hp; b[i] = shield;
      ++cont[shield][hp];
    }
    for (int i = 0; i < m; ++i) {
      scanf("%d%d", c + i, w + i);
      max_atk = max(max_atk, w[i]);
    }
    bool flag = false;
    for (int i = 0; i < n; ++i) {
      if (max_atk <= b[i]) {
        flag = true;
        break;
      }
    }
    for (int i = 0; i <= 20; ++i) {
      for (int j = 1; j <= 1010; ++j) {
        dp[i][j] = inf;
      }
    }
    for (int i = 0; i <= 20; ++i) {
      dp[i][0] = 0;
      for (int j = 1; j <= 1010; ++j) {
        for (int k = 0; k < m; ++k) if (w[k] >= i) {
          int d = w[k] - i;
          int from = (j - d >= 0 ? j - d : 0);
          dp[i][j] = min(dp[i][j], dp[i][from] + c[k] * 1LL);
        }
      }
    }
    long long ret = 0;
    for (int i = 0; i <= 20; ++i) {
      for (int j = 1; j <= 1010; ++j) if (cont[i][j]) {
        ret += 1LL * cont[i][j] * dp[i][j];
      }
    }
    if (flag) printf("-1\n");
    else printf("%lld\n", ret);
  }
  return 0;
}
