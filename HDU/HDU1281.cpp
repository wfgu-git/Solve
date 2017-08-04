#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 20;
vector<int> g[maxn];
void add_edge(int u, int v) {
  g[u].push_back(v);
  g[v].push_back(u);
}
int n, m, k;
int main() {
  while (scanf("%d%d%d", &n, &m, &k) != EOF) {
    for (int i = 0; i < k; ++i) {
      static int u, v;
      add_edge(u, v + 105);
    }
  }
  return 0;
}
