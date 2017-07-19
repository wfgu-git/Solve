#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define lson o << 1
#define rson o << 1 | 1
const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 20;
void debug() {printf("!!!!!!!!!!\n");}
int nn, cont, head[maxn];
struct Edge {int u, v, d, next;} edge[maxn << 1];
void add_edge(int u, int v, int d) {
  edge[cont] = {u, v, d, head[u]};
  edge[cont + nn] = {v, u, d, head[v]};
  head[u] = cont, head[v] = cont + nn;
  cont++;
}
void filp(int &x, int &y) {
  swap(x, y), x = -x, y = -y;
}
struct Segtree {
  struct node {
    int l, r, max, min;
    int rev;
  } a[maxn << 2];
  void push_up(int o) {
    a[o].max = max(a[lson].max, a[rson].max);
    a[o].min = min(a[lson].min, a[rson].min);
  }
  void push_down(int o) {
    if (!a[o].rev) return;
    a[lson].rev ^= 1, a[rson].rev ^= 1;
    filp(a[lson].min, a[lson].max);
    filp(a[rson].min, a[rson].max);
    a[o].rev = 0;
  }
  void build(int l = 1, int r = nn + 1, int o = 1) {
    a[o].l = l, a[o].r = r, a[o].rev = 0;
    a[o].min = inf, a[o].max = -inf;
    if (r - l == 1) return;
    int m = l + (r - l) / 2;
    build(l, m, lson);
    build(m, r, rson);
  }
  void update(int p, int k, int o = 1) {
    if (p == a[o].l && a[o].r - a[o].l == 1) {
      a[o].min = a[o].max = k;
      return;
    }
    push_down(o);
    int m = a[o].l + (a[o].r - a[o].l) / 2;
    if (p < m) update(p, k, lson);
    else update(p, k, rson);
    push_up(o);
  }
  void updatelr(int l, int r, int o = 1) {
    if (l <= a[o].l && a[o].r <= r) {
      a[o].rev ^= 1;
      filp(a[o].min, a[o].max);
      return;
    }
    push_down(o);
    int m = a[o].l + (a[o].r - a[o].l) / 2;
    if (l < m) updatelr(l, r, lson);
    if (r > m) updatelr(l, r, rson);
    push_up(o);
  }
  int query(int l, int r, int o = 1) {
    if (l <= a[o].l && a[o].r <= r) {
      return a[o].max;
    }
    push_down(o);
    int m = a[o].l + (a[o].r - a[o].l) / 2;
    int ret = -inf;
    if (l < m) ret = max(ret, query(l, r, lson));
    if (r > m) ret = max(ret, query(l, r, rson));
    return ret;
  }
} st;
int id[maxn], sz[maxn], son[maxn], top[maxn], deep[maxn], fa[maxn], tot;
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
  id[u] = ++tot;
  if (son[u] != -1) link(son[u], first);
  for (int i = head[u]; i != -1; i = edge[i].next) {
    int v = edge[i].v;
    if (v == fa[u] || v == son[u]) continue;
    link(v, v);
  }
}
void change(int k, int val) {
  int u = edge[k].u;
  int v = edge[k].v;
  if (deep[u] > deep[v]) swap(u, v);
  st.update(id[v], val);
}
int solve(int u, int v) {
  if (u == v) return 0;
  int ret = -inf;
  while (top[u] != top[v]) {
    if (deep[top[u]] < deep[top[v]]) swap(u, v);
    ret = max(ret, st.query(id[top[u]], id[u] + 1));
    u = fa[top[u]];
  }
  if (u == v) return ret;
  if (deep[u] > deep[v]) swap(u, v);
  ret = max(ret, st.query(id[son[u]], id[v] + 1));
  return ret;
}
void negate(int u, int v) {
  while (top[u] != top[v]) {
    if (deep[top[u]] < deep[top[v]]) swap(u, v);
    st.updatelr(id[top[u]], id[u] + 1);
    u = fa[top[u]];
  }
  if (u == v) return;
  if (deep[u] > deep[v]) swap(u, v);
  st.updatelr(id[son[u]], id[v] + 1);
}
void init(int n) {
  nn = n;
  cont = 1;
  tot = 0;
  memset(head, -1, sizeof(head));
  memset(son, -1, sizeof(son));
}
int main() {
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    int n;
    scanf("%d", &n);
    init(n);
    for (int i = 1;  i < n; i++) {
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
    char op[10];
    while (~scanf("%s", op)) {
      if (op[0] == 'D') break;
      int x, y;
      scanf("%d%d", &x, &y);
      if (op[0] == 'Q') {
        printf("%d\n", solve(x, y));
      } else if (op[0] == 'C') {
        change(x, y);
      } else if (op[0] == 'N') {
        negate(x, y);
      }
    }
  }
  return 0;
}
