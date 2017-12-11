#include <bits/stdc++.h>
using namespace std;
const int maxn = 150000 + 20;
int a, b, c, d, k;
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
  scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
  if (b > d) swap(b, d);
  if (k == 0) {
    printf("Case %d: 0\n", kase);
    return;
  }
  long long ret1, ret2;
  ret1 = ret2 = 0;
  for (int i = k; i <= b; i += k) {
    ret1 += 1LL * mu[i / k] * (b / i) * (d / i);
    ret2 += 1LL * mu[i / k] * (b / i) * (b / i);
  }
  long long ans = ret1 - (ret2 - 1) / 2;
  printf("Case %d: %I64d\n", kase, ans);
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
