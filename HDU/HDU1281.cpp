#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 20;
bool used[maxn];
int match[maxn];
vector<int> g[maxn];
void add_edge(int u, int v) {
  g[u].push_back(v);
  g[v].push_back(u);
}
bool dfs(int u) {
  used[u] = true;
  for (int v : g[u]) {
    int w = match[v];
    if (w < 0 || (!used[w] && dfs(w))) {
      match[u] = v;
      match[v] = u;
      return true;
    }
  }
  return false;
}
int max_match(int n) {
  int ret = 0;
  memset(match, -1, sizeof(match));
  for (int i = 1; i <= n; ++i) {
    if (match[i] < 0) {
      memset(used, 0, sizeof(used));
      if (dfs(i)) ++ret;
    }
  }
  return ret;
}
void init(int n) {
  for (int i = 1; i <= maxn; ++i) {
    g[i].clear();
  }
}
int row[maxn][maxn], col[maxn][maxn];
int main() {
  
}
