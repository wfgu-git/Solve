/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 200;

vector<int> G[maxn];
int n, m;
int deg[maxn];
int vis[maxn];
int color[maxn][maxn];
struct Edge {int u, v;} ;
vector<Edge> edges;
int pos, k = -1;
int tar[maxn];
int used[maxn];
bool check(int u) {
  for (int v : G[u]) {
    if (!color[u][v]) return 0;
  }
  return 1;
}
struct INFO {
  int id, d;
  bool operator < (const INFO & rhs) const {
    return d > rhs.d;
  }
} info[maxn];
void dfs(int u, int p) {
  int now;
  now = (1 << k) - 1;
  for (int i = 0; i < n; ++i) {
    tar[i] =  now;
  }
  vis[u] = 1;
  // int c = 1;
  for (int v : G[u]) {
    if (color[u][v]) now ^= (1 << (color[u][v] - 1));
    for (int x : G[v]) {
      if (color[v][x]) tar[v] ^= (1 << (color[v][x] - 1));
    }
  }
  // if (u == 3) cout << "now = " << now << endl;
  memset(used, 0, sizeof(used));
  while (!check(u)) {
    int pp = -1;
    int tmp = (1 << (k + 2)) - 1;
    for (int v : G[u]) if (!vis[v] && !used[v]) {
      if (__builtin_popcount(tmp) > __builtin_popcount(now & tar[v])) {
        tmp = (now & tar[v]);
        pp = v;
      }
    }
    int c = 0, cc = tmp & (-tmp);
    while (cc) {
      c++; cc >>= 1;
    }
    color[u][pp] = color[pp][u] = c;
    // cout << u << "-->" << pp << " color is " << color[u][pp] << endl;
    // tar[pp] ^= (1 << (c - 1));
    used[pp] = 1;
    now ^= (1 << (c - 1));
  }
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("/home/wfgu/Documents/solve/data.in", "r", stdin);
  freopen("/home/wfgu/Documents/solve/data.out", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);

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
    info[i] = {i, deg[i]};
    if (k < deg[i]) {
      k = deg[i];
      pos = i;
    }
  }
  cout << k << '\n';
  sort(info, info + n);
  for (int i = 0; i < n; ++i) {
    dfs(info[i].id, -1);
  }
  for (Edge & e : edges) {
    cout << color[e.u][e.v] << '\n';
  }
}
