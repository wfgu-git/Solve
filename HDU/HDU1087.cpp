#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 1000;
int a[maxn + 1];
ll dp[maxn + 1];
int main() {
  int n;
  while (scanf("%d", &n) == 1 && n) {
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
    }
    ll ans = -inf;
    for (int i = 0; i < n; i++) {
      dp[i] = a[i];
      for (int j = 0; j < i; j++) {
        if (a[j] < a[i]) {
          dp[i] = max(dp[i], dp[j] + a[i]);
        }
      }
      ans = max(ans, dp[i]);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
