#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define lson o << 1
#define rson o << 1 | 1
const int maxn = 50000 + 20;
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
int nn, cont, head[maxn];
struct Edge {int u, v, next;} edge[maxn << 1];
void add_edge(int u, int v) {
  edge[cont] = {u, v, head[u]};
  edge[cont + nn] = {v, u, head[v]};
  head[u] = cont, head[v] = cont + nn;
  cont++;
}
struct Segtree {
  struct node {
    int l, r, v;
    int add;
  } a[maxn << 2];
  void push_up(int o) {
    a[o].v = a[lson].v + a[rson].v;
  }
  void push_down(int o ) {
    if (!a[o].add) return;
    a[lson].add += a[o].add;
    a[rson].add += a[o].add;
    a[lson].v += (a[lson].r - a[lson].l) * a[o].add;
    a[rson].v += (a[rson].r - a[rson].l) * a[o].add;
    a[o].add = 0;
  }
  void build(int l = 1, int r = nn + 1, int o = 1) {
    a[o].l = l, a[o].r = r, a[o].v = a[o].add = 0;
    if (r - l == 1) {
      return;
    }
    int m = (l + r) / 2;
    build(l, m, lson);
    build(m, r, rson);
    push_up(o);
  }
  void update(int l, int r, int k, int o = 1) {
    if (l <= a[o].l && a[o].r <= r) {
      a[o].add += k;
      a[o].v += (a[o].r - a[o].l) * k;
      return;
    }
    push_down(o);
    int m = (a[o].l + a[o].r) / 2;
    if (l < m) update(l, r, k, lson);
    if (r > m) update(l, r, k, rson);
    push_up(o);
  }
  int query(int p, int o = 1) {
    if (p == a[o].l && a[o].r - a[o].l == 1) {
      return a[o].v;
    }
    push_down(o);
    int m = (a[o].l + a[o].r) / 2;
    if (p < m) return query(p, lson);
    else return query(p, rson);
    push_up(o);
  }
} st;
int tot, id[maxn], top[maxn], sz[maxn], fa[maxn], son[maxn], deep[maxn];
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
void modify(int u, int v, int k) {
  while (top[u] != top[v]) {
    if (deep[top[u]] < deep[top[v]]) swap(u, v);
    st.update(id[top[u]], id[u] + 1, k);
    u = fa[top[u]];
  }
  if (deep[u] > deep[v]) swap(u, v);
  st.update(id[u], id[v] + 1, k);
}
void init(int n) {
  nn = n;
  cont = 1, tot = 0;
  memset(head, -1, sizeof(head));
  memset(son, -1, sizeof(son));
}
int w[maxn];
int main() {
  int n, m, q;
  while (scanf("%d%d%d", &n, &m, &q) == 3) {
    init(n);
    for (int i = 1; i <= n; ++i) {
      read(w[i]);
    }
    for (int i = 0; i < m; ++i) {
      int u, v;
      read(u), read(v);
      add_edge(u, v);
    }
    dfs(1, 0, 0);
    link(1, 1);
    st.build();
    for (int i = 1; i <= n; ++i) {
      modify(i, i, w[i]);
    }
    char op[2];
    for (int i = 0; i < q; ++i) {
      scanf("%s", op);
      int l, r, k;
      if (op[0] == 'I') {
        read(l), read(r), read(k);
        modify(l, r, k);
      } else if (op[0] == 'D') {
        read(l), read(r), read(k);
        modify(l, r, -k);
      } else if (op[0] == 'Q'){
        read(k);
        printf("%d\n", st.query(id[k]));
      }
    }
  }
  return 0;
}
