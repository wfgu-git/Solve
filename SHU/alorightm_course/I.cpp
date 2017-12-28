/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100 + 20;

int n;
int ans;
int vis[maxn];
int g[maxn][maxn];
int cont[maxn];
bool dfs(int u, int tot) {
  for (int i = u + 1; i <= n; ++i) {
    if (cont[i] + tot <= ans) return 0;
    if (g[u][i]) {
      int j;
      for (j = 0; j < tot; ++j) {
        if (!g[i][vis[j]]) break;
      }
      if (j == tot) {
        vis[tot] = i;
        if (dfs(i, tot + 1)) return 1;
      }
    }
  }

  if (tot > ans) {
    ans = tot;
    return 1;
  }

  return 0;
}
void solve() {
  ans = -1;
  for (int i = n; i; --i) {
    vis[0] = i;
    dfs(i, 1);
    cont[i] = ans;
  }
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("/home/wfgu/solve/data.in", "r", stdin);
  freopen("/home/wfgu/solve/data.out", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);

  /*
  1、最大团点的数量=补图中最大独立集点的数量

  2、二分图中，最大独立集点的数量+最小覆盖点的数量=整个图点的数量

  3、二分图中，最小覆盖点的数量=最大匹配的数量

  4、图的染色问题中，最少需要的颜色的数量=最大团点的数量
  */
  int kase = 0;
  while (cin >> n) {
    string line;
    for (int i = 1; i <= n; ++i) {
      cin >> line;
      for (int j = 1; j <= n; ++j) {
        g[i][j] = g[j][i] = line[j - 1] - '0';
      }
    }
    solve();
    cout << "Case " << ++kase << ": " << ans << '\n';
  }
  cout.flush();
}
