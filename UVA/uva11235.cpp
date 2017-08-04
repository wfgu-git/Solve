#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 20;
const int logmaxn = 30;
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
    while ((1 << (k + 1)) <= r - l + 1) ++k;
    return max(dp[l][k], dp[r - (1 << k) + 1][k]);
  }
} rmq;
int n, q;
int a[maxn];
int num[maxn], L[maxn], R[maxn];
int main() {
  while (scanf("%d", &n) != EOF && n) {
    scanf("%d", &q);
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
    }
    a[n] = a[n - 1] + 1;
    int p;
    vector<int> cont;
    for (int i = 0; i <= n; ++i) {
      if (!i || a[i] != a[i - 1]) {
        if (i) {
          cont.push_back(i - p);
          for (int j = p; j < i; ++j) {
            num[j] = cont.size() - 1;
            L[j] = p;
            R[j] = i - 1;
          }
        }
        p = i;
      }
    }
    rmq.init(cont);
    for (int i = 0; i < q; ++i) {
      int l, r;
      int ans;
      scanf("%d%d", &l, &r);
      --l; --r;
      if (num[l] == num[r]) {
        ans = r - l + 1;
      } else {
        ans = max(R[l] - l + 1, r - L[r] + 1);
        if (num[r] - num[l] > 1)
          ans = max(ans, rmq.query(num[l] + 1, num[r] - 1));
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}
