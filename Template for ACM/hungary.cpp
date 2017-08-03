#include <bits/stdc++.h>
using namespace std;
const int maxn = 500;
vector<int> g[maxn];
void add_edge(int u, int v) {
  g[u].push_back(v);
  g[v].push_back(u);
}
bool dfs(int u) {
  used[u] = true;
  for (vector<int>::iterator it = g[u].begin(); it != g[u].end(); ++it) {
    int v = *it;
    int w = match[v];
    if (w < 0 || (!used[w] && dfs(w))) {
      match[u] = v;
      match[v] = u;
      return true;
    }
  }
  return false;
}
int Hungary(int V) {
  int ret = 0;
  memset(match, -1, sizeof(match));
  for (int i = 1; i <= V; ++i) {
    if (match[i] < 0) {
      memset(used, 0, sizeof(used));
      if (dfs(i)) ++ret;
    }
  }
  return ret;
}
