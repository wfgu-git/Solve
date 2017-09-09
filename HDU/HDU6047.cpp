#include <bits/stdc++.h>
using namespace std;
const int moder = 1000000007;
const int inf = 0x3f3f3f3f;
const int maxn = 250000 + 20;
const int logmaxn = 25 + 5;
int a[maxn], b[maxn], sub[maxn];
int nn;
struct RMQ {
  int dp[maxn][logmaxn];
  void init(int *v, int n) {
    for (int i = 1; i <= n; i++) dp[i][0] = v[i];
    for (int j = 1; (1 << j) <= n; j++) {
      for (int i = 1; i + (1 << j) - 1 <= n; i++) {
        dp[i][j] = max(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
      }
    }
  }
  int query(int l, int r) {
    int k = log((double)(r - l + 1)) / log(2.0);
    return max(dp[l][k], dp[r - (1 << k) + 1][k]);
  }
} rmq;
using ll = long long;
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    for_each(a + 1, a + n + 1, [](int &x) {scanf("%d", &x);});
    priority_queue<int, vector<int>, greater<int> > q;
    for (int i = 1; i <= n; i++) {
      scanf("%d", b + i);
      q.push(b[i]);
    }
    for (int i = 1; i <= n; i++) sub[i] = a[i] - i;
    rmq.init(sub, n);
    ll ans = 0;
    int maxv = -inf;
    for (int i = n + 1; i <= 2 * n; i++) {
      static int temp;
      int j = q.top(); q.pop();
      temp = max(rmq.query(j, n), maxv);
      ans = (ans + temp) % moder;
      maxv = max(maxv, temp - i);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
