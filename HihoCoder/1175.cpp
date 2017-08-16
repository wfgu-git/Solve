#include <bits/stdc++.h>
using namespace std;
const int moder = 142857;
const int maxn = 100000 + 20;
vector<int> G[maxn];
int ind[maxn];
int w[maxn];
int N, M, K;
inline void work() {
  memset(w, 0, sizeof(w));
  for (int i = 1; i <= K; ++i) {
    int x;
    scanf("%d", &x);
    w[x] = 1;
  }
  memset(ind, 0, sizeof(ind));
  for (int i = 0; i < M; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].push_back(v);
    ind[v]++;
  }

  queue<int> q;
  for (int i = 1; i <= N; ++i) {
    if (!ind[i]) {
      q.push(i);
    }
  }
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (const int& v : G[u]) {
      w[v] += w[u];
      w[v] %= moder;
      if (!--ind[v]) {
        q.push(v);
      }
    }
  }

  int ans = 0;
  for (int i = 1; i <= N; ++i) {
    ans = (1LL * w[i] + ans) % moder;
  }
  printf("%d\n", ans);
}
int main() {
  while (scanf("%d%d%d", &N, &M, &K) != EOF) {
    work();
  }
  return 0;
}
