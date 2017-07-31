#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxp = 30 + 5;
const int maxn = 50000 + 20;
void debug() {cout << "!!!!" << endl;}
vector<int> g[maxn];
void add_edge(int u, int v) {
  g[u].push_back(v);
  g[v].push_back(u);
}
int n, k;
map<long long, int> root[maxn];
ll p[maxp], w[maxn];
ll ans;
inline void init(int n) {
  ans = 0;
  for (int i = 1; i <= n; ++i) {
    g[i].clear();
    root[i].clear();
  }
}
inline void getw(int now, ll val) {
  ll ret = 0;
  for (int i = 1; i <= k; ++i) {
    int temp = 0;
    while (val && val % p[i] == 0) {
      ++temp;
      val /= p[i];
    }
    temp %= 3;
    ret = ret * 3 + temp;
  }
  w[now] = ret;
}
static int temp[maxp];
ll add(ll a, ll b) {
  for (int i = k; i >= 1; --i) {
    temp[i] = (a + b) % 3;
    a /= 3;
    b /= 3;
  }
  ll ret = 0;
  for (int i = 1; i <= k; ++i) {
    ret = ret * 3 + temp[i];
  }
  return ret;
}
ll arc(ll a, ll b) {
  for (int i = k; i >= 1; --i) {
    temp[i] = ((a - b) % 3 + 3) % 3;
    a /= 3;
    b /= 3;
  }
  ll ret = 0;
  for (int i = 1; i <=k; ++i) {
    ret = ret * 3 + temp[i];
  }
  return ret;
}
int merge(map<ll, int> &a, map<ll, int> b) {
  int ret = 0;
  map<ll, int> t;
  for (auto x : a) {
    for (auto y : b) {
      ret += x.second * b[arc(0, x.first)];
      t[add(x.first, y.first)] += x.second * y.second;
    }
  }
  for (auto x : t) {
    a[x.first] += x.second;
  }
  return ret;
}
void dfs(int u, int p) {
  for (int v : g[u]) {
    if (v == p) continue;
    dfs(v, u);
    if (root[u].size() < root[v].size()) swap(root[u], root[v]);
    ans += merge(root[u], root[v]);
  }
  if (w[u] == 0) ++ans;
  if (root[u].size() == 0) {
    (root[u])[w[u]] = 1;
  } else {
    map<ll, int> t;
    for (auto x : root[u]) {
      t[add(x.first, w[u])] = x.second;
    }
    for (auto x : t) {
      (root[u])[x.first] += x.second;
    }
  }
}
int main() {
  while (scanf("%d", &n) != EOF) {
    init(n);
    scanf("%d", &k);
    for (int i = 1; i <= k; ++i) {
      scanf("%lld", p + i);
    }
    for (int i = 1; i <= n; ++i) {
      ll x;
      scanf("%lld", &x);
      getw(i, x);
    }
    for (int i = 1; i < n; ++i) {
      static int u, v;
      scanf("%d%d", &u, &v);
      add_edge(u, v);
    }
    dfs(1, 0);
    printf("%lld\n", ans);
  }
}
