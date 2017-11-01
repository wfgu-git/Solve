/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef __int64 ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 10000 + 20;
const int moder = 1e8 + 7;

ll dp[10002][5][3];
ll p[3] = {1, 2, 1};
ll a[150000];
char line[150000];
void work() {
  int T;
  scanf("%d", &T);
  while (T--) {
    memset(dp, 0, sizeof(dp));
    scanf("%s", line);
    int n = strlen(line);
    int flag = 1;
    for (int i = 1; i <= n; ++i) {
      a[i] = line[i - 1] - '0';
      if (i == 1 && a[i] > 4) flag = 0;
      if (i == n && a[i] > 4) flag = 0;
      if (a[i] > 6) flag = 0;
    }

    if (!flag) {
      printf("0\n");
      continue;
    }

    if (n == 1) {
      if (a[1] <= 2) printf("%d\n", p[a[1]]);
      else printf("0\n");
      continue;
    }

    for (int i = 0; i <= 2; ++i) {
      if (a[1] >= i) {
        dp[1][i][i] = p[i];
      } else {
        dp[1][i][i] = 0;
      }
    }

    for (int i = 2; i <= n; ++i) {
      for (int j = 0; j <= 4; ++j) {
        for (int k = 0; k <= 2; ++k) {
          int q = a[i - 1] - k;
          int l = j - k;
          if (q >= 0 && l >= 0 && j >= k && q >= l && j >= l) {
            dp[i][j][k] += p[k] * dp[i - 1][q][l];
            dp[i][j][k] %= moder;
          }
        }
      }
    }
    ll ans = 0;
    for (int i = 0; i <= a[n] && i <= 2; ++i) {
      ans += dp[n][a[n]][i];
      ans %= moder;
    }
    printf("%I64d\n", ans);
  }
}
int main() {
  // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  // freopen("data.in", "r", stdin);
  /*
  need __int64 && I64d , or return a tle
  */
  work();
}
