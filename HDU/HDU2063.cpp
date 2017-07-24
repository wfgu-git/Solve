#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 20;
int ans;
int k, m, n;
int g[maxn][maxn];
int match[maxn];
bool used[maxn];
void init() {
  ans = 0;
  memset(g, 0, sizeof(g));
}
bool dfs(int v) {
  for (int i = 1; i <= n; i++) if (g[v][i] && !used[i]) {
    used[i] = 1;
    if (match[i] < 0 || dfs(match[i])) {
      match[i] = v;
      return true;
    }
  }
  return false;
}
void solve() {
  memset(match, -1, sizeof(match));
  for (int i = 1; i <= m; i++) {
    memset(used, 0, sizeof(used));
    if (dfs(i))
      ++ans;
  }
}
int main() {
  while (~scanf("%d", &k) && k) {
    init();
    scanf("%d%d", &m, &n);
    for (int i = 0; i < k; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      g[u][v] = 1;
    }
    solve();
    printf("%d\n", ans);
  }
  return 0;
}
