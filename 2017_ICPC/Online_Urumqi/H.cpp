/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

vector<pii> G[maxn];
int f[maxn];
int ans;
int dfs(int u) {
  if (f[u] != -1) return f[u];
  int Max = 0;
  for (const pii& x : G[u]) {
    int v = x.first;
    int d = x.second;
    Max = max(Max, dfs(v) + d);
  }
  return f[u] = Max;
}
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  for (int cas = 1; cas <= T; ++cas) {
    int N, M;
    int from, to, dist;
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) G[i].clear();
    for (int i = 0; i < M; ++i) {
      cin >> from >> to >> dist;
      G[from].push_back({to, dist});
    }
    int ans = 0;
    memset(f, -1, sizeof(f));
    for (int i = 1; i <= N; ++i) {
      ans = max(ans, dfs(i));
    }
    cout << ans << endl;
  }
  return 0;
}
