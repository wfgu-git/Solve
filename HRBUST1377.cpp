#include <bits/stdc++.h>
using namespace std;
const int maxn =100 + 20;
const int maxv = 32000 + 20;
int N, V;
int belong[maxn];
int p[maxn];
int w[maxn];
int c[maxn];
int box[maxn];
int dp[maxv];
int tdp[maxv];
int arc[maxn];
vector<int> G[maxn];
inline void work() {
  for (int i = 1; i <= N; ++i) {
    scanf("%d%d%d", c + i, p + i, belong + i);
  }
  int tot = 0;
  for (int i = 1; i <= N; ++i) {
    if (!belong[i]) {
      G[++tot].push_back(i);
      arc[i] = tot;
    } else {
      G[arc[belong[i]]].push_back(i);
    }
  }
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i <=)
}
int main() {
  while (scanf("%d%d", &V, &N) != EOF) {
    work();
  }
  return 0;
}
