#include <bits/stdc++.h>
using namespace std;
const int maxn = 20000 + 20;
vector<int> G[maxn];
void add_edge(int u, int v) {
  G[u].push_back(v);
  G[v].push_back(u);
}
int dfs_clock;
int dfn[maxn];
int low[maxn];
int parent[maxn];
int bccno[maxn], bcc_cont;
bool vis[maxn];
vector<int> bcc[maxn];
stack<int> sta;
void tarjan(int u) {
  dfn[u] = low[u] = ++dfs_clock;
  sta.push(u);
  vis[u] = true;
  for (const int& v : G[u]) {
    if (!vis[v]) {
      parent[v] = u;
      tarjan(v);
      low[u] = min(low[u], low[v]);

      if (low[v] > dfn[u]) {
        // bridge
        ;
      }
    } else if (v != parent[u]) {
      low[u] = min(low[u], dfn[v]);
    }
  }

  if (low[u] == dfn[u]) {
    bcc[bcc_cont] = {};
    do {
      int x = sta.top();
      sta.pop();
      bccno[x] = bcc_cont;
      bcc[bcc_cont].push_back(x);
      if (x == u) break;
    } while(true);
    ++bcc_cont;
  }
}
void init(int N) {
  for (int i = 1; i <= N; ++i) {
    G[i].clear();
  }
  memset(dfn, 0, sizeof(dfn));
  memset(low, 0, sizeof(low));
  memset(bccno, 0, sizeof(bccno));
  memset(vis, 0, sizeof(vis));
  dfs_clock = 0; bcc_cont = 1;
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

  printf("%d\n", bcc_cont - 1);
  for (int i = 1; i <= N; ++i) {
    printf("%d%c", *min_element(bcc[bccno[i]].begin(), bcc[bccno[i]].end()), (i == N ? '\n' : ' '));
  }
}
int main() {
  while (scanf("%d%d", &N, &M) != EOF) {
    work();
  }
  return 0;
}
