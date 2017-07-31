#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e7 + 20;
int a[maxn];
int cnt[maxn];
long long n, k, T, b, c, p;
void build() {
  for (int i = 1; i <= n; ++i) {
    a[i] = (a[i - 1] * b + c) % p;
    cnt[i] = cnt[i - 1] + (a[i] >= T);
  }
}
int main() {
  scanf("%lld%lld%lld%d%lld%lld%lld", &n, &k, &T, a + 0, &b, &c, &p);
  build();
    long long ans = 0;
    int l, r;
    l = r = 1;
    while(true) {
      while (r <= n && cnt[r] - cnt[l - 1] < k) ++r;
      if (r > n) break;
      ans += (n - r + 1);
      l++;
    }
    printf("%lld\n", ans);
  return 0;
}
