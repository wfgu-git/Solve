#include <iostream>
using namespace std;
#include <string.h>
#include <algorithm>
#define maxn 20005
#define maxm 200005
#define INF 0xfffffff
int bccno[maxm], sta[maxm];
int dfn[maxn], low[maxn], top, bcc_cont, dfs_clock;
int head[maxn], f, n, m, Min[maxn], parent[maxn], vis[maxn];
struct node {
  int e, next, t;
} edge[maxm];
void add_edge(int s, int e, int i) {
  edge[f].e = e;
  edge[f].t = i;
  edge[f].next = head[s];
  head[s] = f++;
}
void dfs(int u) {
  int son = 0;
  low[u] = dfn[u] = ++dfs_clock;
  vis[u] = 1;
  for (int i = head[u]; i != -1; i = edge[i].next) {
    int v = edge[i].e;
    int t = edge[i].t;
    if (!vis[v]) {
      ++son;
      sta[top++] = t;
      parent[v] = u;
      dfs(v);
      low[u] = min(low[u], low[v]);
      if (v == 1 && son > 1 || v != 1 && low[v] >= dfn[u]) {
      // if ((parent[u] != 0 && son > 1) || (parent[u] != 0 && low[v] >= dfn[u])) {
        // printf("u = %d v = %d parent[%d] = %d\n", u, v, u, parent[u]);
        bcc_cont++;
        int now = -1;
        Min[bcc_cont] = INF;
        while (now != t) {
          now = sta[--top];
          bccno[now] = bcc_cont;
          Min[bcc_cont] = min(Min[bcc_cont], now);
        }
      }
    } else if (parent[u] != v && dfn[v] < dfn[u]) {
      sta[top++] = t;
      low[u] = min(low[u], dfn[v]);
    }
  }
}
int main() {
  freopen("data.in", "r", stdin);
  int i, a, b;
  cin >> n >> m;
  memset(head, -1, sizeof(head));
  f = 1;
  for (i = 1; i <= m; i++) {
    cin >> a >> b;
    add_edge(a, b, i);
    add_edge(b, a, i);
  }
  memset(dfn, 0, sizeof(dfn));
  memset(low, 0, sizeof(low));
  memset(vis, 0, sizeof(vis));
  dfs_clock = top = bcc_cont = 0;
  dfs(1);
  cout << bcc_cont << endl;
  for (i = 1; i <= m; i++) cout << Min[bccno[i]] << " ";
  cout << endl;
  return 0;
}
