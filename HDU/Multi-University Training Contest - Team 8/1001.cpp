#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 20;
vector<int> tree[maxn];
int N;
int a[maxn], depth[maxn];
int t[maxn];
long long dfs(int u, int p, int d) {
  depth[u] = d;
  int child = 0;
  for (const int& v : tree[u]) {
    if (v == p) continue;
    t[child++] = dfs(v, u, d + 1);
  }
  long long cost =
}
void work() {
  scanf("%d", &N);
  for (int i = 1; i <= N; ++i) {
    tree[i].clear();
    scanf("%d", a + i);
  }
  for (int u, v, i = 1; i < N; ++i) {
    scanf("%d%d", &u, &v);
    tree[u].push_back(v);
    tree[v].push_back(u);
  }

  dfs(1, 1, 0);

}
int main() {
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    work();
  }
  return 0;
}
