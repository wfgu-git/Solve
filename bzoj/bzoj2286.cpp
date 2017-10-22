/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define inf 0x3f3f3f3f3f3f3f3f
const int maxn = 250000 + 20;
const int mxlg = 20 + 5;

int n, m, k;
vector<pair<int, int> > raw_tree[maxn];
vector<int> virtual_tree[maxn];
vector<int> key_nodes;
ll dist[maxn];
ll dp[maxn];
int vis[maxn];
int key_node[maxn];
int used[maxn];
int fa[mxlg][maxn];
int depth[maxn];
int dfn[maxn];
int dfs_clock;
int S[maxn];
void dfs(int u, int p, int d) {
  fa[0][u] = p;
  depth[u] = d;
  dfn[u] = ++dfs_clock;
  for (int i = 0; i < raw_tree[u].size(); ++i) {
    pair<int, int> & pii = raw_tree[u][i];
    int v = pii.first;
    ll w = pii.second;
    if (v != p) {
      dist[v] = min(dist[u], w);
      dfs(v, u, d + 1);
    }
  }
}
void lca_init() {
  dist[1] = inf;
  dfs(1, -1, 0);

  for (int k = 0; k + 1 < mxlg; ++k) {
    for (int v = 1; v <= n; ++v) {
      if (fa[k][v] < 0) fa[k + 1][v] = -1;
      else fa[k + 1][v] = fa[k][fa[k][v]];
    }
  }
}
int get_lca(int u, int v) {
  if (depth[u] > depth[v]) swap(u, v);
  for (int k = 0; k < mxlg; ++k) {
    if ((depth[v] - depth[u]) >> k & 1) {
      v = fa[k][v];
    }
  }
  if (u == v) {
    return u;
  }
  for (int k = mxlg - 1; k >= 0; --k) {
    if (fa[k][v] != fa[k][u]) {
      v = fa[k][v];
      u = fa[k][u];
    }
  }
  return fa[0][u];
}
void add_virtual_edge(int x, int y) {
  virtual_tree[x].push_back(y);
  virtual_tree[y].push_back(x);
}
ll dfs1(int u, int p) {
  if (key_node[u]) {
    return dp[u] = dist[u];
  }
  ll sum = 0;
  for (int i = 0; i < virtual_tree[u].size(); ++i) {
    int v = virtual_tree[u][i];
    if (v != p) {
      dfs1(v, u);
      sum += dp[v];
    }
  }
  return dp[u] = min(dist[u], sum);
}
bool comp(int x, int y) {
  return dfn[x] < dfn[y];
}
void build(vector<int>& V) {
  sort(V.begin(), V.end(), comp);

  int top = 0, tot = 0;
  S[top++] = 1;
  for (int i = 0; i < k; ++i) {
    int v = V[i];
    int lca = get_lca(v, S[top - 1]);
    key_node[v] = 1;
    if (!vis[v]) used[tot++] = v;
    vis[v] = 1;
    if (!vis[lca]) {
      vis[lca] = 1;
      used[tot++] = lca;
    }
    if (lca != S[top - 1]) {
      int x, y;
      while (top >= 2 && depth[S[top -2]] >= depth[lca]) {
        x = S[top - 2];
        y = S[top - 1];
        add_virtual_edge(x, y);
        --top;
      }

      if (S[top - 1] != lca) {
        x = lca;
        y = S[--top];
        add_virtual_edge(x, y);
        S[top++] = lca;
      }
    }
    S[top++] = v;
  }
  while (top > 1) {
    add_virtual_edge(S[top - 1], S[top - 2]);
    --top;
  }


  dfs1(1, -1);

  printf("%lld\n", dp[1]);

  for (int i = 0; i < tot; ++i) {
    virtual_tree[used[i]].clear();
    key_node[used[i]] = 0;
    vis[used[i]] = 0;
  }
  key_nodes.clear();
}
void work() {
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int x, y, w;
    scanf("%d%d%d", &x, &y, &w);
    raw_tree[x].push_back({y, w});
    raw_tree[y].push_back({x, w});
  }

  lca_init();

  scanf("%d", &m);
  for (int q = 0; q < m; ++q) {
    scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
      int x;
      scanf("%d", &x);
      key_nodes.push_back(x);
    }
    build(key_nodes);

  }
}

int main() {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);

  work();
}
