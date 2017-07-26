#include <cstdio>
#include <cstring>
using namespace std;
const int maxv = 1000 + 5;
int g[maxv][maxv];
int match[maxv];
bool used[maxv];
int k, m, n;
int ans;
bool dfs(int v) {
  for (int i = 1; i <= n; i++) {
    if (g[v][i] && !used[i]) {
      used[i] = true;
      if (match[i] < 0 || dfs(match[i])) {
        match[i] = v;
        return true;
      }
    }
  }
  return false;
}
int solve() {
  int res = 0;
  memset(match, -1, sizeof(match));
  for (int v = 1; v <= m; v++) {
    if (match[v] < 0) {
      memset(used, 0, sizeof(used));
      if (dfs(v)) {
        res++;
      }
    }
  }
  return res;
}
void init() {
  ans = 0;
  memset(g, 0, sizeof(g));
}
int main() {
  while (~scanf("%d", &k) && k) {
    scanf("%d%d", &m, &n);
    init();
    for (int i = 0; i < k; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      g[u][v] = 1;
    }
    ans = solve();
    printf("%d\n", ans);
  }
}
