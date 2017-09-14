/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int inf = 0x3f3f3f3f;
const int maxn = 1000000 + 20;

int n, k;
vector<vector<pii> > G;
ll ans;
int dfs(int u, int p, ll w) {
  int son = 1;
  for (pii x : G[u]) {
    int v = x.first;
    ll d = (ll)x.second;
    if (v == p) {
      continue;
    }
    son += dfs(v, u, d);
  }
  ans += 1L * w * min(k, son);
  return son;
}
int main() {
  // freopen("/home/wfgu/Documents/solve/data.in", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(0);

  while (cin >> n >> k) {
    G.resize(n + 1);
    G.clear();
    for (int i = 1; i < n; ++i) {
      static int u, v, d;
      cin >> u >> v >> d;
      G[u].push_back({v, d});
      G[v].push_back({u, d});
    }
    ans = 0;
    dfs(1, 0, 0);
    cout << ans << endl;
  }
}
