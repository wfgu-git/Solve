#include <bits/stdc++.h>
using namespace std;
const int inf = INT_MAX;
const int maxn = 100000;
int a[maxn * 5 + 1];
int dp_ori[maxn * 5 + 1];
int dp_rev[maxn * 5 + 1];
int len_ori[maxn * 5 + 1];
int len_rev[maxn * 5 + 1];
void get_dp(int *dp, int *len, const int &n) {
  fill(dp, dp + n, inf);
  for (int i = 0; i < n; i++) {
    *lower_bound(dp, dp + n, a[i]) = a[i];
    len[i] = lower_bound(dp, dp + n, inf) - dp;
  }
}
int main() {
  int n;
  while (scanf("%d", &n) == 1) {
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
    }
    get_dp(dp_ori, len_ori, n);
    reverse(a, a + n);
    get_dp(dp_rev, len_rev, n);
    int ans = -1;
    for (int i = 0; i < n; i++) {
      ans = max(ans, min(len_ori[i], len_rev[n - i - 1]));
    }
    printf("%d\n", 2 * ans - 1);
  }
  return 0;
}
