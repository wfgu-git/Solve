/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 3e5 + 20;
const int mxlg = 20 + 2;

int n, Q;
vector<int> raw_tree[maxn];
vector<pair<int, int> > virtual_tree[maxn];
vector<int> key_nodes;
int S[maxn];
int dfn[maxn], dfs_clock;
int fa[mxlg][maxn];
int depth[maxn];
int v0;
int ans;
void dfs(int u, int p, int d) {
  fa[0][u] = p;
  depth[u] = d;
  dfn[u] = ++dfs_clock;
  for (int & v : raw_tree[u]) {
    if (v != p) {
      dfs(v, u, d + 1);
    }
  }
}
void lca_init() {
  dfs_clock = 0;
  dfs(1, -1, 0);
  for (int k = 0; k + 1 < mxlg; ++k) {
    for (int v = 1; v <= n; ++v) {
      if (fa[k][v] < 0) fa[k + 1][v] = -1;
      else fa[k + 1][v] = fa[k][fa[k][v]];
    }
  }
}
int lca(int u, int v) {
  if (depth[u] > depth[v]) swap(u, v);
  for (int k = 0; k < mxlg; ++k) {
    if ((depth[v] - depth[u]) >> k & 1) {
      v = fa[k][v];
    }
  }
  if (v == u) return u;
  for (int k = mxlg - 1; k >= 0; --k) {
    if (fa[k][v] != fa[k][u]) {
      u = fa[k][u];
      v = fa[k][v];
    }
  }
  return fa[0][u];
}
bool comp(const int & i, const int & j) {
  return dfn[i] < dfn[j];
}
void add_edge(int x, int y, int w) {
  virtual_tree[x].push_back({y, w});
}
void build(vector<int>& V, int k) {
  sort(V.begin(), V.begin() + k, comp);

  int top = 0;
  S[top++] = V[0];
  for (int i = 1; i < k; ++i) {
    int u = V[i];
    int p = lca(u, S[top - 1]);
    if (p != S[top - 1]){
      int x, y, w;
      while (top > 1 && depth[S[top - 2]] >= depth[p]) {
        x = S[top - 2];
        y = S[top - 1];
        w = abs(depth[x] - depth[y]);
        add_edge(x, y, w);
        add_edge(y, x, w);
        --top;
      }

      if (S[top - 1] != p) {
        x = p;
        y = S[top - 1];
        w = abs(depth[x] - depth[y]);
        add_edge(x, y, w);
        add_edge(y, x, w);
        S[top - 1] = p;
        V.push_back(p);
      }
    }
    S[top++] = u;
  }

  while (top > 1) {
    int x = S[top - 1];
    int y = S[top - 2];
    int w = abs(depth[x] - depth[y]);
    add_edge(x, y, w);
    add_edge(y, x, w);
    --top;
  }
}
void dfs1(int x, int p, int val) {
  if (val >= ans) {
    ans = val;
    v0 = x;
  }
  for (const pair<int, int>& pii : virtual_tree[x]) {
    int v = pii.first;
    int w = pii.second;
    if (v == p) continue;
    dfs1(v, x, val + w);
  }
}
void dfs2(int x, int p, int val) {
  ans = max(ans, val);
  for (const pair<int, int>& pii : virtual_tree[x]) {
    int v = pii.first;
    int w = pii.second;
    if (v == p) continue;
    dfs2(v, x, val + w);
  }
  virtual_tree[x].clear();
}
int main() {
#ifndef ONLINE_JUDGE
freopen("/home/wfgu/Documents/solve/data.in", "r", stdin);
freopen("/home/wfgu/Documents/solve/data.out", "w", stdout);
#endif

  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    raw_tree[u].push_back(v);
    raw_tree[v].push_back(u);
  }
  lca_init();
  scanf("%d", &Q);
  for (int i = 0; i < Q; ++i) {
    int m;
    scanf("%d", &m);
    for (int j = 0; j < m; ++j) {
      int x;
      scanf("%d", &x);
      key_nodes.push_back(x);
    }
    build(key_nodes, m);
    ans = 0;
    dfs1(key_nodes[0], -1, 0);
    dfs2(v0, -1, 0);
    printf("%d\n", (ans + 1) / 2);
    key_nodes.clear();
  }
}
