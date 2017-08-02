#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 500 + 20;
int match[maxn];
bool used[maxn];
int city[maxn][maxn];
char grid[maxn][maxn];
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
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
int max_match(int V) {
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
void init() {
  memset(city, 0, sizeof(city));
  for (int i = 0; i < maxn; ++i) {
    g[i].clear();
  }
}
int n, m;
inline bool inside(int x, int y) {
  return !(x < 0 || x >= n || y < 0 || y >= m);
}
int main() {
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    init();
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
      scanf("%s", grid[i]);
    }
    int tot = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] == '*') {
          city[i][j] = ++tot;
        }
      }
    }
    for (int x = 0; x < n; ++x) {
      for (int y = 0; y < m; ++y) {
        if (city[x][y]) {
          for (int d = 0; d < 4; ++d) {
            int tx = x + dx[d];
            int ty = y + dy[d];
            if (inside(tx, ty) && city[tx][ty]) {
              g[city[x][y]].push_back(city[tx][ty]);
              g[city[tx][ty]].push_back(city[x][y]);
            }
          }
        }
      }
    }
    printf("%d\n", tot - max_match(tot));
  }
  return 0;
}
