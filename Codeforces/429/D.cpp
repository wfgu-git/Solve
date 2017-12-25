/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const ll lnf = 0x3f3f3f3f3f3f3f3fLL;
const int maxn = 300000 + 20;

struct edge {
  int u, v, id;
} ;
vector<vector<pair<int, int>>> g;
vector<int> ans;
int d[maxn];
int vis[maxn];
int dfs(int x) {
  vis[x] = 1;
  for (pair<int, int>  pii : g[x]) {
    int v = pii.first;
    int eid = pii.second;
    if (vis[v]) {continue;}
    if (dfs(v)) {
      d[v] ^= 1;
      d[x] ^= 1;
      ans.push_back(eid);
    }
  }
  return d[x];
}
void work() {
  int n, m;
  cin >> n >> m;
  g.resize(n);

  int root = -1;
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> d[i];
    if (d[i] == -1) {
      root = i;
    } else {
      sum ^= d[i];
    }
  }
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u; --v;
    g[u].push_back(make_pair(v, i + 1));
    g[v].push_back(make_pair(u, i + 1));
  }

  if (sum && root == -1) {
    cout << -1;
    return;
  }

  if (sum) {
    d[root] = 1;
  } else {
    root = 0;
  }
  for (int i = 0; i < n; ++i) {
    if (d[i] < 0) {
      d[i] = 0;
    }
  }

  dfs(0);
  cout << ans.size() << "\n";
  for (int & x : ans) {
    cout << x << "\n";
  }
}
int main() {
  // freopen("data.in", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  work();
}
