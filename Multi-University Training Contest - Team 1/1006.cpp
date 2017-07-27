#include <bits/stdc++.h>
using namespace std;
const int moder = 1e9 + 7;
const int maxn = 100000 + 20;
using ll = long long;
ll mod_pow(int x, int n) {
  ll ret = 1, base = x;
  while (n) {
    if (n & 1)
      ret = ret * base % moder;
    base = base * base % moder;
    n >>= 1;
  }
  return ret;
}
int n, m;
int a[maxn], b[maxn];
bool vis[maxn];
int loop_a[maxn], loop_b[maxn];
void solve(int kase) {
  memset(loop_a, 0, sizeof(loop_a));
  memset(loop_b, 0, sizeof(loop_b));
  for_each(a, a + n, [](int &x){scanf("%d", &x);});
  for_each(b, b + m, [](int &x){scanf("%d", &x);});
  memset(vis, 0, sizeof(vis));
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      int len = 0;
      while (!vis[i]) {
        ++len;
        vis[i] = true;
        i = a[i];
      }
      loop_a[len]++;
    }
  }
  memset(vis, 0, sizeof(vis));
  for (int i = 0; i < m; i++) {
    if (!vis[i]) {
      int len = 0;
      while (!vis[i]) {
        ++len;
        vis[i] = true;
        i = b[i];
      }
      loop_b[len]++;
    }
  }
  ll ans = 1;
  for (int i = 1; i <= n; ++i) {
    ll ret = 0;
    for (int j = 1; j * j <= i; ++j) {
      if (i % j == 0) {
        int k = j;
        ret += 1LL * loop_b[j] * j;
        if (j * j != i) {
          k = i / j;
          ret += 1LL * loop_b[k] * k;
        }
      }
    }
    int x = loop_a[i];
    ans = 1LL * ans * mod_pow(ret, x) % moder;
  }
  printf("Case #%d: %lld\n", kase, ans);
}
int main() {
  int kase = 0;
  while (scanf("%d%d", &n, &m) != EOF) {
    solve(++kase);
  }
  return 0;
}
