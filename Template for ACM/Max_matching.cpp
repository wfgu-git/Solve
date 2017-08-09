// looks better
#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 500;
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

// 挑战
bool used[maxn];
int match[maxn];
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
