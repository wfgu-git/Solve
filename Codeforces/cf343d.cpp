#include <bits/stdc++.h>
using namespace std;
#define lson o << 1
#define rson o << 1 | 1
const int maxn = 500000 + 20;
void debug() {printf("!!!!!!!!!\n");}
struct Edge {int u, v, next;} edge[maxn << 1];
int nn;
int cont, head[maxn];
void add_edge(int u, int v) {
  edge[cont] = {u, v, head[u]};
  head[u] = cont++;
}
int in[maxn], out[maxn], arc[maxn], dfs_clock;
int tot, sz[maxn], son[maxn], top[maxn], fa[maxn], id[maxn], deep[maxn];
void dfs(int u, int p, int d) {
  sz[u] = 1;
  fa[u] = p;
  deep[u] = d;
  for (int i = head[u]; i != -1; i = edge[i].next) {
    int v = edge[i].v;
    if (v == p) continue;
    dfs(v, u, d + 1);
    sz[u] += sz[v];
    if (son[u] == -1 || sz[son[u]] < sz[v]) son[u] = v;
  }
}
void link(int u, int first) {
  top[u] = first;
  in[u] = ++dfs_clock;
  id[u] = ++tot;
  arc[in[u]] = u;
  if (son[u] != -1) link(son[u], first);
  for (int i = head[u]; i != -1; i = edge[i].next) {
    int v = edge[i].v;
    if (v == son[u] || v == fa[u]) continue;
    link(v, v);
  }
  out[u] = dfs_clock;
}
struct Segtree {
  struct node {
    int l, r, v;
    int lazy;
  } a[maxn << 2];
  void push_up(int o) {}
  void push_down(int o) {
    if (a[o].lazy == -1) return;

    a[lson].lazy = a[rson].lazy = a[o].lazy;
    a[lson].v = a[rson].v = a[o].lazy;
    a[o].lazy = -1;
  }
  void build(int l = 1, int r = nn + 1, int o = 1) {
    a[o].l = l, a[o].r = r, a[o].v = 0, a[o].lazy = -1;
    if (r - l == 1) return;
    int m = l + (r - l) / 2;
    build(l, m, lson);
    build(m, r, rson);
    push_up(o);
  }
  void update(int l, int r, int k, int o = 1) {
    if (l <= a[o].l && a[o].r <= r) {
      a[o].v = k;
      a[o].lazy = k;
      return;
    }
    push_down(o);
    int m = a[o].l + (a[o].r - a[o].l) / 2;
    if (l < m) update(l, r, k, lson);
    if (r > m) update(l, r, k, rson);
    push_up(o);
  }
  int query(int p, int o = 1) {
    if (p == a[o].l && a[o].r - a[o].l == 1) {
      return a[o].v;
    }
    push_down(o);
    int m = a[o].l + (a[o].r - a[o].l) / 2;
    if (p < m) query(p, lson);
    else query(p, rson);
  }
} st;
void solve(int u) {
  int v = 1;
  while (top[u] != top[v]) {
    if (deep[top[u]] < deep[top[v]]) swap(u, v);
    st.update(id[top[u]], id[u] + 1, 0);
    u = fa[top[u]];
  }
  if (deep[u] > deep[v]) swap(u, v);
  st.update(id[u], id[v] + 1, 0);
}
void init(int n) {
  nn = n;
  tot = dfs_clock = 0;
  cont = 1;
  memset(head, -1, sizeof(head));
  memset(son, -1, sizeof(son));
}
int main() {
  int n;
  scanf("%d", &n);
  init(n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    add_edge(u, v);
    add_edge(v, u);
  }
  dfs(1, 0, 0);
  link(1, 1);
  st.build();
  int m;
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int op, v;
    scanf("%d%d", &op, &v);
    if (op == 1) {
      st.update(id[v], id[arc[out[v]]] + 1, 1);
    } else if (op == 2) {
      solve(v);
    } else {
      printf("%d\n", st.query(id[v]));
    }
  }
  return 0;
}
/*
5
1 2
5 1
2 3
4 2
12
1 1
2 3
3 1
3 2
3 3
3 4
1 2
2 4
3 1
3 3
3 4
3 5
*/
