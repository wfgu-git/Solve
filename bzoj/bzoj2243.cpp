#include <cstdio>
#include <cstring>
#include <cctype>
#include <utility>
#include <algorithm>
using namespace std;
const int maxn = 500000 + 20;
#define lson o << 1
#define rson o << 1 | 1
int nn, cont, head[maxn];
struct Edge {int u, v, next;} edge[maxn << 1];
void add_edge(int u, int v) {
  edge[cont].u = u;
  edge[cont].v = v;
  edge[cont].next = head[u];
  head[u] = cont++;
}
struct Segtree {
  struct node {
    int l, r, sum;
    int lazy, lc, rc;
  } a[maxn << 2];
  void push_up(int o) {
    a[o].sum = a[lson].sum + a[rson].sum - (a[lson].rc == a[rson].lc);
    a[o].lc = a[lson].lc;
    a[o].rc = a[rson].rc;
  }
  void push_down(int o) {
    if (a[o].lazy == -1) return;

    a[lson].lazy = a[rson].lazy = a[o].lazy;
    a[lson].sum = a[rson].sum = 1;
    a[lson].lc = a[lson].rc = a[o].lazy;
    a[rson].lc = a[rson].rc = a[o].lazy;
    a[o].lazy = -1;
  }
  void build(int *val, int *arc, int l = 1, int r = nn + 1, int o = 1) {
    a[o].l = l, a[o].r = r, a[o].sum = 0;
    a[o].lazy = a[o].lc = a[o].rc = -1;
    int m = (l + r) / 2;
    if (r - l == 1) {
      a[o].sum = 1;
      a[o].rc = a[o].lc = val[arc[l]];
      return;
    }
    build(val, arc, l, m, lson);
    build(val, arc, m, r, rson);
    push_up(o);
  }
  void update(int l, int r, int k, int o = 1) {
    if (l <= a[o].l && a[o].r <= r) {
      a[o].sum = 1;
      a[o].lazy = a[o].lc = a[o].rc = k;
      return;
    }
    push_down(o);
    int m = (a[o].l + a[o].r) / 2;
    if (l < m) update(l, r, k, lson);
    if (r > m) update(l, r, k, rson);
    push_up(o);
  }
  int query(int l, int r, int o = 1) {
    if (l <= a[o].l && a[o].r <= r) {
      return a[o].sum;
    }
    push_down(o);
    int ret = 0;
    int m = (a[o].l + a[o].r) / 2;
    if (l < m) ret += query(l, r, lson);
    if (r > m) ret += query(l, r, rson);
    if (l < m && r > m && a[lson].rc == a[rson].lc) --ret;
    return ret;
  }
  int queryc(int p, int o = 1) {
    if (p == a[o].l && a[o].r - a[o].l == 1) {
      return a[o].lc;
    }
    push_down(o);
    int m = (a[o].l + a[o].r) / 2;
    if (p < m) return queryc(p, lson);
    else return queryc(p, rson);
  }
} st;
int tot, fa[maxn], top[maxn], sz[maxn], son[maxn], deep[maxn], tid[maxn], arc[maxn];
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
  arc[tid[u]] = u;
  if (son[u] != -1) link(son[u], first);
  for (int i = head[u]; i != -1; i = edge[i].next) {
    int v = edge[i].v;
    if (v == fa[u] || v == son[u]) continue;
    link(v, v);
  }
}
void modify(int u, int v, int k) {
  while (top[u] != top[v]) {
    if (deep[top[u]] < deep[top[v]]) swap(u, v);
    st.update(tid[top[u]], tid[u] + 1, k);
    u = fa[top[u]];
  }
  if (deep[u] > deep[v]) swap(u, v);
  st.update(tid[u], tid[v] + 1, k);
}
int solve(int u, int v) {
  int ret = 0;
  while (top[u] != top[v]) {
    if (deep[top[u]] < deep[top[v]]) swap(u, v);
    ret += st.query(tid[top[u]], tid[u] + 1);
    if (st.queryc(tid[top[u]]) == st.queryc(tid[fa[top[u]]])) --ret;
    u = fa[top[u]];
  }
  if (deep[u] > deep[v]) swap(u, v);
  ret += st.query(tid[u], tid[v] + 1);
  return ret;
}
void init(int n) {
  nn = n;
  tot = 0, cont = 1;
  memset(head, -1, sizeof(head));
  memset(son, -1, sizeof(son));
}
int w[maxn];
template<class T> inline bool read(T &n){
    T x = 0, tmp = 1;
    char c = getchar();
    while((c < '0' || c > '9') && c != '-' && c != EOF) c = getchar();
    if(c == EOF) return false;
    if(c == '-') c = getchar(), tmp = -1;
    while(c >= '0' && c <= '9') x *= 10, x += (c - '0'),c = getchar();
    n = x*tmp;
    return true;
}
int main() {
  int n, m;
  while (scanf("%d%d", &n, &m) == 2) {
    init(n);
    for (int i = 1; i <= n; i++) {
      read(w[i]);
    }
    for (int i = 1; i < n; i++) {
      int u, v;
      read(u);read(v);
      add_edge(u, v);
      add_edge(v, u);
    }
    dfs(1, 0, 0);
    link(1, 1);
    st.build(w, arc);
    char op[2];
    for (int i = 0; i < m; i++) {
      scanf("%s", op);
      int x, y, z;
      if (op[0] == 'Q') {
        read(x);read(y);
        printf("%d\n", solve(x, y));
      } else {
        read(x);read(y);read(z);
        modify(x, y, z);
      }
    }
  }
  return 0;
}
