#include <bits/stdc++.h>
using namespace std;
const int maxn = 500000 + 20;
int vis[maxn], mu[maxn], prime[maxn], tot;
void Mobius () {
  memset(vis, 0, sizeof(vis));
  mu[1] = 1;
  tot = 0;
  for (int i = 2; i < maxn; ++i) {
    if (!vis[i]) {
      prime[tot++] = i;
      mu[i] = -1;
    }
    for (int j = 0; j < tot && i * prime[j] < maxn; ++j) {
      vis[i * prime[j]] = 1;
      if (i % prime[j] == 0) {
        mu[i * prime[j]] = 0;
        break;
      } else {
        mu[i * prime[j]] = -mu[i];
      }
    }
  }
}
int n, m, P;
void work() {
  scanf("%d%d%d", &n, &m, &P);
  if (n < m) swap(n, m);
}
int main() {
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    work();
  }
  return 0;
}
