/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;

const int inf = 0x3f3f3f3f;
const int maxn = 300000 + 20;

vector<int> G[maxn];
vector<pii> Qs[maxn];
vector< vector< int > > dp;
int a[maxn];
int depth[maxn], fa[maxn], lca[maxn];
bool vis[maxn];
int fnd(int x) {
  return x == fa[x] ? x : fa[x] = fnd(fa[x]);
}
void tarjan(int u, int p, int d) {
  vis[u] = 1;
  fa[u] = u;
  depth[u] = d;
  for (int v : G[u]) {
    if (v != p) {
      tarjan(v, u, d + 1);
      fa[v] = u;
    }
  }
  for (pii q : Qs[u]) {
    int v = q.first;
    int now = q.second;
    if (vis[v]) {
      lca[now] = fnd(v);
    }
  }
}
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, k;
  for ( ; ~scanf("%d%d", &n, &k); ) {
    for (int i = 1; i <= n; ++i) {
      G[i].clear();
      Qs[i].clear();
      fa[i] = i;
    }
    for (int i = 1;  i<= n; ++i) {
      scanf("%d", a + i);
    }
    for (int i = 2; i <= n; ++i) {
      Qs[a[i - 1]].push_back({a[i], i});
      Qs[a[i]].push_back({a[i - 1], i});
    }
    for (int i = 1; i < n; ++i) {
      static int u, v;
      scanf("%d%d", &u, &v);
      G[u].push_back(v);
      G[v].push_back(u);
    }
    memset(vis, 0, sizeof(vis));
    tarjan(1, 1, 1);
    for (int i = 2; i <= n; ++i) {
      lca[i] = depth[lca[i]];
    }
    dp.assign(n + 1, vector<int>(k + 1, 0));
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j <= min(i, k); ++j) {
        int tmp = inf;
        if (j > 0) {
          tmp = min(tmp, dp[i - 1][j - 1] + depth[a[i]]);
        }
        if (i >= 2 && j >= 1 && j - 1 <= i - 2) {
          tmp = min(tmp, dp[i - 2][j - 1] + lca[i]);
        }
        if (j <= i - 1) {
          tmp = min(tmp, dp[i - 1][j]);
        }
        dp[i][j] = tmp;
      }
    }
    printf("%d\n", dp[n][k]);
  }
  return 0;
}
