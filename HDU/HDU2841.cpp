#include <bits/stdc++.h>
using namespace std;
const int maxn = 150000 + 20;
int n, m;
int vis[maxn];
int mu[maxn];
int prime[maxn], tot;
void init() {
  memset(vis, 0, sizeof(vis));
  mu[1] = 1;
  tot = 0;
  for (int i = 2; i < maxn; i++) {
    if (!vis[i]) {
      prime[tot++] = i;
      mu[i] = -1;
    }
    for (int j = 0; j < tot && i * prime[j] < maxn; j++) {
      vis[i * prime[j]] = 1;
      if (i % prime[j])
        mu[i * prime[j]] = -mu[i];
      else {
        mu[i * prime[j]] = 0;
        break;
      }
    }
  }
}
inline void work(int kase) {
  scanf("%d%d", &n, &m);
  if (m > n) swap(n, m);
  const int k = 1;
  long long ans = 0LL;
  for (int i = k; i <= m; i += k) {
    ans += 1LL * mu[i] * (m / i) * (n / i);
  }
  printf("%lld\n", ans);
}
int main() {
  init();
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    work(cas);
  }
  return 0;
}
