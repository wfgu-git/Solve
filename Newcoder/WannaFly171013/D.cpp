/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 20;

int n, m;
vector<int> G[maxn];
struct edge {int u, v;} ;
vector<edge> edges;
int ans[maxn][maxn];
int color[maxn];
int deg[maxn];
int tmp[maxn];
int ttmp[maxn];
int now[maxn];
int used[maxn];
int tar[maxn][maxn];
int k;
void add_edge(int u, int v) {
  G[u].push_back(v);
  G[v].push_back(u);
}
void tip(int u) {
  for (int v : G[u]) {
    if (color[v] == 1) {
      color[u] = 2;
      return;
    } else if (color[v] == 2) {
      color[u] = 1;
      return;
    }
  }
  color[u] = 1;
}
int cont(int *v) {
  int ret = 0;
  for (int i = 1; i <= k + 1; ++i) {
    if (v[i]) ret++;
  }
  return ret;
}
void unite(int* x, int* y) {
  for (int i = 1; i <= k + 1; ++i) ttmp[i] = 0;
  for (int i = 1; i <= k; ++i) {
    if (x[i] && y[i]) ttmp[i] = 1;
  }
}
int get_color(int* x) {
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
    if (!ans[u][v]) return 0;
  }
  return 1;
}
void solve(int u) {
  for (int i = 1; i <= k; ++i) now[i] = 1;
  now[k + 1] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 1; j <= k; ++j) {
      tar[i][j] = 1;
    }
    tar[i][k + 1] = 0;
  }
  for (int v : G[u]) {
    if (ans[u][v]) {
      now[ans[u][v]] = 0;
    }
    for (int x : G[v]) {
      if (ans[v][x]) {
        tar[v][ans[v][x]] = 0;
      }
    }
  }
  memset(used, 0, sizeof(used));
  while (!check(u)) {
    int t = -1;
    for (int i = 1; i <= k + 1; ++i) tmp[i] = 1;
    for (int v : G[u]) if (!ans[u][v] && !used[v]) {
      unite(now, tar[v]);
      if (cont(tmp) > cont(ttmp)) {
        memcpy(tmp, ttmp, sizeof(ttmp));
        t = v;
      }
    }
    int tc = get_color(tmp);
    ans[u][t] = ans[t][u] = tc;
    // cout << u << "-->" << t << " = " << tc << endl;
    used[t] = 1;
    now[tc] = 0;
  }
}
struct INFO {
  int id, d;
  bool operator < (const INFO & rhs) const {
    return d > rhs.d;
  }
} info[maxn];
int main() {
#ifndef ONLINE_JUDGE
  freopen("/home/wfgu/Documents/solve/data.in", "r", stdin);
  freopen("/home/wfgu/Documents/solve/data.out", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    static int u, v;
    cin >> u >> v;
    --u; --v;
    add_edge(u, v);
    edges.push_back({u, v});
    deg[u]++; deg[v]++;
  }
  k = -1;
  for (int i = 0; i < n; ++i) {
    if (!color[i]) {
      tip(i);
    }
    k = max(k, deg[i]);
    info[i] = {i, deg[i]};
  }
  sort(info, info + n);
  cout << k << '\n';
  // for (int i = 0; i < n; ++i) {
  //   cout << i + 1 << " -- > " << color[i] << endl;
  // }
  for (int i = 0; i < n; ++i) {
    solve(info[i].id);
  }
  for (edge & e : edges) {
    cout << ans[e.u][e.v] << '\n';
  }
}
