#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1e5;
int a[maxn + 2];
long long sum[maxn + 2];
int l[maxn + 2], r[maxn + 2];
int main() {
  int n;
  while (scanf("%d", &n) == 1) {
    memset(sum, 0, sizeof(sum));
    for (int i = 1; i <= n; ++i) {
      scanf("%d", a + i);
      l[i] = r[i] = i;
      sum[i] = sum[i - 1] + a[i];
    }
    for (int i = 2; i <= n; i++) {
      int now = i;
      while (now >= 2 && a[i] <= a[now - 1]) now = l[now - 1];
      l[i] = now;
    }
    for (int i = n - 1; i >= 0; i--) {
      int now = i;
      while (now <= n - 1 && a[i] <= a[now + 1]) now = r[now + 1];
      r[i] = now;
    }
    long long ans = -1;
    int L, R;
    for (int i = 1; i <= n; i++) {
      long long cur = a[i] * 1LL * (sum[r[i]] - sum[l[i] - 1]);
      if (ans < cur) {
        ans = cur;
        L = l[i], R = r[i];
      }
    }
    printf("%lld\n%d %d\n", ans, L, R);
  }
  return 0;
}
