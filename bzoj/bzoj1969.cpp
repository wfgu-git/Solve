/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 30000 + 20;
const int maxm = 100000 + 20;
const int maxq = 40000 + 20;

#define lson o << 1
#define rson o << 1 | 1

int n, m;
struct Edge {int u, v;} edges[maxm];
vector<int> G[maxn];
vector<query> Qs;
map<pair<int, int>, bool> > S;
int parent[mxlg][maxn];
int L[maxn], R[maxn], dfs_clock;
int fa[maxn];
int find(int x) {
  if (x != fa[x]) {
    fa[x] = find(fa[x]);
  }
  return fa[x];
}
void unite(int x, int y) {
  x = find(x);
  y = find(y);
  if (depth[x] > depth[y]) {
    swap(x, y);
  }
  fa[y] = x;
}
void dfs(int u, int p, int d) {
  L[u] = ++dfs_clock;
  depth[u] = d;
  parent[0][u] = p;
  for (int v : G[u]) {
    if (v != p) {
      dfs(v, u, d + 1);
    }
  }
  R[u] = dfs_clock;
}
void lca_init() {
  dfs(1, -1, 0);
  for (int k = 1; k + 1 < mxlg; ++k) {
    for (int v = 1; v <= n; ++v) {
      parent[k + 1][v] = (parent[k][v] < 0) ? -1 : parent[k][parent[k][v]];
    }
  }
}
void lca(int u, int v) {
  if (depth[u] > depth[v]) swap(u, v);
  for (int k = 0; k < mxlg; ++k) {
    if ((depth[v] - depth[u]) >> k & 1) {
      v = parent[k][v];
    }
  }
  if (v == u) return u;
  for (int k = 0; k < mxlg; ++k) {
    if (parent[k][v] != parent[k][u]) {
      v = parent[k][v];
      u = parent[k][u];
    }
  }
  return parent[0][u];
}
struct SegTree {
  struct node {int l, r, v, lazy;} a[maxn << 2];
  void push_down(int o) {
    if (a[o].lazy != -1) {
      a[lson].lazy += a[o].lazy;
      a[rson].lazy += a[o].lazy;
      a[lson].v += (a[lson].r - a[lson].l) * a[lson].lazy;
      a[rson].v += (a[rson].r - a[rson].l) * a[rson].lazy;
      a[o].lazy = -1;
    }
  }
  void build(int l, int r, int o = 1) {
    a[o].l = l;
    a[o].r = r;
    a[o].v = 0;
    a[o].lazy = -1;
    if (l + 1 == r) {
      return;
    }
    int m = (l + r) / 2;
    build(l, m, lson);
    build(m, r, rson);
  }
  void update(int l, int r, int k, int o = 1) {
    if (l <= a[o].l && a[o].r <= r) {
      a[o].lazy += k;
      a[o].v += k * (a[o].r - a[o].l);
      return;
    }
    push_down(o);
    int m = (a[o].l + a[o].r) / 2;
    if (l < m) update(l, r, k, lson);
    if (r < m) update(l, r, k, rson);
  }
  int query(int p, int o = 1) {
    if (a[o].l == p && a[o].l + 1 == a[o].r) {
      return a[o].v;
    }
    push_down(o);
    int m = (a[o].l + a[o].r) / 2;
    if (p < m) return query(p, lson);
    else return query(p, rson);
  }
} seg;
int get_ans(int u, int v) {
  u = find(u);
  v = find(v);
  int t = find(lca(u, v));
  return seg.query(L[u]) + seg.query(L[v]) - 2 * seg.query(L[t]);
}
void input() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    G[u].push_back(v);
    G[v].push_back(u);
    edges[i] = {u, v};
  }
  while (~scanf("%d", &opt) && opt != -1) {
    int x, y;
    scanf("%d%d", &x, &y);
    Qs.push_back({opt, x, y});
    if (opt == 0) {
      S[make_pair(x, y)] = 1;
      S[make_pair(y, x)] = 1;
    }
  }
}
void work() {
}
int main() {
  input();
  work();
}
