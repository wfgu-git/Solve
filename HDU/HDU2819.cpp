#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 20;
struct Max_Match
{
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
    for (int v = 1; v <= n; v++) if(g[u][v] && !vis[v]) {
      vis[v] = true;
      if (left[v] == -1 || dfs(left[v])) {
        left[v] = u;
        return true;
      }
    }
    return false;
  }

  int solve() {
    int ans=0;
    for (int i = 1; i <= n; i++) {
      memset(vis, 0, sizeof(vis));
      if (dfs(i)) ++ans;
    }
    return ans;
  }
} MM;
int a[maxn], b[maxn];
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    MM.init(n);
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        static int x;
        scanf("%d", &x);
        if (x) MM.g[i][j] = 1;
      }
    }
    if (MM.solve() != n) {
      printf("-1\n");
    } else {
      int tot = 0;
      for (int i = 1; i <= n; ++i) a[MM.left[i]] = i;
      memcpy(b, a, sizeof(a));
      for (int i = 1; i <= n; ++i) if (b[i] != i) {
        for (int j = 1; j <= n; ++j) if (b[j] == i) {
          ++tot;
          swap(b[i], b[j]);
        }
      }
      printf("%d\n", tot);
      for (int i = 1; i <= n; ++i) if (a[i] != i) {
        for (int j = 1; j <= n; ++j) if (a[j] == i) {
          printf("R %d %d\n", i, j);
          swap(a[i], a[j]);
        }
      }
    }
  }
  return 0;
}
