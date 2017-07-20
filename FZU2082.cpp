#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 50000 + 20;
#define lson o << 1
#define rson o << 1 | 1
void debug() {printf("!!!!!!!!!\n");}
int nn, cont, head[maxn];
struct Edge {int u, v, d, next;} edge[maxn * 2];
void add_edge(int u, int v, int d) {
  edge[cont].u = u, edge[cont].v = v, edge[cont].d = d, edge[cont].next = head[u];
  edge[cont + nn].u = v, edge[cont + nn].v = u, edge[cont + nn].d = d, edge[cont + nn].next = head[v];
  head[u] = cont, head[v] = cont + nn;
  cont++;
}
struct Segtree {
  struct node {
    int l, r;
    int v;
  } a[maxn << 2];
  void push_up(int o) {
    a[o].v = a[lson].v + a[rson].v;
  }
  void build(int l = 1, int r = nn + 1, int o = 1) {
    a[o].l = l, a[o].r = r, a[o].v = 0;
    if (r - l == 1) return;
    int m = l + (r - l) / 2;
    build(l, m, lson);
    build(m, r, rson);
    push_up(o);
  }
  void update(int p, int k, int o = 1) {
    if (p == a[o].l && a[o].r - a[o].l == 1) {
      a[o].v = k * 1LL;
      return;
    }
    int m = a[o].l + (a[o].r - a[o].l) / 2;
    if (p < m) update(p, k, lson);
    else update(p, k, rson);
    push_up(o);
  }
  int query(int l, int r, int o = 1) {
    if (l <= a[o].l && a[o].r <= r) {
      return a[o].v;
    }
    int ret = 0;
    int m = a[o].l + (a[o].r - a[o].l) / 2;
    if (l < m) ret += query(l, r, lson);
    if (r > m) ret += query(l, r, rson);
    return ret;
  }
} st;
int sz[maxn], son[maxn], deep[maxn], top[maxn], fa[maxn], tid[maxn], tot;
void dfs(int u, int p, int d) {
  sz[u] = 1;
  fa[u] = p;
  deep[u] = d;
  for (int i = head[u]; i != -1; i = edge[i].next) {
    int v = edge[i].v;
    if (v == p) continue;
    dfs(v, u, d + 1);
    sz[u] += sz[v];
    if (son[u] == -1 || sz[v] > sz[son[u]]) son[u] = v;
  }
}
void link(int u, int first) {
  top[u] = first;
  tid[u] = ++tot;
  if (son[u] != -1) link(son[u], first);
  for (int i = head[u]; i != -1; i = edge[i].next) {
    int v = edge[i].v;
    if (v == fa[u] || v == son[u]) continue;
    link(v, v);
  }
}
void change(int k, int x) {
  int u = edge[k].u;
  int v = edge[k].v;
  if (deep[u] > deep[v]) swap(u, v);
  st.update(tid[v], x);
}
int get_ans(int u, int v) {
  int ret =  0;
  while (top[u] != top[v]) {
    if (deep[top[u]] < deep[top[v]]) swap(u, v);
    ret += st.query(tid[top[u]], tid[u] + 1);
    u = fa[top[u]];
  }
  if (u == v) return ret;
  if (deep[u] > deep[v]) swap(u, v);
  ret += st.query(tid[son[u]], tid[v] + 1);
  return ret;
}
void init(int n) {
  nn = n;
  tot = 0, cont = 1;
  memset(son, -1, sizeof(son));
  memset(head, -1, sizeof(head));
}
int main() {
  int n, m;
  while (~scanf("%d%d", &n, &m)) {
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
      change(i, edge[i].d);
    }
    int op, a, b;
    for (int i = 0; i < m; i++) {
      scanf("%d%d%d", &op, &a, &b);
      if (op == 0) {
        change(a, b);
      } else {
        printf("%d\n", get_ans(a, b));
      }
    }
  }
  return 0;
}
