#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 50000 + 20;
const int logmaxn = 20 + 2;
vector < vector < int > > g;
int w[maxn];
int depth[maxn];
int fa[maxn][logmaxn];
int up[maxn][logmaxn], down[maxn][logmaxn];
int Max[maxn][logmaxn], Min[maxn][logmaxn];

void dfs(int u, int p, int d) {
  depth[u] = d;
  fa[u][0] = p;
  up[u][0] = max(0, w[p] - w[u]);
  down[u][0] = max(0, w[u] - w[p]);
  Max[u][0] = max(w[u], w[p]);
  Min[u][0] = min(w[u], w[p]);
  for (int i = 0; i < (int)g[u].size(); i++) {
    int v = g[u][i];
    if (v != p) {
      dfs(v, u, d + 1);
    }
  }
}
void init(const int &n) {
  memset(Max, 0, sizeof(Max));
  memset(Min, 0x3f, sizeof(Min));

  dfs(1, -1, 0);

  for (int k = 1; k < logmaxn; k++) {
    for (int u = 1; u <= n; u++) {
      if (fa[u][k - 1] < 0) {
        fa[u][k] = -1;
      } else {
        fa[u][k] = fa[fa[u][k - 1]][k - 1];
        int t = fa[u][k - 1];
        Max[u][k] = max(Max[t][k - 1], Max[u][k - 1]);
        Min[u][k] = min(Min[t][k - 1], Min[u][k - 1]);
        up[u][k] = max(max(up[t][k - 1], up[u][k - 1]),  Max[t][k - 1] - Min[u][k - 1]);
        down[u][k] = max(max(down[t][k - 1], down[u][k - 1]), Max[u][k - 1] - Min[t][k - 1]);
      }
    }
  }
}
int get_up(int u, int d, int &minw) {
  int ret = 0;
  minw = inf;
  int pre_min = inf;
  for (int k = logmaxn - 1; k >= 0; k--) {
    if (d >> k & 1) {
      minw = min(minw, Min[u][k]);
      ret = max(ret, up[u][k]);
      ret = max(ret, Max[u][k] - pre_min);
      pre_min = min(pre_min, Min[u][k]);
      u = fa[u][k];
    }
  }
  return ret;
}
int get_down(int u, int d, int &maxw) {
  int ret = 0;
  maxw = 0;
  int pre_max = 0;
  for (int k = logmaxn - 1; k >= 0; k--) {
    if (d >> k & 1) {
      maxw = max(maxw, Max[u][k]);
      ret = max(ret, down[u][k]);
      ret = max(ret, pre_max - Min[u][k]);
      pre_max = max(pre_max, Max[u][k]);
      u = fa[u][k];
    }
  }
  return ret;
}
int lca(int u, int v) {
  if (depth[u] > depth[v]) swap(u, v);

  for (int k = 0; k < logmaxn; k++) {
    if ((depth[v] - depth[u]) >> k & 1) {
      v = fa[v][k];
    }
  }

  if (u == v) return u;

  for (int k = logmaxn - 1; k >= 0; k--) {
    if (fa[u][k] != fa[v][k]) {
      u = fa[u][k];
      v = fa[v][k];
    }
  }
  return fa[u][0];
}
int main() {
  int n;
  while (scanf("%d", &n) == 1) {
    g.resize(n + 5);
    g.clear();
    for (int i = 1; i <= n; i++) {
      scanf("%d", &w[i]);
    }
    for (int i = 1; i < n; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      g[u].push_back(v);
      g[v].push_back(u);
    }
    init(n);
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      int t = lca(u, v);
      int maxw, minw;
      int _up = get_up(u, depth[u] - depth[t], minw);
      int _down = get_down(v, depth[v] - depth[t], maxw);
      int ans = max(maxw - minw, max(_up, _down));
      printf("%d\n", ans);
    }
  }
  return 0;
}
