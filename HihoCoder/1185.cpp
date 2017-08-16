#include <bits/stdc++.h>
using namespace std;
/*
tarjan(u)
{
    Dfn[u]=Low[u]=++Index                      // 为节点u设定次序编号和Low初值
    Stack.push(u)                              // 将节点u压入栈中
    for each (u, v) in E                       // 枚举每一条边
        if (v is not visted)                   // 如果节点v未被访问过
            tarjan(v)                          // 继续向下找
            Low[u] = min(Low[u], Low[v])
        else if (v in Stack)                   // 如果节点v还在栈内(很重要,无向图没有这一步)
            Low[u] = min(Low[u], Dfn[v])
    if (Dfn[u] == Low[u])                      // 如果节点u是强连通分量的根
        repeat
            v = Stack.pop                      // 将v退栈，为该强连通分量中一个顶点
            mark v                             // 标记v，同样通过栈来找连通分量
        until (u == v)
}
*/
const int maxn = 20000 + 20;
pair<int, int> edges[100000 + 20];
vector<int> G[maxn];
vector<int> rg[maxn];
int val[maxn];
void add_edge(int u, int v) {
  G[u].push_back(v);
}
int low[maxn], dfn[maxn], dfs_clock;
bool vis[maxn];
bool insta[maxn];
stack<int> sta;
int w[maxn];
int sccno[maxn], scc_cont;
vector<int> scc[maxn];
void tarjan(int u) {
  low[u] = dfn[u] = ++dfs_clock;
  sta.push(u);
  insta[u] = 1;
  // vis[u] = true;

  for (int& v : G[u]) {
    if (!dfn[v]) {
      tarjan(v);
      low[u] = min(low[u], low[v]);
    } else if (insta[v]) {
      low[u] = min(low[u], dfn[v]);
    }
  }

  // if (dfn[u] == low[u]) {
  //   scc[scc_cont] = {};
  //   do {
  //     int x = sta[--top];
  //     sccno[x] = scc_cont;
  //     w[scc_cont] += val[x];
  //     scc[scc_cont].push_back(x);
  //     if (x == u) break;
  //   } while(true);
  //   ++scc_cont;
  // }
  if (dfn[u] == low[u]) {
    scc_cont++;
    while (!sta.empty()) {
      int x = sta.top();
      sta.pop();
      insta[x] = 0;
      sccno[x] = scc_cont;
      w[scc_cont] += val[x];
      if (u == x) break;
    }
  }
}
int ind[maxn];
int N, M;
void rebuild() {
  // memset(ind, 0, sizeof(ind));
  // for (int u = 1; u <= N; ++u) {
  //   for (int& v : G[u]) {
  //     if (sccno[u] == sccno[v]) continue;
  //     rg[sccno[u]].push_back(sccno[v]);
  //     ind[sccno[v]]++;
  //   }
  // }
  for (int i = 0; i < M; ++i) {
    int u = sccno[edges[i].first];
    int v = sccno[edges[i].second];
    if (!u || !v) continue;
    if (u != v) {
      rg[u].push_back(v);
    }
  }
}
int ans;
void dfs(int u, int sum) {
  ans = max(ans, sum);
  for (const int& v : rg[u]) {
    if (!vis[v]) {
      vis[v] = true;
      dfs(v, sum + w[v]);
      vis[v] = false;
    }
  }
}
// vector<int> mark;
// int topo() {
//   queue<int> q;
//   q.push(sccno[1]);
//   mark.push_back(sccno[1]);
//   while (!q.empty()) {
//     int u = q.front(); q.pop();
//     for (const int& v : rg[u]) {
//       mark.push_back(v);
//       w[v] += w[u];
//       if (!--ind[v]) {
//         q.push(v);
//       }
//     }
//   }
//   int ans = 0;
//   for (int& x : mark) {
//     ans = max(ans, w[x]);
//   }
//   return ans;
// }
void work() {
  // mark.clear();
  memset(w, 0, sizeof(w));
  memset(sccno, 0, sizeof(sccno));
  memset(low, 0, sizeof(low));
  memset(dfn, 0, sizeof(dfn));
  memset(vis, 0, sizeof(vis));
  ans = dfs_clock = scc_cont = 0;
  // scc_cont = 1; // [L, R) -_-
  for (int i = 1; i <= N; ++i) {
    G[i].clear();
    rg[i].clear();
  }

  for (int i = 1; i <= N; ++i) {
    scanf("%d", &val[i]);
  }
  for (int i = 0; i < M; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    add_edge(u, v);
    edges[i] = {u, v};
  }

  tarjan(1);

  rebuild();

  memset(vis, 0, sizeof(vis));
  dfs(sccno[1], w[sccno[1]]);
  printf("%d\n", ans);

}
int main() {
  // freopen("data.in", "r", stdin);
  while (scanf("%d%d", &N, &M) != EOF) {
    work();
  }
  return 0;
}
