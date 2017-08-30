/*
   教练我要打ACM!
   Life has never been fucking so easy...
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 20;

int w[maxn];
int dp[2][maxn];
/*
 dp[0][v] = cum ... gcd
 dp[1][v] = max(dp[0][fa], __gcd(dp[1][fa], w[v]))
*/

int N;
vector<int> G[maxn];
set<int> st[maxn];
void dfs(int u, int p, int g) {
  for (const int& v : G[u]) {
    if (v == p) continue;
    dp[0][v] = __gcd(w[v], g);
    dp[1][v] = g;
    st[v].insert(g);
    for (const int& x : st[u]) {
      int t = __gcd(x, w[v]);
      dp[1][v] = max(dp[1][v], t);
      st[v].insert(t);
    }
    dfs(v, u, dp[0][v]);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;
  for (int i = 1; i <= N; ++i) {
    cin >> w[i];
  }
  for (int i = 1; i < N; ++i) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  memset(dp, 0, sizeof(dp));
  dp[0][1] = w[1]; dp[1][1] = 0; st[1].insert(0);
  dfs(1, 0, w[1]);
  for (int i = 1; i <= N; ++i) {
    cout << max(dp[0][i], dp[1][i]) << " ";
  }
  return 0;
}
