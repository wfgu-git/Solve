#include <bits/stdc++.h>
using namespace std;
const int maxn = 50000;
vector<int> G[maxn];
int N, K;
int fa[maxn];
int sz[maxn];
void dfs(int u, int p) {
  sz[u] = 1;
  fa[u] = p;
  for (int& v : G[u]) {
    if (v == p) continue;
    dfs(v, u);
    sz[u] += sz[v];
  }
}
inline void work() {
  for (int i = 0; i < N; ++i) {
    G[i].clear();
  }
  scanf("%d%d", &N, &K);
  for (int i = 1; i < N; ++i) {
    G[(i - 1) / K].push_back(i);
  }
  dfs(0, 0);
  int ans = sz[0];
  for (int i = 1; i < N; ++i) {
    ans ^= sz[i];
  }
  printf("%d\n", ans);
}
int main() {
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    work();
  }
  return 0;
}
