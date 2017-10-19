/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int maxn = 300000 + 20;
const int mxlg = 20 + 3;

int N, Q;
vector<int> raw_tree[maxn];
vector<pair<int, int> > virtual_tree[maxn];
int ans;
int v0;
int depth[maxn];
int fa[mxlg][maxn];
int dfn[maxn];
int dfs_clock;
int S[maxn];
int top;
void add_edge(int x, int y, int w) {
  virtual_tree[x].push_back({y, w});
  // printf("add (%d, %d), value = %d\n", x, y, w);
}
void dfs(int u, int p, int d) {
  fa[0][u] = p;
  depth[u] = d;
  dfn[u] = ++dfs_clock;
  for (int& v : raw_tree[u]) {
    if (v == p) continue;
    dfs(v, u, d + 1);
  }
}
void lca_init() {
  dfs_clock = 0;
  dfs(1, -1, 0);
  for (int k = 0; k + 1 < mxlg; ++k) {
    for (int v = 1; v <= N; ++v) {
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

  if (v == u) return u;

  for (int k = mxlg - 1; k >= 0; --k) {
    if (fa[k][v] != fa[k][u]) {
      v = fa[k][v];
      u = fa[k][u];
    }
  }
  return fa[0][u];
}
void dfs1(int x, int p, int L) {
  if (L > ans) {
    ans = L;
    v0 = x;
  }
  for (auto & pii : virtual_tree[x]) {
    int v = pii.first;
    int w = pii.second;
    if (v == p) continue;
    dfs1(v, x, L + w);
  } }
void dfs2(int x, int p, int L) {
  ans = max(ans, L);
  for (auto & pii : virtual_tree[x]) {
    int v = pii.first;
    int w = pii.second;
    if (v == p) continue;
    dfs2(v, x, L + w);
  }
  virtual_tree[x].clear();
}
bool comp(int x, int y) {
  return dfn[x] < dfn[y];
}
void build(vector<int>& V, int k) {
  sort(V.begin(), V.end(), comp);

  top = 0;
  S[top++] = 1;
  for (int i = (V[0] == 1); i < k; ++i) {
    int v = V[i];
    int lca = get_lca(v, S[top - 1]);
    if (lca != S[top - 1]) {
      while (top > 1 && depth[S[top - 2]] >= depth[lca]) {
        add_edge(S[top - 2], S[top - 1], depth[S[top - 1]] - depth[S[top - 2]]);
        add_edge(S[top - 1], S[top - 2], depth[S[top - 1]] - depth[S[top - 2]]);
        --top;
      }

      if (S[top - 1] != lca) {
        add_edge(S[top - 1], lca, depth[lca] - depth[S[top - 1]]);
        add_edge(lca, S[top - 1], depth[lca] - depth[S[top - 1]]);
        S[top - 1] = lca;
        // V.push_back(lca);
      }
    }
    S[top++] = v;
  }

  while (top > 1) {
    add_edge(S[top - 2], S[top - 1], depth[S[top - 1]] - depth[S[top - 2]]);
    add_edge(S[top - 1], S[top - 2], depth[S[top - 1]] - depth[S[top - 2]]);
    --top;
  }

  ans = 0, v0 = -1;
  dfs1(V[0], -1, 0);
  dfs2(v0, -1, 0);
  printf("%d\n", (ans + 1) / 2);
}
int main() {
#ifndef ONLINE_JUDGE
freopen("/home/wfgu/Documents/solve/data.in", "r", stdin);
freopen("/home/wfgu/Documents/solve/data.out", "w", stdout);
#endif

  scanf("%d", &N);
  for (int i = 1; i < N; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    raw_tree[x].push_back(y);
    raw_tree[y].push_back(x);
  }
  lca_init();
  scanf("%d", &Q);
  for (int i = 0; i < Q; ++i) {
    int m;
    scanf("%d", &m);
    vector<int> key_nodes(m);
    for (int j = 0; j < m; ++j) {
      scanf("%d", &key_nodes[j]);
    }
    build(key_nodes, m);
  }
}
