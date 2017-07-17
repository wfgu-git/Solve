#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100000 + 20;
struct Edge {int u, v, d, next;} edge[maxn * 2];
int nn;
int head[maxn], cont;
int sz[maxn], son[maxn], deep[maxn], top[maxn], fa[maxn], id[maxn], tot;
void add_edge(int u, int v, int d) {
  edge[cont] = {u, v, d, head[u]};
  head[u] = cont;
  edge[cont + nn] = {v, u, d, head[v]};
  head[v] = cont + nn;
  cont++;
}
struct Segtree {
  struct node {
    int l, r, v;
  } a[maxn << 2];
  void push_up(int o) {
    a[o].v = a[o << 1].v + a[o << 1 | 1].v;
  }
  void build(int l = 1, int r = nn + 1, int o = 1) {
    a[o].l = l, a[o].r = r, a[o].v = 0;
    if (r - l == 1) return;
    int m = l + (r - l) / 2;
    build(l, m, o << 1);
    build(m, r, o << 1 | 1);
    push_up(o);
  }
  void update(int p, int k, int o = 1) {
    if (p == a[o].l && a[o].r - a[o].l == 1) {
      a[o].v = k;
      return;
    }
    int m = a[o].l + (a[o].r - a[o].l) / 2;
    if (p < m) update(p, k, o << 1);
    else update(p, k, o << 1 | 1);
    push_up(o);
  }
  int query(int l, int r, int o = 1) {
    if (l <= a[o].l && a[o].r <= r) {
      return a[o].v;
    }
    int ret = 0;
    int m = a[o].l + (a[o].r - a[o].l) / 2;
    if (l < m) ret += query(l, r, o << 1);
    if (r > m) ret += query(l, r, o << 1 | 1);
    return ret;
  }
} st;
void dfs(int u, int p, int d) {
  sz[u] = 1;
  fa[u] = p;
  deep[u] = d;
  int mx = -1;
  for (int i = head[u]; i != -1; i = edge[i].next) {
    int v = edge[i].v;
    if (v == p) continue;
    dfs(v, u, d + 1);
    sz[u] += sz[v];
    if (mx < sz[v]) {
      son[u] = v;
      mx = sz[v];
    }
  }
}
void link(int u, int first) {
  top[u] = first;
  id[u] = ++tot;
  if (son[u]) link(son[u], first);
  for (int i = head[u]; i != -1; i = edge[i].next) {
    int v = edge[i].v;
    if (v == fa[u] || v == son[u]) continue;
    link(v, v);
  }
}
int solve(int u, int v) {
  int ret =  0;
  while (top[u] != top[v]) {
    if (deep[top[u]] < deep[top[v]]) swap(u, v);
    ret += st.query(id[top[u]], id[u] + 1);
    u = fa[top[u]];
  }
  if (u == v) return ret;
  if (deep[u] > deep[v]) swap(u, v);
  ret += st.query(id[son[u]], id[v] + 1);
  return ret;
}
void init(int n) {
  nn = n;
  tot = 0, cont = 1;
  memset(son, 0, sizeof(son));
  memset(head, -1, sizeof(head));
}
int main() {
  int n, m, s;
  while (~scanf("%d%d%d", &n, &m, &s)) {
    init(n);
    for (int i = 1; i < n; i++) {
      int u, v, d;
      scanf("%d%d%d", &u, &v, &d);
      add_edge(u, v, d);
    }
    dfs(1, 0, 0);
    link(1, 1);
    st.build();
    for (int i = 1; i < n; i++) {
      int u = edge[i].u;
      int v = edge[i].v;
      int d = edge[i].d;
      if (deep[u] > deep[v]) swap(u, v);
      st.update(id[v], d);
    }
    for (int i = 0; i < m; i++) {
      int op, a, b;
      scanf("%d", &op);
      if (op == 0) {
        scanf("%d", &a);
        printf("%d\n", solve(s, a));
        s = a;
      } else {
        scanf("%d%d", &a, &b);
        int u = edge[a].u;
        int v = edge[a].v;
        if (deep[u] > deep[v]) swap(u, v);
        st.update(id[v], b);
      }
    }
  }
  return 0;
}
