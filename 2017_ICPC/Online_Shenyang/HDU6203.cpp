/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 10000 + 20;
const int mxlg = 20 + 2;

struct Node {
  int u, v, lca;
} ;
int n, q;
vector<int> G[maxn];
vector<Node> Q;
int fa[mxlg][maxn];
int depth[maxn];
bool vis[maxn];
void init() {
  memset(vis, 0, sizeof(vis));
  for (int i = 0; i <= n; ++i) {
    G[i].clear();
  }
  Q.clear();
}
void dfs(int u, int p, int d) {
  fa[0][u] = p;
  depth[u] = d;
  for (int v : G[u]) {
    if (v != p) {
      dfs(v, u, d + 1);
    }
  }
}
void LCA_init() {
  dfs(0, -1, 0);
  for (int k = 0; k + 1 < mxlg; ++k) {
    for (int v = 0; v <= n; ++v) {
      if (fa[k][v] < 0) {
        fa[k + 1][v] = -1;
      } else {
        fa[k + 1][v] = fa[k][fa[k][v]];
      }
    }
  }
}
int lca(int u, int v) {
  if (depth[u] > depth[v]) {
    swap(u, v);
  }
  for (int k = mxlg - 1; k >= 0; --k) {
    if ((depth[v] - depth[u]) >> k & 1) {
      v = fa[k][v];
    }
  }
  if (v == u) return u;
  for (int k = mxlg - 1; k >= 0; --k) {
    if (fa[k][v] != fa[k][u]) {
      v = fa[k][v];
      u = fa[k][u];
    }
  }
  return fa[0][u];
}
void del(int u) {
  vis[u] = 1;
  for (int v : G[u]) {
    if (v == fa[0][u] || vis[v]) {
      continue;
    }
    del(v);
  }
}
int main() {
  // freopen("/home/wfgu/Documents/solve/data.in", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(0);
  while (cin >> n) {
    init();
    int u, v;
    for (int i = 0; i < n; ++i) {
      cin >> u >> v;
      G[u].push_back(v);
      G[v].push_back(u);
    }
    LCA_init();
    cin >> q;
    for (int i = 0; i < q; ++i) {
      cin >> u >> v;
      Q.push_back({u, v, lca(u, v)});
    }
    sort(Q.begin(), Q.end(), [](Node a, Node b) {return depth[a.lca] > depth[b.lca];});
    int ans = 0;
    for (int i = 0; i < Q.size(); ++i) {
      int u = Q[i].u;
      int v = Q[i].v;
      int f = Q[i].lca;
      if (!vis[u] && !vis[v]) {
        ++ans;
        del(f);
      }
    }
    cout << ans << endl;
  }
}
