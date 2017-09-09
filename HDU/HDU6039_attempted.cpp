/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 20;

#define lson o << 1
#define rson o << 1 | 1
int kase = 0;
int n, m, q;
int L[maxn], R[maxn], dfs_clock;
int root[maxn];
int radius[maxn];
int dist[maxn];
int nn;
vector<int> tG[maxn];
struct Edge {
  int v, w, r;
} ;
vector<Edge> G[maxn];
struct Segtree {
  struct node {
    int l, r, max;
    int lazy;
  } a[maxn << 2];
  void push_up(int o) {
    a[o].max = max(a[lson].max, a[rson].max);
  }
  void push_down(int o) {
    if (a[o].lazy != -1) {
      a[lson].lazy = a[rson].lazy = a[o].lazy;
      a[lson].max += a[o].lazy;
      a[rson].max += a[o].lazy;
      a[o].lazy = -1;
    }
  }
  void build(int l = 1, int r = nn + 1, int o = 1) {
    a[o].l = l; a[o].r = r; a[o].max = 0; a[o].lazy = -1;
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
      a[o].max += k;
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
      return a[o].max;
    }
    push_down(o);
    int m = (a[o].l + a[o].r) / 2;
    int ret = -1;
    if (l < m) ret = max(ret, query(l, r, lson));
    if (r > m) ret = max(ret, query(l, r, rson));
    return ret;
  }
} seg;
struct UFset {
  int n;
  int fa[maxn], rank[maxn];
  inline void init(int n) {
    this->n = n;
    for (int i = 0; i <= n; ++i) {
      rank[i] = 0;
      fa[i] = i;
    }
  }
  inline int find(int x) {
    if (x != fa[x]) {
      fa[x] = find(fa[x]);
    }
    return fa[x];
  }

  inline bool same(int x, int y) {
    return find(x) == find(y);
  }

  inline int unite(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y) return 0;

    if (rank[x] < rank[y]) {
      fa[x] = y;
    } else {
      fa[y] = x;
      if (rank[x] == rank[y]) ++rank[x];
    }
    /* 统计某个为祖先有几个元素
    fa[y] = x;
    rank[x] += rank[y];
    */
    return 1;
  }
} st;
void dfs(int u, int p, int d, int rt) {
  L[u] = ++dfs_clock;
  root[u] = rt;
  dist[L[u]] = d;
  for (int i = 0; i < G[u].size(); ++i) {
    Edge& e = G[u][i];
    if (e.v == p) {
      dfs(e.v, u, d + e.w, rt);
    } else {

    }
  }
  R[u] = dfs_clock;
}
void work(int cas) {
  st.init(n);
  for (int i = 1; i <= n; ++i) {
    tG[i].clear();
    G[i].clear();
    scanf("%d", radius + i);
    radius[i] = log2(radius[i]);
  }
  dfs_clock = 0;

  for (int i = 0; i < m; ++i) {
    static int op, x, y;
    scanf("%d%d%d", &op, &x, &y);
    if (op == 1) {
      tG[x].push_back(y);
      tG[y].push_back(x);
    } else {
      st.unite(x, y);
    }
  }

  for (int x = 1; x <= n; ++x) {
    for (const int& y : tG[x]) {
      G[st.find(x)].push_back((Edge){st.find(y), x, radius[x] - radius[y]});
    }
  }

  memset(root, 0, sizeof(root));
  memset(R, 0, sizeof(R));
  memset(L, 0x3f, sizeof(L));
  for (int i = 1; i <= n; ++i) {
    if (i == st.find(i) && !root[i]) {
      dfs(i, 0, 0, i);
    }
  }
  nn = dfs_clock;
}
int main() {
  while (scanf("%d%d%d", &n, &m, &q) != EOF) {
    work(++kase);
  }
}
