/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
// #include <ext/rope>
using namespace std;
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;


const int inf = 0x3f3f3f3f;
const int mxlg = 20;
const int maxn = 30000 + 20;
const int maxm = 500000 + 20;

#define lson o << 1
#define rson o << 1 | 1

int N, M, Q;
vector<int> ans;
vector<int> G[maxn];
vector<pii> edges;
bool bridge[maxm];
map<pii, bool> mark;
int dfn[maxn], low[maxn], fa[maxn], dfs_clock;
int L[maxn], R[maxn], tid;
int parent[mxlg][maxn], depth[maxn];
void add_edge(int u, int v) {
  edges.push_back({u, v});
  edges.push_back({v, u});
  int m = edges.size();
  G[u].push_back(m - 2);
  G[v].push_back(m - 1);
}
void tarjan(int u, int p) {
  dfn[u] = low[u] = ++dfs_clock;
  for (int i = 0; i < G[u].size(); ++i) {
    int x = G[u][i];
    int v = edges[x].second;
    if (v == p || mark.count(edges[x])) continue;
    if (!dfn[v]) {
      tarjan(v, u);
      low[u] = min(low[u], low[v]);
      if (low[v] > dfn[u]) {
        bridge[x] = 1;
        bridge[x ^ 1] = 1;
      } else {
        low[u] = min(low[u], dfn[v]);
      }
    }
  }
}
int find(int x) {
  return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void unite(int u, int v) {
  if ((u = find(u)) == (v = find(v))) {
    return;
  }
  if (depth[u] > depth[v]) {
    swap(u, v);
  }
  fa[v] = u;
}
void rebuild() {
  for (int i = 1; i <= N; ++i) {
    sort(G[i].begin(), G[i].end());
    G[i].erase(unique(G[i].begin(), G[i].end()), G[i].end());
  }
  for (int i = 1; i <= N; ++i) {
    if (!dfn[i]) {
      tarjan(i, i);
    }
  }
  for (int i = 1; i <= N; ++i) {
    G[i].clear();
  }
  for (int i = 0; i < edges.size(); ++i) {
    if (!bridge[i] && !mark.count(edges[i])) {
      unite(edges[i].first, edges[i].second);
    }
    if (bridge[i] && !mark.count(edges[i])) {
      G[find(edges[i].first)].push_back(find(edges[i].second));
    }
  }
  for (int i = 1; i <= N; ++i) {
    sort(G[i].begin(), G[i].end());
    G[i].erase(unique(G[i].begin(), G[i].end()), G[i].end());
  }
}
void dfs(int u, int p, int d) {
  L[u] = ++tid;
  depth[u] = d;
  parent[0][u] = p;
  for (int i = 0; i < G[u].size(); ++i) {
    int v = G[u][i];
    if (v != p) {
      dfs(v, u, d + 1);
    }
  }
  R[u] = tid;
}
void lca_init() {
  dfs(find(1), 0, 0);
  for (int k = 0; k + 1 < mxlg; ++k) {
    for (int v = 1; v <= N; ++v) {
      parent[k + 1][v] = (parent[k][v] <= 0) ? 0 : parent[k][parent[k][v]];
    }
  }
}
int lca(int u, int v) {
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
  struct node {
    int l, r, sum, lazy;
  } a[maxn << 2];
  void push_down(int o) {
    if(a[o].lazy) {
      a[lson].lazy += a[o].lazy;
      a[rson].lazy += a[o].lazy;
      a[lson].sum += a[o].lazy * (a[lson].r - a[lson].l);
      a[rson].sum += a[o].lazy * (a[rson].r - a[rson].l);
      a[o].lazy = 0;
    }
  }
  void build(int l, int r, int o = 1) {
    a[o] = {l, r, 0, 0};
    if (l + 1 == r) {
      return;
    }
    int m = (l + r) / 2;
    build(l, m, lson);
    build(m, r, rson);
  }
  void update(int l, int r, int val, int o = 1) {
    if (l <= a[o].l && a[o].r <= r) {
      a[o].lazy += val;
      a[o].sum += val * (a[o].r - a[o].l);
      return;
    }
    push_down(o);
    int m = (a[o].l + a[o].r) / 2;
    if (l < m) update(l, r, val, lson);
    if (r > m) update(l, r, val, rson);
  }
  int query(int p, int o = 1) {
    if (a[o].l == p && a[o].l + 1 == a[o].r) {
      return a[o].sum;
    }
    push_down(o);
    int m = (a[o].l + a[o].r) / 2;
    if (p < m) {
      return query(p, lson);
    } else {
      return query(p, rson);
    }
  }
} seg;
int get_ans(int u, int v) {
  u = find(u);
  v = find(v);
  int t = find(lca(u, v));
  return seg.query(L[u]) + seg.query(L[v]) - 2 * seg.query(L[t]);
}
void destory(int u, int v) {
  u = find(u);
  v = find(v);
  int t = find(lca(u, v));
  while (find(u) != find(t)) {
    seg.update(L[find(u)], R[find(u)] + 1, -1);
    unite(find(u), parent[0][find(u)]);
  }
  while (find(v) != find(t)) {
    seg.update(L[find(v)], R[find(v)] + 1, -1);
    unite(find(v), parent[0][find(v)]);
  }
}
struct query {
  int opt, x, y;
} ;
vector<query> Qs;
void input() {
  scanf("%d%d", &N, &M);
  int u, v;
  for (int i = 0; i < M; ++i) {
    scanf("%d%d", &u, &v);
    add_edge(u, v);
  }
  int c, a, b;
  while (~scanf("%d", &c) && c != -1) {
    scanf("%d%d", &a, &b);
    Qs.push_back({c, a, b});
    if (!c) {
      mark[make_pair(a, b)] = 1;
      mark[make_pair(b, a)] = 1;
    }
  }
}
void work() {
  for (int i = 1; i <= N; ++i) {
    fa[i] = i;
  }
  rebuild();
  lca_init();
  seg.build(1, N + 1);
  for (int i = 1; i <= N; ++i) {
    if (find(i) == i) {
      seg.update(L[i], L[i] + 1, depth[i]);
    }
  }
  for (vector<query>::reverse_iterator it = Qs.rbegin(); it != Qs.rend(); it++) {
    int opt = it->opt;
    int x = find(it->x);
    int y = find(it->y);
    if (opt) {
      ans.push_back(get_ans(x, y));
    } else {
      destory(x, y);
    }
  }
  reverse(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); ++i) {
    printf("%d\n", ans[i]);
  }
}
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  input();
  work();
}
