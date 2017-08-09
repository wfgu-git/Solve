#include <bits/stdc++.h>
using namespace std;
const int maxn = 200 + 20;
const int maxf = 6080;
int two[maxn], five[maxn];
int dp[maxn][maxf];
int main() {
  int N, K;
  while (scanf("%d%d", &N, &K) != EOF) {
    for (int i = 1; i <= N; ++i) {
      long long x;
      scanf("%lld", &x);
      static int cnt;
      cnt = 0;
      while (x % 2LL == 0LL) {
        ++cnt; x /= 2;
      }
      two[i] = cnt;
      cnt = 0;
      while (x % 5LL == 0LL) {
        ++cnt; x /= 5;
      }
      five[i] = cnt;
    }
    memset(dp, -0x3f, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= N; ++i) {
      for (int j = K; j >= 1; --j) {
        for (int k = 6000; k >= five[i]; --k) {
          dp[j][k] = max(dp[j][k], dp[j - 1][k - five[i]] + two[i]);
        }
      }
    }
    int ans = 0;
    // for (int j = 0; j <= K; ++j) {
      for (int k = 0; k <= 6000; ++k) {
        ans = max(ans, min(dp[K][k], k));
      }
    // }
    printf("%d\n", ans);
  }
  return 0;
}
