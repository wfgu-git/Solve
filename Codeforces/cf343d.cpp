#include <bits/stdc++.h>
using namespace std;
const int maxn = 500000 + 200;
vector< vector< int > > g;
int st[maxn + 2], ft[maxn + 2];
int sz[maxn + 2], fa[maxn + 2], depth[maxn + 2], son[maxn + 2], id[maxn + 2], top[maxn + 2];
int dfs_clock, tot;
void get_info(int u, int p, int d) {
  sz[u] = 1;
  fa[u] = p;
  depth[u] = d;
  for (auto v : g[u]) {
    if (v == p) continue;
    get_info(v, u, d + 1);
    sz[u] += sz[v];
    if (son[u] == -1 || sz[son[u]] < sz[v]) son[u] = v;
  }
}
void dfs(int u, int first) {
  st[u] = ++dfs_clock;
  id[st[u]] = u;
  top[u] = first;
  if (son[u] == -1) {
    ft[u] = dfs_clock + 1;
    return;
  }
  dfs(son[u], first);
  for (auto v : g[u]) {
    if (v == fa[u] || v == son[u]) continue;
    dfs(v, v);
  }
  ft[u] = dfs_clock + 1;
}
int seg[maxn * 4 + 2], lazy[maxn * 4 + 2], nn;
void maintain(int o) {
  seg[o] = 0;
  seg[o] = max(seg[o << 1], seg[o << 1 | 1]);
  if (lazy[o] >= 0) seg[o] = lazy[o];
}
void push_down(int o) {
  if (lazy[o] == -1) return;

  lazy[o << 1] = lazy[o << 1 | 1] = lazy[o];
  lazy[o] = -1;
}
void update(int ql, int qr, int k, int l = 1, int r = nn + 1, int o = 1) {
  if (ql <= l && r <= qr) {
    lazy[o] = k;
    return;
  }
  push_down(o);
  int m = l + (r - l) / 2;
  if (ql < m) update(ql, qr, k, l, m, o << 1);
  if (qr > m) update(ql, qr, k, m, r, o << 1 | 1);
  maintain(o);
}
int query(int p, int l = 1, int r = nn + 1, int o = 1) {
  if (lazy[o] >= 0) return lazy[o];
  if (p == l && r - l == 1) {
    return seg[o];
  }
  push_down(o);
  int m = l + (r - l) / 2;
  if (p < m) return query(p, l, m, o << 1);
  else return query(p, m, r, o << 1 | 1);
}
void modify(int u, int k, int v = 1) {
  int top1 = top[u], top2 = top[v];
  while (top1 != top2) {
    if (depth[top1] < depth[top2]) {
      swap(top1, top2);
      swap(u, v);
    }
    update(id[top1], id[u] + 1, k);
    u = fa[top1];
    top1 = top[u];
  }
  if (depth[u] > depth[v]) swap(u, v);
  update(id[u], id[v] + 1, k);
}
void init(int n) {
  nn = n;
  dfs_clock = tot = 0;
  memset(son, -1, sizeof(son));
  memset(seg, 0, sizeof(seg));
  memset(lazy, 0, sizeof(lazy));
  g.resize(n + 2);
  g.clear();
}
int main() {
  int n;
  scanf("%d", &n);
  init(n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  get_info(1, 0, 0);
  dfs(1, 1);
  int m;
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int op, k;
    scanf("%d%d", &op, &k);
    if (op == 1) {
      update(st[k], ft[k], 1);
    } else if (op == 2) {
      modify(k, 0);
    } else {
      printf("%d\n", query(k));
    }
  }
  return 0;
}
