#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 500000;
const int mxlg = 20 + 5;
vector<int> G[maxn];
int root;
int fa[mxlg][maxn];
int depth[maxn];

void dfs(int u, int p, int d) {
  fa[0][u] = p;
  depth[u] = d;
  for (int i = 0; i < G[u].size(); ++i) {
    if (G[u][i] != p) dfs(G[u][i], u, d + 1);
  }
}

void init(int V) {
  dfs(root, -1, 0);
  for (int k = 0; k + 1 < mxlg; ++k) {
    for (int v = 0; v < V; ++v) {
      if (fa[k][v] < 0) fa[k + 1][v] = -1;
      else fa[k + 1][v] = fa[k][fa[k][v]];
    }
  }
}

int lca(int u, int v) {
  if (depth[u] > depth[v]) swap(u, v);
  for (int k = 0; k < mxlg; k++) {
    if ((depth[v] - depth[u]) >> k & 1) {
      v = fa[k][v];
    }
  }
  if (v == u) return u;
  for (int k = mxlg - 1; k >= 0; k--) {
    if (fa[k][u] != fa[k][v]) {
      u = fa[k][u];
      v = fa[k][v];
    }
  }
  return fa[0][u];
}
