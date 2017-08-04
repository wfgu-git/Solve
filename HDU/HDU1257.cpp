#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 20;
int dp[maxn];
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    dp[0] = 0;
    int cont = 0;
    for (int i = 0; i < n; ++i) {
      int x;
      scanf("%d", &x);
      int it = lower_bound(dp, dp + cont, x) - dp;
      if (it == cont) {
        dp[cont++] = x;
      } else {
        dp[it] = x;
      }
    }
    printf("%d\n", cont);
  }
  return 0;
}
