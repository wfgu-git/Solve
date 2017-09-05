/*
教练我要打ACM!
*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

int N, M;
int w[maxn];
int diff[maxn];
vector<int> G[maxn];
void add_edge(int from, int to) {
  G[from].push_back(to);
  G[to].push_back(from);
}
bool vis[maxn];
int dp[2][maxn];
void dfs(int u, int p) {
  vis[u] = true;
  int v;
  for (int i = 0; i < G[u].size(); ++i) {
    v = G[u][i];
    if (v == p) continue;
    dfs(v, u);
    dp[1][u] += dp[0][v];
    dp[0][u] += max(dp[0][v], dp[1][v]);
  }

}
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(0);

  while (cin >> N >> M && (N + M)) {
    for(int i = 0; i < N * N + 2; ++i) {
      G[i].clear();
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < N; ++i) {
      cin >> w[i];
      dp[1][i] = w[i];
    }
    for (int i = 0; i < M; ++i) {
      cin >> diff[i];
    }
    for (int i = 0; i < N; ++i) {
      for (int j = i + 1; j < N; ++j) {
        for (int k = 0; k < M; ++k) {
          if (abs(w[i] - w[j]) == diff[k]) {
            add_edge(i, j);
          }
        }
      }
    }

    memset(vis, 0, sizeof(vis));
    int ans = 0;
    for (int i = 0; i < N; ++i) {
      if (!vis[i]) {
        dfs(i, -1);
        ans += max(dp[0][i], dp[1][i]);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
