#include <cstdio>
#include <cstring>
#include <cctype>
#include <utility>
#include <algorithm>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 30000 + 20;
#define lson o << 1
#define rson o << 1 | 1
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
    int l, r, sum;
    int max;
  } a[maxn << 2];
  void push_up(int o) {
    a[o].sum = a[lson].sum + a[rson].sum;
    a[o].max = max(a[lson].max, a[rson].max);
  }
  void push_down(int o) {}
  void build(int *val, int *arc, int l = 1, int r = nn + 1, int o = 1) {
    a[o].l = l, a[o].r = r, a[o].sum = 0, a[o].max = -inf;
    if (r - l == 1) {
      a[o].sum = a[o].max = val[arc[l]];
      return;
    }
    int m = (l + r) / 2;
    build(val, arc, l, m, lson);
    build(val, arc, m, r, rson);
    push_up(o);
  }
  void update(int p, int k, int o = 1) {
    if (p == a[o].l && a[o].r - a[o].l == 1) {
      a[o].sum = a[o].max = k;
      return;
    }
    push_down(o);
    int m = (a[o].l + a[o].r) / 2;
    if (p < m) update(p, k, lson);
    else update(p, k, rson);
    push_up(o);
  }
  int querySum(int l, int r, int o = 1) {
    if (l <= a[o].l && a[o].r <= r) {
      return a[o].sum;
    }
    push_down(o);
    int ret = 0;
    int m = (a[o].l + a[o].r) / 2;
    if (l < m) ret += querySum(l, r, lson);
    if (r > m) ret += querySum(l, r, rson);
    return ret;
  }
  int queryMax(int l, int r, int o = 1) {
    if (l <= a[o].l && a[o].r <= r) {
      return a[o].max;
    }
    push_down(o);
    int ret = -inf;
    int m = (a[o].l + a[o].r) / 2;
    if (l < m) ret = max(ret, queryMax(l, r, lson));
    if (r > m) ret = max(ret, queryMax(l, r, rson));
    return ret;
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
int get_sum(int u, int v) {
  int ret = 0;
  while (top[u] != top[v]) {
    if (deep[top[u]] < deep[top[v]]) swap(u, v);
    ret += st.querySum(tid[top[u]], tid[u] + 1);
    u = fa[top[u]];
  }
  if (deep[u] > deep[v]) swap(u, v);
  ret += st.querySum(tid[u], tid[v] + 1);
  return ret;
}
int get_max(int u, int v) {
  int ret = -inf;
  while (top[u] != top[v]) {
    if (deep[top[u]] < deep[top[v]]) swap(u, v);
    ret = max(ret, st.queryMax(tid[top[u]], tid[u] + 1));
    u = fa[top[u]];
  }
  if (deep[u] > deep[v]) swap(u, v);
  ret = max(ret, st.queryMax(tid[u], tid[v] + 1));
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
  int n;
  while (scanf("%d", &n) == 1) {
    init(n);
    for (int i = 1; i < n; ++i) {
      int u, v;
      read(u); read(v);
      add_edge(u, v);
    }
    for (int i = 1; i <= n; ++i) {
      read(w[i]);
    }
    dfs(1, 0, 0);
    link(1, 1);
    st.build(w, arc);
    int m;
    read(m);
    char op[10];
    int x, y;
    for (int i = 0; i < m; ++i) {
      scanf("%s", op);
      read(x);read(y);
      if (op[3] == 'X') {
        printf("%d\n", get_max(x, y));
      } else if (op[3] == 'M') {
        printf("%d\n", get_sum(x, y));
      } else {
        // printf("CHANG v = %d(%d) w = %d\n", x, tid[x], y);
        st.update(tid[x], y);
      }
    }
  }
  return 0;
}
