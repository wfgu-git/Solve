#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 2000;
int ts[maxn + 20];
int td[maxn + 20];
int dp[maxn + 20][2];
int main() {
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; cas++) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &ts[i]);
    }
    for (int i = 2; i <= n; i++) {
      scanf("%d", &td[i]);
    }
    dp[0][0] = dp[0][1] = 0;
    dp[1][0] = ts[1];
    dp[1][1] = inf;
    for (int i = 2; i <= n; i++) {
      dp[i][0] = min(dp[i - 1][0], dp[i -1][1]) + ts[i];
      dp[i][1] = min(dp[i - 2][0], dp[i -2][1]) + td[i];
    }
    int tot = min(dp[n][0], dp[n][1]);
    int h = tot / 3600 + 8;
    tot %= 3600;
    int m = tot / 60;
    tot %= 60;
    int t = tot;
    int flag = true;
    if (h > 12) {
      h %= 12;
      flag = false;
    }
    printf("%02d:%02d:%02d %s\n", h, m, t, (flag)? "am" : "pm");
  }
  return 0;
}
