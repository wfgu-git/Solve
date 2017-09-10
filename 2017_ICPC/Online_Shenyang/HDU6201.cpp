/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

vector<pair<int, int> > G[maxn];
void add_edge(int from, int to, int dist) {
  G[from].push_back({to, dist});
  G[to].push_back({from, dist});
}
bool vis[maxn];
int c[maxn];
int w[maxn];
int ans;
void dfs1(int u) {
  vis[u] = 1;
  c[u] = w[u];
  for (const pair<int, int>& p : G[u]) {
    int v = p.first;
    int d = p.second;
    if (!vis[v]) {
      dfs1(v);
      c[u] = min(c[u], c[v] + d);
    }
  }
}
void dfs2(int u) {
  vis[u] = 1;
  for (const pair<int, int>& p : G[u]) {
    int v = p.first;
    int d = p.second;
    if (!vis[v]) {
      if (c[u] + d < c[v]) {
        c[v] = c[u] + d;
      }
      dfs2(v);
    }
  }
  ans = max(ans, w[u] - c[u]);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  for (int cas = 1; cas <= T; ++cas) {
    int n;
    cin >> n;
    for (int i = 1; i <=n; ++i) {
      G[i].clear();
      cin >> w[i];
    }
    int u, v, d;
    for (int i = 1; i < n; ++i) {
      cin >> u >> v >> d;
      add_edge(u, v, d);
    }

    ans = 0;
    memset(vis, 0, sizeof(vis));
    dfs1(1);
    memset(vis, 0, sizeof(vis));
    dfs2(1);
    cout << ans << endl;
  }
}
