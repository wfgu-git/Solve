#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 500 + 20;
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
int max_match(int n) {
  int ret = 0;
  memset(match, -1, sizeof(match));
  for (int i = 0; i < n; ++i) {
    if (match[i] < 0) {
      memset(used, 0, sizeof(used));
      if (dfs(i)) ++ret;
    }
  }
  return ret;
}
void init() {
  for (int i = 0; i < maxn; ++i) g[i].clear();
}
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    init();
    for (int i = 0; i < n; ++i) {
      static int u, k;
      scanf("%d: (%d)", &u, &k);
      for (int j = 0; j < k; ++j) {
        static int v;
        scanf("%d", &v);
        // add_edge(u, v + n);
        g[u].push_back(v);
      }
    }
    printf("%d\n", n - max_match(n));
  }
  return 0;
}
