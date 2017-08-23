/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;
#define lson o << 1
#define rson o << 1 | 1

int n, q;
ll w[maxn];
vector<int> G[maxn];
void add_edge(int u, int v) {
  G[u].push_back(v);
  G[v].push_back(u);
}
int depth[maxn], tid[maxn], arc[maxn], sz[maxn], son[maxn], top[maxn], fa[maxn], tot;
void dfs(int u, int p, int d) {
  depth[u] = d;
  sz[u] = 1;
  fa[u] = p;
  for (const int& v : G[u]) {
    if (v == p) continue;
    dfs(v, u, d + 1);
    sz[u] += sz[v];
    if (son[u] == -1 || sz[son[u]] < sz[v]) son[u] = v;
  }
}
void link(int u, int first) {
  top[u] = first;
  tid[u] = ++tot;
  arc[tid[u]] = u;
  if (son[u] != -1) link(son[u], first);
  for (const int& v : G[u]) {
    if (v == fa[u] || v == son[u]) continue;
    link(v, v);
  }
}
struct Segtree {
  struct node {
    int l, r;
    ll sum, max, min;
  } a[maxn << 2];
  void push_up(int o) {
    a[o].sum = a[lson].sum + a[rson].sum;
    a[o].max = max(a[lson].max, a[rson].max);
    a[o].min = min(a[lson].min, a[rson].min);
  }
  void build(int l = 1, int r = n + 1, int o = 1) {
    a[o].l = l; a[o].r = r;
    a[o].sum = a[o].max = a[o].min = 0LL;
    if (l + 1 == r) {
      a[o].sum = a[o].max = a[o].min = w[arc[l]];
      return;
    }
    int m = (l + r) / 2;
    build(l, m, lson);
    build(m, r, rson);
    push_up(o);
  }
  ll query(int l, int r, ll lb, ll ub, int o = 1) {
    if (l <= a[o].l && a[o].r <= r) {
      if (a[o].min > ub || a[o].max < lb) return 0;
      if (a[o].min >= lb && a[o].max <= ub) return a[o].sum;
    }
    int m = (a[o].l + a[o].r) / 2;
    ll ret = 0;
    if (l < m) ret += query(l, r, lb, ub, lson);
    if (r > m) ret += query(l, r, lb, ub, rson);
    return ret;
  }
} st;
ll solve(int u, int v, ll lb, ll ub) {
  ll ret = 0;
  while (top[u] != top[v]) {
    if (depth[top[u]] < depth[top[v]]) swap(u, v);
    ret += st.query(tid[top[u]], tid[u] + 1, lb, ub);
    u = fa[top[u]];
  }
  if (depth[u] > depth[v]) swap(u, v);
  ret += st.query(tid[u], tid[v] + 1, lb, ub);
  return ret;
}
void work() {
  tot = 0;
  for (int i = 1; i <= n; ++i) {
    G[i].clear();
    son[i] = -1;
  }

  for (int i = 1; i <= n; ++i) {
    scanf("%lld", w + i);
  }
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    add_edge(u, v);
  }
  dfs(1, 0, 0);
  link(1, 1);
  st.build();
  vector<ll> ans;
  for (int i = 0; i < q; ++i) {
    int u, v;
    ll lb, ub;
    scanf("%d%d%lld%lld", &u, &v, &lb, &ub);
    ans.push_back(solve(u, v, lb, ub));
  }
  for (int i = 0; i < q; ++i) {
    printf("%lld%c", ans[i], (i == q - 1 ? '\n' : ' '));
  }
}
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  while (scanf("%d%d", &n, &q) != EOF) {
    work();
  }
  return 0;
}
