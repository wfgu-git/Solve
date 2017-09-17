/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 300000 + 20;
const int mxlg = 25 + 2;

int n, k;
int a[maxn];
vector<int> G[maxn];
int depth[maxn], fa[mxlg][maxn];
int dlca[maxn];
vector< vector< int > > dp;
void dfs(int u, int p, int d) {
  depth[u] = d;
  fa[0][u] = p;
  for (int v : G[u]) {
    if (v != p) {
      dfs(v, u, d + 1);
    }
  }
}
int lca(int u, int v) {
  if (depth[u] > depth[v]) {
    swap(u, v);
  }

  for (int k = 0; k < mxlg; k++) {
    if ((depth[v] - depth[u]) >> k & 1) {
      v = fa[k][v];
    }
  }

  if (v == u) {
    return u;
  }

  for (int k = mxlg - 1; k >= 0; --k) {
    if (depth[u] != depth[v]) {
      u = fa[k][u];
      v = fa[k][v];
    }
  }
  return fa[0][u];
}
void init() {
  dfs(1, -1, 1);
  for (int k = 0; k + 1 < mxlg; ++k) {
    for (int v = 1; v <= n; ++v) {
      if (fa[k][v] < 0) {
        fa[k + 1][v] = -1;
      } else {
        fa[k + 1][v] = fa[k][fa[k][v]];
      }
    }
  }
}
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(0);

  while (cin >> n >> k) {
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
      G[i].clear();
    }
    int u, v;
    for (int i = 1; i < n; ++i) {
      cin >> u >> v;
      G[u].push_back(v);
      G[v].push_back(u);
    }
    init();
    for (int i = 2; i <= n; ++i) {
      dlca[i] = depth[lca(a[i], a[i - 1])];
      cout << dlca[i] << endl;
    }
    dp.assign(n + 1, vector<int>(k + 1, 0));
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j <= min(i, k); ++j) {
        int tmp = inf;
        if (j > 0) {
          tmp = min(tmp, dp[i - 1][j - 1] + depth[a[i]]);
        }
        if (i >= 2 && j >= 1 && j - 1 <= i - 2) {
          tmp = min(tmp, dp[i - 2][j - 1] + dlca[i]);
        }
        if (j <= i - 1) {
          tmp = min(tmp, dp[i - 1][j]);
        }
        dp[i][j] = tmp;
      }
    }
    cout << dp[n][k] << endl;
  }
  return 0;
}
