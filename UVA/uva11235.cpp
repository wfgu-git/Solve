#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 20;
const int logmaxn = 20 + 5;
struct RMQ {
  int dp[maxn][logmaxn];
  void init(const vector<int> &a) {
    int n = a.size();
    for (int i = 0; i < n; ++i) dp[i][0] = a[i];
    for (int j = 1; (1 << j) <= n; ++j) {
      for (int i = 0; i + (1 << j) -1 < n; ++i) {
        dp[i][j] = max(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
      }
    }
  }
  int query(int l, int r) {
    // int k = log(r - l + 1) / log(2.0);
    int k = 0;
    while ((1 << k + 1) <= r - l + 1) ++k;
    return min(dp[l][k], dp[r - (1 << k) + 1][k]);
  }
} rmq;
int a[maxn];
int val[maxn], cnt[maxn];
int num[maxn];
int L[maxn], R[maxn];
int main() {
  int n, q;
  while (scanf("%d", &n) != EOF && n) {
    scanf("%d", &q);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", a + i);
    }
    int tot = 0;
    int p = 1;
    while (p < n) {
      static int now;
      now = val[++tot] = a[p];
      L[tot] = p;
      while (p < n - 1 && a[p + 1] == now) ++p;
      R[tot] = p;
      cnt[tot] = R[tot] - L[tot] + 1;
      ++p;
    }
    for (int i = 1; i <= tot; ++i) {
      printf("val = %d, cnt = %d, num = %d, L = %d, R = %d\n", val[i], cnt[i], num[i], L[i], R[i]);

    }
    for (int i = 0; i < q; ++i) {
      static int l, r;
      scanf("%d%d", &l, &r);

    }
  }
  return 0;
}
