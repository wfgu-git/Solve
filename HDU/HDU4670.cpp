#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 50000 + 20;
const int maxp = 30 + 20;
int n, k;
ll p[maxp], w[maxn];
ll sum[maxn];
ll ans;
int tot;
int tid[maxn], son[maxn], sz[maxn], fa[maxn];
vector<int> g[maxn];
map<ll, int> root[maxn];
void add_edge(int u, int v) {
  g[u].push_back(v);
  g[v].push_back(u);
}
void get_w(int now, long long v) {
  ll ret = 0;
  for (int i = 0; i < k; ++i) {
    int temp = 0;
    while (true) {
      if (v % p[i]) break;
      v /= p[i];
      ++temp;
    }
    temp %= 3;
    ret = ret * 3 + temp;
  }
  w[now] = ret;
}
int _temp[maxp];
ll add(ll a, ll b) {
  for (int i = k - 1; i >= 0; --i) {
    _temp[i] = (a + b) % 3;
    a /= 3;
    b /= 3;
  }
  ll ret = 0;
  for (int i = 0; i < k; ++i) {
    ret = ret * 3 + _temp[i];
  }
  return ret;
}
ll arc(ll a, ll b) {
  for (int i = k - 1; i >= 0; --i) {
    _temp[i] = ((a - b) % 3 + 3) % 3;
    a /= 3;
    b /= 3;
  }
  ll ret = 0;
  for (int i = 0; i < k; ++i) {
    ret = ret * 3 + _temp[i];
  }
  return ret;
}
void dfs(int u, int p) {
  sz[u] = 1;
  fa[u] = p;
  for (int v : g[u]) {
    if (v == p) continue;
    dfs(v, u);
    sz[u] += sz[v];
    if (son[u] == -1 || sz[son[u]] < sz[v]) {
      son[u] = v;
    }
  }
}
void dsu(int u) {

}
void init(int _n) {
  memset(sum, 0, sizeof(sum));
  memset(son, -1, sizeof(son));
  for (int i = 1; i <= _n; ++i) {
    g[i].clear();
  }
}
int main() {
  while (scanf("%d", &n) != EOF) {
    init(n);
    scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
      scanf("%lld", p + i);
    }
    for (int i = 1; i <= n; ++i) {
      ll x;
      scanf("%lld", &x);
      get_w(i, x);
      root[i].clear();
    }
    for (int i = 1; i < n; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      add_edge(u, v);
    }
    ans = 0;
    tot = 0;
    dfs(1, 0);
    dsu(1);
    printf("%lld\n", ans);
  }
  return 0;
}
/*
3
2
2 3
6 27 36
1 3
2 3
*/
