#include <bits/stdc++.h>
using namespace std;
constexpr int maxm = 100;
constexpr int maxn = maxm * 2 + 20;
struct Max_Match {
  int n;
  bool g[maxn][maxn];
  bool vis[maxn];
  int left[maxn];

  void init(int n) {
    this->n = n;
    memset(g, 0, sizeof(g));
    memset(left, -1, sizeof(left));
   }

  bool dfs(int u) {
    for (int v = n + 1; v <= 2 * n; ++v) if(g[u][v] && !vis[v]) {
      vis[v] = true;
      if (left[v] == -1 || dfs(left[v])) {
        left[v] = u;
        return true;
      }
    }
    return false;
  }

  int solve() {
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      memset(vis,0,sizeof(vis));
      if (dfs(i)) ++ans;
    }
    return ans;
  }
} MM;
int n, m;
void work() {
  MM.init(m);
  int x, y;
  while (~scanf("%d%d", &x, &y)) {
    if (x == -1 && y == -1) {
      int ans = MM.solve();
      if (!ans) printf("No Solution\n");
      else printf("%d\n", ans);
    }
    else MM.g[x][y] = 1;
  }
}
int main() {
  while (scanf("%d%d", &m, &n) != EOF) {
    work();
  }
  return 0;
}
