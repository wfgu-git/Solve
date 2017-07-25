#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000 + 20;
const int logmaxn = 25 + 5;
int dep[maxn];
int fa[maxn][logmaxn];
int dis[maxn];
bool vis[maxn];
vector<int> g[maxn];
void dfs(int u, int p)
{
    fa[u][0] = p;
    dep[u] = dep[p] + 1;
    dis[u] = dis[p] + 1;
    for (int v : g[u]) {
      if (v == p) continue;
      dfs(v, u);
    }
}
void init(const int &n)
{
  memset(dis, 0, sizeof(dis));
  memset(vis, 0, sizeof(vis));
  dis[1] = 0;
  dep[1] = 0;
  dfs(1, 0);
  for (int k = 0; k + 1 < logmaxn; k++) {
      for (int v = 1; v <= n; v++) {
          if (fa[v][k] == 0)  fa[v][k + 1] = 0;
          else fa[v][k + 1] = fa[fa[v][k]][k];
      }
  }
}
int lca(int u, int v)
{
  if (dep[u] > dep[v]) swap(u, v);
  for (int k = 0; k < logmaxn; k++) {
      if ((dep[v] - dep[u]) >> k & 1) {
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
int solve(int a, int b, int t) {
  int f1 = lca(a, t);
  int f2 = lca(b, t);
  if (dep[f1] < dep[f2]) swap(f1, f2);
  int ans = dis[f1] + dis[t] - 2 * dis[lca(f1, t)];
  int f3 = lca(a, b);
  if (dep[f3] > dep[f1]) {
    ans += dis[f3] + dis[f1] - 2 * dis[lca(f3, f1)];
  }
  return ans;
}
int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  for (int v = 2; v <= n; ++v) {
    int u;
    scanf("%d", &u);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  init(n);
  int a, b, c;
  for (int i = 0; i < q; i++) {
    scanf("%d%d%d", &a, &b, &c);
    int ans = -1;
    ans = max(ans, solve(a, b, c));
    ans = max(ans, solve(a, c, b));
    ans = max(ans, solve(b, c, a));
    printf("%d\n", ans + 1);
  }
}
