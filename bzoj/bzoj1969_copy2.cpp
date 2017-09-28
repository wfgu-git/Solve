#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e5 + 5, M = 1e5 + 5, P = 1999997;
#define lc x << 1
#define rc x << 1 | 1
#define mid ((l + r) >> 1)
#define lson lc, l, mid
#define rson rc, mid + 1, r
typedef long long ll;
inline int read() {
  char c = getchar();
  int x = 0, f = 1;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}

int n, m, trn, mark[N], Q, c, x, y, del[M];
int Hash[P];
inline int& Map(int x) { return Hash[x % P]; }
struct meow {
  int u, v;
} a[M], tr[N];
struct qmeow {
  int c, u, v, qid;
} q[M];
int ans[M];

struct Graph {
  struct edge {
    int v, ne, id;
  } e[M << 1];
  int cnt, h[N];
  inline void ins(int u, int v, int id) {
    e[++cnt] = (edge){v, h[u], id};
    h[u] = cnt;
    e[++cnt] = (edge){u, h[v], id};
    h[v] = cnt;
  }
  int vis[N];
  void dfs(int u) {
    vis[u] = 1;
    for (int i = h[u]; i; i = e[i].ne)
      if (!vis[e[i].v]) {
        mark[e[i].id] = 1;
        tr[++trn] = a[e[i].id];
        dfs(e[i].v);
      }
  }
} G;

struct edge {
  int v, ne;
} e[N << 1];
int cnt, h[N];
inline void ins(int u, int v) {
  e[++cnt] = (edge){v, h[u]};
  h[u] = cnt;
  e[++cnt] = (edge){u, h[v]};
  h[v] = cnt;
}
int dfn[N], dfc, fa[N], top[N], deep[N], mx[N], size[N];
void dfs(int u) {
  size[u] = 1;
  for (int i = h[u]; i; i = e[i].ne) {
    int v = e[i].v;
    if (v == fa[u]) continue;
    deep[v] = deep[u] + 1;
    fa[v] = u;
    dfs(v);
    size[u] += size[v];
    if (size[v] > size[mx[u]]) mx[u] = v;
  }
}
void dfs2(int u, int anc) {  // printf("u anc %d %d\n",u,anc);
  dfn[u] = ++dfc;
  top[u] = anc;
  if (mx[u]) dfs2(mx[u], anc);
  for (int i = h[u]; i; i = e[i].ne)
    if (e[i].v != fa[u] && e[i].v != mx[u]) dfs2(e[i].v, e[i].v);
}

struct SegmentTree {
  struct meow {
    int sum, tag;
    meow() : tag(-1) {}
  } t[N << 2];
  inline void paint(int x, int l, int r, int v) {
    t[x].tag = v;
    t[x].sum = (r - l + 1) * v;
  }
  inline void pushDown(int x, int l, int r) {
    if (t[x].tag != -1) {
      paint(lson, t[x].tag);
      paint(rson, t[x].tag);
      t[x].tag = 0;
    }
  }
  void build(int x, int l, int r) {
    if (l == r)
      t[x].sum = 1;
    else {
      build(lson);
      build(rson);
      t[x].sum = t[lc].sum + t[rc].sum;
    }
  }
  inline void cover(int x, int l, int r, int ql, int qr, int v) {
    if (ql <= l && r <= qr)
      paint(x, l, r, v);
    else {
      pushDown(x, l, r);
      if (ql <= mid) cover(lson, ql, qr, v);
      if (mid < qr) cover(rson, ql, qr, v);
      t[x].sum = t[lc].sum + t[rc].sum;
    }
  }
  inline int que(int x, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr)
      return t[x].sum;
    else {
      pushDown(x, l, r);
      int ans = 0;
      if (ql <= mid) ans += que(lson, ql, qr);
      if (mid < qr) ans += que(rson, ql, qr);
      return ans;
    }
  }
} S;

void cover(int x, int y, int v) {
  while (top[x] != top[y]) {
    if (deep[top[x]] < deep[top[y]]) swap(x, y);
    S.cover(1, 1, n, dfn[top[x]], dfn[x], v);
    x = fa[top[x]];
  }
  if (dfn[x] > dfn[y]) swap(x, y);
  if (x != y) S.cover(1, 1, n, dfn[x] + 1, dfn[y], v);
}
int query(int x, int y) {
  int ans = 0;
  while (top[x] != top[y]) {
    if (deep[top[x]] < deep[top[y]]) swap(x, y);
    ans += S.que(1, 1, n, dfn[top[x]], dfn[x]);
    x = fa[top[x]];
  }
  if (dfn[x] > dfn[y]) swap(x, y);
  if (x != y) ans += S.que(1, 1, n, dfn[x] + 1, dfn[y]);
  return ans;
}

int main() {
  // freopen("in","r",stdin);
  n = read();
  m = read();
  for (int i = 1; i <= m; i++) {
    x = read();
    y = read();
    if (x > y) swap(x, y);
    a[i] = (meow){x, y};
    Map(x * n + y) = i;
  }
  while (true) {
    c = read();
    if (c == -1) break;
    x = read();
    y = read();
    if (x > y) swap(x, y);
    q[++Q] = (qmeow){c, x, y, 0};
    if (c == 0)
      del[Map(x * n + y)] = 1;
    else
      q[Q].qid = ++ans[0];
  }
  for (int i = 1; i <= m; i++)
    if (!del[i]) G.ins(a[i].u, a[i].v, i);  // printf("hi %d\n",i);

  G.dfs(1);
  for (int i = 1; i <= trn; i++)
    ins(tr[i].u, tr[i].v);  // printf("tr %d %d\n",tr[i].u, tr[i].v);
  dfs(1);
  dfs2(1, 1);
  S.build(1, 1, n);
  for (int i = 1; i <= m; i++)
    if (!mark[i] && !del[i]) cover(a[i].u, a[i].v, 0);

  for (int i = Q; i >= 1; i--) {  // printf("Q %d\n",i);
    if (q[i].c == 0)
      cover(q[i].u, q[i].v, 0);
    else
      ans[q[i].qid] = query(q[i].u, q[i].v);
  }
  for (int i = 1; i <= ans[0]; i++) printf("%d\n", ans[i]);
}
