#include <string.h>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
const int maxn = 30000 + 10;
const int maxm = 100000 + 10;
const int maxq = maxm + 40000 + 10;

struct Edge {
  int u, v;
  Edge() {}
  Edge(int u, int v) : u(u), v(v) {}
  bool operator<(const Edge& e) const {
    if (u == e.u) return v < e.v;
    return u < e.u;
  }
  bool operator==(const Edge& e) const { return e.u == u && e.v == v; }
} edges[maxm];

struct Oper {
  int c, a, b;
  int ans;
  Oper() {}
  Oper(int c, int a, int b) : c(c), a(a), b(b) {}
} oper[maxq];

struct SegmentTree {
  int sum[maxn << 2];
  int col[maxn << 2];
  void PushUp(int rt) { sum[rt] = sum[rt << 1] + sum[rt << 1 | 1]; }
  void PushDown(int rt, int l, int r) {
    if (col[rt]) {
      col[rt << 1 | 1] += col[rt];
      col[rt << 1] += col[rt];
      int m = (l + r) >> 1;
      sum[rt << 1] += col[rt] * (m - l + 1);
      sum[rt << 1 | 1] += col[rt] * (r - m);
      col[rt] = 0;
    }
  }
  void Update(int L, int R, int x, int l, int r, int rt) {
    if (L <= l && r <= R) {
      sum[rt] += x * (r - l + 1);
      col[rt] += x;
      return;
    }
    PushDown(rt, l, r);
    int m = (l + r) >> 1;
    if (L <= m) Update(L, R, x, lson);
    if (R > m) Update(L, R, x, rson);
    PushUp(rt);
  }
  int Query(int p, int l, int r, int rt) {
    if (l == r) return sum[rt];
    int m = (l + r) >> 1;
    PushDown(rt, l, r);
    if (p <= m)
      return Query(p, lson);
    else
      return Query(p, rson);
  }
  void init() {
    memset(sum, 0, sizeof(sum));
    memset(col, 0, sizeof(col));
  }
} seg_tree;

int N, M, Q;
int dfn, pre[maxn], post[maxn];
bool vis[maxm], del[maxm];
int rmq[2 * maxm], tot;
int dfn_to_node[maxn];
int rmq_pos[maxn];
int anc[2 * maxm][19];
int dep[maxn];
vector<int> G[maxn];
int fa[maxn], p[maxn];

int find(int x) {
  if (x == p[x]) return x;
  return p[x] = find(p[x]);
}
void make_rmq() {
  for (int i = 0; i < tot; ++i) anc[i][0] = rmq[i];
  for (int j = 1; (1 << j) <= tot; ++j)
    for (int i = 0; i + (1 << j) - 1 < tot; ++i)
      anc[i][j] = min(anc[i][j - 1], anc[i + (1 << (j - 1))][j - 1]);
}

stack<int> S;
void dfs() {
  while (S.size()) S.pop();
  S.push(1);
  memset(pre, 0, sizeof(pre));
  dep[1] = 0;
  memset(fa, -1, sizeof(fa));
  fa[1] = 1;
  dfn = tot = 0;
  memset(vis, 0, sizeof(vis));
  while (S.size()) {
    int u = S.top();
    if (pre[u]) {
      post[u] = dfn;
      if (fa[u] > 0) rmq[tot++] = pre[fa[u]];
      S.pop();
      continue;
    }
    pre[u] = ++dfn;
    rmq_pos[u] = tot;
    rmq[tot++] = dfn;
    dfn_to_node[dfn] = u;
    for (int i = 0; i < G[u].size(); ++i) {
      int x = G[u][i];
      if (vis[x] || del[x]) continue;
      vis[x] = true;
      Edge& e = edges[x];
      int v = e.u == u ? e.v : e.u;
      if (fa[v] != -1) {
        oper[Q].c = 0;
        oper[Q].a = min(u, v);
        oper[Q].b = max(u, v);
        ++Q;
      } else {
        fa[v] = u;
        dep[v] = dep[u] + 1;
        S.push(v);
      }
    }
  }
  seg_tree.init();
  for (int i = 1; i <= N; ++i) seg_tree.Update(pre[i], pre[i], dep[i], 1, N, 1);
}

void input() {
  for (int i = 0; i < M; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    if (u > v) swap(u, v);
    edges[i] = Edge(u, v);
  }
  sort(edges, edges + M);
  memset(del, 0, sizeof(del));
  Q = 0;
  int c, a, b;
  while (scanf("%d", &c) == 1) {
    if (c == -1) break;
    scanf("%d%d", &a, &b);
    if (a > b) swap(a, b);
    oper[Q++] = Oper(c, a, b);
    if (c == 0) {
      int z = lower_bound(edges, edges + M, Edge(a, b)) - edges;
      del[z] = true;
    }
  }
}

void buildtree() {
  for (int i = 1; i <= N; ++i) {
    G[i].clear();
    p[i] = i;
  }
  for (int i = 0; i < M; ++i)
    if (!del[i]) {
      int u = edges[i].u, v = edges[i].v;
      G[u].push_back(i);
      G[v].push_back(i);
    }
  dfs();
  make_rmq();
}

int LCA(int u, int v) {
  u = find(u), v = find(v);
  u = rmq_pos[u], v = rmq_pos[v];
  if (u > v) swap(u, v);
  int k = 0;
  while ((1 << (k + 1)) <= v - u + 1) ++k;
  return dfn_to_node[min(anc[u][k], anc[v - (1 << k) + 1][k])];
}

void Destroy(int u, int rt) {
  while (u != rt) {
    seg_tree.Update(pre[u], post[u], -1, 1, N, 1);
    p[u] = rt;
    u = find(fa[u]);
  }
}

void Update(int u, int v) {
  u = find(u), v = find(v);
  int lca = find(LCA(u, v));
  Destroy(u, lca);
  Destroy(v, lca);
}

int Query(int u, int v) {
  u = find(u), v = find(v);
  int lca = find(LCA(u, v));
  int deepu = seg_tree.Query(pre[u], 1, N, 1);
  int deepv = seg_tree.Query(pre[v], 1, N, 1);
  int deeplca = seg_tree.Query(pre[lca], 1, N, 1);
  return deepu + deepv - 2 * deeplca;
}

void solve() {
  for (int i = Q - 1; i >= 0; --i)
    if (oper[i].c == 0)
      Update(oper[i].a, oper[i].b);
    else
      oper[i].ans = Query(oper[i].a, oper[i].b);
  for (int i = 0; i < Q; ++i)
    if (oper[i].c == 1) printf("%d\n", oper[i].ans);
}

int main() {
  //  freopen("intpu.in", "r", stdin);
  while (scanf("%d%d", &N, &M) == 2) {
    input();
    buildtree();
    solve();
  }
}
