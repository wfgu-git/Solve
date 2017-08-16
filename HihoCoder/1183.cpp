#include <bits/stdc++.h>
using namespace std;
const int maxn = 20000 + 20;
vector<int> G[maxn];
void add_edge(int u, int v) {
  G[u].push_back(v);
  G[v].push_back(u);
}
set<int> cut;
struct comp {
  bool operator () (const pair<int, int>& x, const pair<int, int>& y) const {
    if (x.first == y.first) return x.second < y.second;
    return x.first < y.first;
  }
} ;
set<pair<int, int>, comp> bridge;
int parent[maxn];
int low[maxn], dfn[maxn], dfs_clock;
bool vis[maxn];
void tarjan(int u) {
  dfn[u] = low[u] = ++dfs_clock;
  vis[u] = 1;
  int son = 0;
  for (const int& v : G[u]) {
    if (!vis[v]) {
      ++son;
      parent[v] = u;
      //节点v未被访问，则(u,v)为树边
      tarjan(v);
      low[u] = min(low[u], low[v]);

      if (parent[u] == 0 && son > 1) {
        // u(root) is an articulation point
        cut.insert(u);
      }

      if (parent[u] != 0 && low[v] >= dfn[u]) {
        // u is an articulation point
        cut.insert(u);
      }

      if (low[v] > dfn[u]) {
        // bridge
        bridge.insert({min(u, v), max(u, v)});
      }
    } else if (v != parent[u]) {
      // v不是u的父节点
      //节点v已访问，则(u,v)为回边
      low[u] = min(low[u], dfn[v]);
    }
  }
}
void init(int N) {
  for (int i = 1; i <= N; ++i) G[i].clear();
  memset(dfn, 0, sizeof(dfn));
  memset(low, 0, sizeof(low));
  memset(parent, 0, sizeof(parent));
  memset(vis, 0, sizeof(vis));
  cut.clear(); bridge.clear();
  dfs_clock = 0;
}
int N, M;
inline void work() {
  init(N);
  for (int i = 0; i < M; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    add_edge(u, v);
  }
  tarjan(1);

  if (cut.size()) {
    bool fi = true;
    for (int x : cut) {
      if (fi) {
        fi = false;
        printf("%d", x);
      } else {
        printf(" %d", x);
      }
    }
    printf("\n");
  } else {
    printf("Null\n");
  }

  if (bridge.size()) {
    for (pair<int, int> x : bridge) {
      printf("%d %d\n", x.first, x.second);
    }
  }
}
int main() {
  while (scanf("%d%d", &N, &M) != EOF) {
    work();
  }
  return 0;
}
