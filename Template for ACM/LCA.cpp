#include <vector>
#include <algorithm>
using namespace std;
vector<int> G[maxn];
int root;
int fa[maxn][logmaxn];
int depth[maxn];

void dfs(int u, int p, int d) {
  fa[u][0] = p;
  depth[u] = d;
  for (int i = 0; i < G[u].size(); ++i) {
    if (G[u][i] != p) dfs(G[u][i], u, d + 1);
  }
}

void init(int V) {
  dfs(root, -1, 0);
  for (int k = 0; k + 1 < logmaxn; ++k) {
    for (int v = 0; v < V; ++v) {
      if (fa[v][k] < 0) fa[v][k + 1] = -1;
      else fa[v][k + 1] = fa[fa[v][k]][k];
    }
  }
}

int lca(int u, int v) {
  if (depth[u] > depth[v]) swap(u, v);
  for (int k = 0; k < logmaxn; k++) {
    if ((depth[v] - depth[u]) >> k & 1) {
      v = fa[v][k];
    }
  }
  if (v == u) return u;
  for (int k = logmaxn - 1; k >= 0; k--) {
    if (fa[u][k] != fa[v][k]) {
      u = fa[u][k];
      v = fa[v][k];
    }
  }
  return fa[u][0];
}
