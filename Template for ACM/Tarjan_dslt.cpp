#include <bits/stdc++.h>
using namespace std;
const int maxn = 20000 + 20;
const int maxm = 200000 + 20;
int N, M;
int head[maxn], tot;
struct Edge {
  int from, to, next, tid;
} edge[maxm];
void add_edge(int u, int v, int i) {
  edge[tot] = {u, v, head[u], i};
  head[u] = tot++;
}
stack<Edge> sta;
vector<Edge> tmp;
map<pair<int, int>, bool> used;
int bcc_cont;
int bccno[maxm];
int ans[maxm];
bool vis[maxn];
int low[maxn], dfn[maxn], dfs_clock;
int parent[maxn];
void tarjan(int u) {
  low[u] = dfn[u] = ++dfs_clock;
  vis[u] = true;
  int son = 0;
  for (int i = head[u]; i != -1; i = edge[i].next) {
    Edge& e = edge[i];
    int v = edge[i].to;
    if (used[{u, v}]) continue;
    used[{u, v}] = true;
    used[{v, u}] = true;
    if (!vis[v]) {
      ++son;
      parent[v] = u;
      sta.push(e);
      tarjan(v);
      low[u] = min(low[u], low[v]);

      if (!parent[u] && son > 1) {
        tmp.clear();
        int Min = 10000000;
        Edge now;
        do {
          now = sta.top();
          sta.pop();
          bccno[now.tid] = bcc_cont;
          tmp.push_back(now);
          Min = min(Min, now.tid);
        } while (e.from != now.from || e.to != now.to);
        bcc_cont++;
        for (Edge& x : tmp) {
          ans[x.tid] = Min;
        }
      }

      if (parent[u] && low[v] >= dfn[u]) {
        tmp.clear();
        int Min = 10000000;
        Edge now;
        do {
          now = sta.top();
          sta.pop();
          bccno[now.tid] = bcc_cont;
          tmp.push_back(now);
          Min = min(Min, now.tid);
        } while (e.from != now.from || e.to != now.to);
        bcc_cont++;
        for (Edge& x : tmp) {
          ans[x.tid] = Min;
        }
      }

    } else if (v != parent[u]) {
      low[u] = min(low[u], dfn[v]);
      sta.push(e);
    }
  }
}
void init() {
  memset(low, 0, sizeof(low));
  memset(parent, 0, sizeof(parent));
  memset(head, -1, sizeof(head));
  memset(vis, 0, sizeof(vis));
  used.clear(); tmp.clear();
  dfs_clock = tot = 0;
  bcc_cont = 1;
}
inline void work() {
  init();
  for (int i = 1; i <= M; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    add_edge(u, v, i);
    add_edge(v, u, i);
  }
  tarjan(1);

  tmp.clear();
  int Min = 10000000;
  while (!sta.empty()) {
    bccno[sta.top().tid] = bcc_cont;
    tmp.push_back(sta.top());
    Min = min(Min, sta.top().tid);
    sta.pop();
  }
  for (Edge& x : tmp) {
    ans[x.tid] = Min;
  }

  printf("%d\n", bcc_cont);
  for (int i = 1; i <= M; ++i) {
    printf("%d%c", ans[i], (i < M ? ' ' : '\n'));
  }
}
int main() {
  // freopen("data.in", "r", stdin);
  while (scanf("%d%d", &N, &M) != EOF) {
    work();
  }
  return 0;
}
