#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 20;
int n, m, k;
vector<int> g[maxn * 3];
pair<int, int> edge[maxn * maxn];
bool used[maxn * 3];
int match[maxn * 3];
void add_edge(int u, int v) {
  g[u].push_back(v);
  g[v].push_back(u);
}
void del_edge(int u, int v) {
  vector<int>::iterator it;
  for (it = g[u].begin(); it != g[u].end(); ++it) if (*it == v) break;
  g[u].erase(it);
  for (it = g[v].begin(); it != g[v].end(); ++it) if (*it == u) break;
  g[v].erase(it);
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
int Hungary() {
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
void init() {
  for (int i = 1; i < maxn * 3; ++i) {
    g[i].clear();
  }
}
int main() {
  int kase = 0;
  while (scanf("%d%d%d", &n, &m, &k) != EOF) {
    init();
    for (int i = 0; i < k; ++i) {
      static int u, v;
      scanf("%d%d", &u, &v);
      add_edge(u, v + 105);
      edge[i] = {u, v + 105};
    }
    int ans = Hungary();
    int cont = 0;
    for (int i = 0; i < k; ++i) {
      del_edge(edge[i].first, edge[i].second);
      int now = Hungary();
      if (now < ans) ++cont;
      add_edge(edge[i].first, edge[i].second);
    }
    printf("Board %d have %d important blanks for %d chessmen.\n", ++kase, cont, ans);
  }
  return 0;
}
