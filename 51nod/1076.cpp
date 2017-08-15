#include <bits/stdc++.h>
using std::vector;
using std::min;
const int maxn = 50000 + 20;
vector<int> G[maxn];
void add_edge(int u, int v) {
  G[u].push_back(v);
  G[v].push_back(u);
}
int low[maxn], dfn[maxn], fa[maxn], dfs_clock;
bool is_cut[maxn], insta[maxn];
int sta[maxn], top;
int belong[maxn], bcc_cont;
void tarjan(int u, int p) {
  low[u] = dfn[u] = ++dfs_clock;
  sta[++top] = u; insta[u] = true;
  fa[u] = p;
  for (const int& v : G[u]) {
    if (dfn[v] == -1) {
      tarjan(v, u);
      low[u] = min(low[u], low[v]);
    } else if (insta[v] && p != v) {
      low[u] = min(low[u], dfn[v]);
    }
  }
  if (dfn[u] == low[u]) {
    ++bcc_cont;
    int tmp;
    do {
      tmp = sta[top--];
      insta[tmp] = false;
      belong[tmp] = bcc_cont;
    } while (tmp != u);
  }
}
int N, M, Q;
inline void work() {
  for (int i = 1; i <= N; ++i) {
    G[i].clear();
  }
  static int u, v;
  for (int i = 0; i < M; ++i) {
    scanf("%d%d", &u, &v);
    add_edge(u, v);
  }

  dfs_clock = bcc_cont = top = 0;
  memset(belong, -1, sizeof(belong));
  memset(dfn, -1, sizeof(dfn));
  memset(low, -1, sizeof(low));
  for (int u = 1; u <= N; ++u) {
    if (dfn[u] == -1) tarjan(u, 0);
  }

  scanf("%d", &Q);
  for (int i = 0; i < Q; ++i) {
    scanf("%d%d", &u, &v);
    if (belong[u] == belong[v]) printf("Yes\n");
    else printf("No\n");
  }
}
int main() {
  while (scanf("%d%d", &N, &M) != EOF) {
    work();
  }
  return 0;
}
