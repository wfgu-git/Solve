/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 20;

vector<int> G[maxn];
int n, m;
int deg[maxn];
int vis[maxn];
int color[maxn][maxn];
struct Edge {int u, v;} ;
vector<Edge> edges;
int pos, k = -1;
int tar[maxn][maxn];
int used[maxn];
int now[maxn];
int tmp[maxn];
int ttmp[maxn];
int cont(int *v) {
  int ret = 0;
  for (int i = 1; i <= k + 1; ++i) {
    if (v[i]) ret++;
  }
  return ret;
}
int* jiao(int* x, int* y) {
  for (int i = 1; i <= k + 1; ++i) ttmp[i] = 0;
  for (int i = 1; i <= k + 1; ++i) {
    if (x[i] && y[i]) {
      ttmp[i] = 1;
    }
  }
  return ttmp;
}
int getcolor(int* x) {
  int ret = 0;
  for (int i = 1; i <= k; ++i) {
    if (x[i]) {
      ret = i;
      break;
    }
  }
  return ret;
}
bool check(int u) {
  for (int v : G[u]) {
    if (!color[u][v]) return 0;
  }
  return 1;
}
void dfs(int u, int p) {
  now[k + 1] = 0;
  for (int i = 1; i <= k; ++i) now[i] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 1; j <= k; ++j) {
      tar[i][j] = 1;
    }
    tar[i][k + 1] = 0;
  }

  vis[u] = 1;
  for (int v : G[u]) {
    if (color[u][v]) {
      now[color[u][v]] = 0;
    }
    for (int x : G[v]) {
      if (color[v][x]) tar[v][color[v][x]] = 0;
    }
  }
  memset(used, 0, sizeof(used));
  while (!check(u)) {
    int pp = -1;
    for (int i = 1; i <= k + 1; ++i) tmp[i] = 1;
    for (int v : G[u]) if (!vis[v] && !used[v]) {
      if (cont(tmp) > cont(jiao(now, tar[v]))) {
        memcpy(tmp, ttmp, sizeof(ttmp));
        pp = v;
      }
    }
    int c = getcolor(tmp);
    color[u][pp] = color[pp][u] = c;
    used[pp] = 1;
    now[c] = 0;
  }
  for (int v :G[u]) if (!vis[v]) {
    dfs(v, u);
  }
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("/home/wfgu/Documents/solve/data.in", "r", stdin);
  freopen("/home/wfgu/Documents/solve/data.out", "w", stdout);
#endif
  // ios::sync_with_stdio(false);
  // cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u; --v;
    G[u].push_back(v);
    G[v].push_back(u);
    deg[u]++;
    deg[v]++;
    edges.push_back({u, v});
  }

  for (int i = 0; i < n; ++i) {
    if (k < deg[i]) {
      k = deg[i];
      pos = i;
    }
  }
  cout << k << '\n';
  dfs(pos, -1);
  for (int i = 0; i < n; ++i) {
    if (!vis[i]) dfs(i, -1);
  }
  for (Edge & e : edges) {
    cout << color[e.u][e.v] << '\n';
  }
}
