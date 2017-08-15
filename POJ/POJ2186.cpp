#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

const int maxn = 1e6 + 10;

int sta[maxn];  //  每遍历一个点便入栈
int top;
bool insta[maxn];  //  判断某个点是否已经在栈里面

//  这两个数组至关重要
//  dfn[u]为节点u搜索的次序编号（时间戳）
//  low[u]为u或者u的子树能够追溯到的最早的栈中节点的次序号
int dfn[maxn];
int low[maxn];
int fa[maxn];
int sz[maxn];
int belong[maxn];     //  判断哪些点联通
int cont, dfs_clock;  //  记录强连通个数和当前时间
vector<int> G[maxn];  //  邻接表保存边
int odeg[maxn];
int N, M, Q;
void add_edge(int u, int v) { G[u].push_back(v); }
void tarjan(int u, int p) {
  dfn[u] = low[u] = ++dfs_clock;
  fa[u] = p;
  sta[++top] = u;
  insta[u] = true;  //  入队列，置为true

  for (int i = 0; i < (int)G[u].size(); i++) {
    const int& v = G[u][i];
    if (!dfn[v]) {
      tarjan(v, u);
      low[u] = min(low[u], low[v]);
    } else if (insta[v]) {
      low[u] = min(low[u], dfn[v]);
    }
  }

  if (dfn[u] == low[u]) {
    ++cont;
    int tmp;
    do {
      tmp = sta[top--];
      insta[tmp] = false;  //  出队列，置为false
      belong[tmp] = cont;
      ++sz[cont];
    } while (tmp != u);
  }
}
int xx[maxn], yy[maxn];
inline void work() {
  for (int i = 1; i <= N; i++) {
    G[i].clear();
  }
  for (int i = 0; i < M; i++) {
    static int u, v;
    scanf("%d %d", &u, &v);
    G[u].push_back(v);
    xx[i] = u; yy[i] = v;
    }

  cont = dfs_clock = top = 0;
  memset(dfn, 0, sizeof(dfn));
  memset(low, 0, sizeof(low));
  memset(insta, 0, sizeof(insta));
  memset(belong, 0, sizeof(belong));
  memset(sz, 0, sizeof(sz));
  memset(odeg, 0, sizeof(odeg));
  for (int i = 1; i <= N; ++i) {
    if (!dfn[i]) {
      tarjan(i, 0);
    }
  }

  for (int i = 0; i < M; ++i) {
    if (belong[xx[i]] != belong[yy[i]]) {
      odeg[belong[xx[i]]]++;
    }
  }

  int ans = 0;
  for (int i = 1; i <= cont; ++i) {
    if (!odeg[i]) {
      if (ans) {
        printf("0\n");
        return;
      }
      ans = i;
    }
  }
  printf("%d\n", sz[ans]);
}
int main() {
  // freopen("data.in", "r", stdin);
  while (scanf("%d%d", &N, &M) != EOF) {
    work();
  }
  return 0;
}
