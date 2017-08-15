// 无向图
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
using namespace std;

const int maxn = 1e5 + 10;
vector<int> G[maxn];
bool is_cut[maxn];
int n, m, count = 0;
int low[maxn], dfn[maxn], fa[maxn];  // fa[u]记录u的父亲节点编号
// dfn[u]记录节点u在DFS过程中被遍历到的次序号，low[u]记录节点u或u的子树通过非父子边追溯到最早的祖先节点（即DFS次序号最小

void tarjan(int u, int p) {
  fa[u] = p;  //记录当前u的父亲节点
  dfn[u] = low[u] = count++;
  for (int i = 0; i < (int)G[u].size(); i++) {
    const int& v = G[u][i];
    if (dfn[v] == -1) {
      tarjan(v, u);
      low[u] = min(low[u], low[v]);
    } else if (p != v) {  //如果v是u的父亲的话，即有重边，那么不可能是桥
      low[u] = min(low[u], dfn[v]);
    }
  }
}

void solve() {
  int rootson = 0;
  tarjan(1, 0);
  for (int i = 2; i <= n; i++) {
    int v = fa[i];
    if (v == 1) {
      rootson++;  //统计根节点的子树个数，若其不小于2,即为割点
    } else if (low[i] >= dfn[v]) {
      is_cut[v] = true;
    }
  }

  if (rootson > 1) is_cut[1] = true;

  puts("\n桥为：");
  for (int i = 1; i <= n; i++) {
    int v = fa[i];
    if (v > 0 && low[i] > dfn[v]) {
      printf("%d %d\n", v, i);
    }
  }
  puts("");
}

int main(void) {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    G[x].push_back(y);
    G[y].push_back(x);
  }
  memset(dfn, -1, sizeof(dfn));
  memset(low, -1, sizeof(low));
  solve();
  return 0;
}

// 有向图
#include <cstdio>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;

#define MEM(a) memset(a, 0, sizeof(a))
const int maxv = 21000;
vector<int> G[maxv];
int pre[maxv], lowlink[maxv], sccno[maxv], ans[maxv], dfs_clock, scc_cnt;
stack<int> S;

void dfs(int u) {
  pre[u] = lowlink[u] = ++dfs_clock;
  S.push(u);
  for (int i = 0; i < (int)G[u].size(); i++) {
    int v = G[u][i];
    if (!pre[v]) {
      dfs(v);
      if (lowlink[u] > lowlink[v]) lowlink[u] = lowlink[v];
    } else if (!sccno[v]) {
      if (lowlink[u] > pre[v]) lowlink[u] = pre[v];
    }
  }
  if (lowlink[u] == pre[u]) {
    scc_cnt++;
    for (;;) {
      int x = S.top();
      S.pop();
      sccno[x] = scc_cnt;
      if (x == u) break;
    }
  }
}
void find_scc(int n) {
  dfs_clock = scc_cnt = 0;
  MEM(sccno);
  MEM(pre);
  MEM(ans);
  for (int i = 1; i <= n; i++) {
    if (!pre[i]) dfs(i);
  }
}

int main() {
  int n, m, u, v;
  while (scanf("%d%d", &n, &m) != EOF) {
    for (int i = 1; i <= n; i++) G[i].clear();
    for (int i = 0; i < m; i++) {
      scanf("%d%d", &u, &v);
      G[u].push_back(v);
    }
    find_scc(n);
    for (int u = 1; u <= n; u++) {
      ans[sccno[u]]++;
    }
    int cnt = 0;
    for (int i = 1; i <= scc_cnt; i++)
      if (ans[i] > 1) cnt++;
    printf("%d\n", cnt);
  }
  return 0;
}
