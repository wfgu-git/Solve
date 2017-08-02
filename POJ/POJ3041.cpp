#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 1000 + 20;
int ans;
int k, n;
int match[maxn];
bool used[maxn];
vector<int> g[maxn];
void add_edge(int u, int v) {
  g[u].push_back(v);
  g[v].push_back(u);
}
void init(int n) {
  ans = 0;
  for (int i = 1; i <= n; ++i) g[i].clear();
}
bool dfs(int u) {
  used[u] = true;
  for (int i = 0; i < g[u].size(); ++i) {
    int v = g[u][i];
    int w = match[v];
    if (w < 0 || (!used[w] && dfs(w))) {
      match[u] = v;
      match[v] = u;
      return true;
    }
  }
  return false;
}
void solve() {
  ans = 0;
  memset(match, -1, sizeof(match));
  for (int i = 1; i <= n; i++) {
    if (match[i] < 0) {
      memset(used, 0, sizeof(used));
      if (dfs(i))
        ++ans;
    }
  }
}
int main() {
  while (~scanf("%d%d", &n, &k)) {
    init(n);
    for (int i = 0; i < k; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      add_edge(u, v + n);
    }
    solve();
    printf("%d\n", ans);
  }
  return 0;
}
