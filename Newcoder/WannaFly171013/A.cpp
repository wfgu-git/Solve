/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

vector<int> G[maxn];
ll tot1, tot0;
void dfs(int u, int p, int c) {
  if (c) {
    tot1++;
  } else {
    tot0++;
  }
  for (int v : G[u]) {
    if (v == p) continue;
    dfs(v, u, c ^ 1);
  }
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("/home/wfgu/Documents/solve/data.in", "r", stdin);
  freopen("/home/wfgu/Documents/solve/data.out", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  tot1 = tot0 = 0;
  dfs(1, -1, 0);
  ll ans =  tot1 * (tot1 - 1) / 2LL;
  ans +=  tot0 * (tot0 - 1) / 2LL;
  cout << ans << endl;
}
