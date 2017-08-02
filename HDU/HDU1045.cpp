#include <bits/stdc++.h>
using namespace std;
const int maxn = 10 * 10;
char grid[maxn][maxn];
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
  int n;
  while (scanf("%d", &n) != EOF && n) {
    init(n);
    for (int i = 0; i < n; ++i) {
      scanf("%s", grid[i]);
    }
    int totx, toty;
    totx = toty = 1;
    memset(row, -1, sizeof(row));
    memset(col, -1, sizeof(col));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == '.' && row[i][j] == -1) {
          for (int k = j; grid[i][k] == '.' && k < n; ++k) {
            row[i][k] = totx;
          }
          ++totx;
        }
        if (grid[j][i] == '.' && col[j][i] == -1) {
          for (int k = j; grid[k][i] == '.' && k < n; ++k) {
            col[k][i] = toty;
          }
          ++toty;
        }
      }
    }
    for(int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == '.') {
          add_edge(row[i][j], col[i][j] + (totx + toty));
          // g[row[i][j]].push_back(col[i][j]);
        }
      }
    }
    printf("%d\n", max_match(totx));
  }
  return 0;
}
