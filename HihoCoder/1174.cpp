#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 20;
vector<int> G[maxn];
int used[maxn];
int N, M;
bool topo(int u) {
  used[u] = -1;
  for (const int& v : G[u]) {
    if (used[v] < 0) return false;
    else if (!used[v] && !topo(v)) return false;
  }
  used[u] = 1;
  return true;
}
inline void work() {
  scanf("%d%d", &N, &M);
  for (int i = 1; i <= N; ++i) {
    G[i].clear();
  }
  for (int i = 0; i < M; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].push_back(v);
  }
  memset(used, 0, sizeof(used));
  for (int i = 1; i <= N; ++i) {
    if (!topo(i)) {
      printf("Wrong\n");
      return;
    }
  }
  printf("Correct\n");
}
int main() {
  // freopen("data.in", "r", stdin);
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    work();
  }
  return 0;
}
