#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
#define maxM 50000
#define maxN 500
#define inf 1 << 30
struct node {
  int u, v, f, next;
} edge[maxM];
int head[maxN], p, lev[maxN], cur[maxN];
int que[maxM], tre[maxN], up[maxN][50], low[maxN][50];
void init1(int n, int m) {
  p = 0, memset(head, -1, sizeof(head)), memset(tre, 0, sizeof(tre));
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= m; j++) up[i][j] = inf, low[i][j] = 0;
}
bool bfs(int s, int t) {
  int qin = 0, qout = 0, u, i, v;
  memset(lev, 0, sizeof(lev));
  lev[s] = 1, que[qin++] = s;
  while (qout != qin) {
    u = que[qout++];
    for (i = head[u]; i != -1; i = edge[i].next) {
      if (edge[i].f > 0 && lev[v = edge[i].v] == 0) {
        lev[v] = lev[u] + 1, que[qin++] = v;
        if (v == t) return 1;
      }
    }
  }
  return lev[t];
}
int dinic(int s, int t) {
  int qin, u, i, k, f;
  int flow = 0;
  while (bfs(s, t)) {
    memcpy(cur, head, sizeof(head));
    u = s, qin = 0;
    while (1) {
      if (u == t) {
        for (k = 0, f = inf; k < qin; k++)
          if (edge[que[k]].f < f) f = edge[que[i = k]].f;
        for (k = 0; k < qin; k++) edge[que[k]].f -= f, edge[que[k] ^ 1].f += f;
        flow += f, u = edge[que[qin = i]].u;
      }
      for (i = cur[u]; cur[u] != -1; i = cur[u] = edge[cur[u]].next)
        if (edge[i].f > 0 && lev[u] + 1 == lev[edge[i].v]) break;
      if (cur[u] != -1)
        que[qin++] = cur[u], u = edge[cur[u]].v;
      else {
        if (qin == 0) break;
        lev[u] = -1, u = edge[que[--qin]].u;
      }
    }
  }
  return flow;
}
void addedge(int u, int v, int f) {
  edge[p].u = u, edge[p].v = v, edge[p].f = f, edge[p].next = head[u],
  head[u] = p++;
  edge[p].u = v, edge[p].v = u, edge[p].f = 0, edge[p].next = head[v],
  head[v] = p++;
}
bool buit(int n, int m) {
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (low[i][j] > up[i][j])
        return 0;
      else {
        tre[i] -= low[i][j], tre[j + n] += low[i][j];
        addedge(i, j + n, up[i][j] - low[i][j]);
      }
  return 1;
}
void limitflow(int s, int t, int n, int m) {
  int i, j, x, y;
  x = t + 1, y = t + 2;
  for (i = 0; i <= t; i++) {
    if (tre[i] > 0)
      addedge(x, i, tre[i]);
    else if (tre[i] < 0)
      addedge(i, y, -tre[i]);
  }
  addedge(t, s, inf);
  dinic(x, y);
  for (i = head[x]; i != -1; i = edge[i].next)
    if (edge[i].f) {
      printf("IMPOSSIBLE\n\n");
      return;
    }
  for (i = head[t]; i != -1; i = edge[i].next)
    if (edge[i].v == s) break;
  if (i < 0) {
    printf("IMPOSSIBLE\n\n");
    return;
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j < m; j++)
      printf("%d ", edge[((i - 1) * m + j) * 2 - 1].f + low[i][j]);
    printf("%d\n", edge[i * m * 2 - 1].f + low[i][j]);
  }
  printf("\n");
}
int main() {
  freopen("/home/wfgu/solve/data.in", "r", stdin);
  int cas, cas1, n, m, i, j, sum1, sum2;
  int u, v, d, f1, t1, f2, t2, s, t;
  char c[5];
  scanf("%d", &cas);
  for (int tt = 1; tt <= cas; tt++) {
    scanf("%d%d", &n, &m);
    s = 0, t = n + m + 1, sum1 = 0, sum2 = 0;
    init1(n, m);
    for (i = 1; i <= n; i++)
      scanf("%d", &u), tre[s] -= u, tre[i] += u, sum1 += u;
    ;
    for (i = n + 1; i <= n + m; i++)
      scanf("%d", &u), tre[i] -= u, tre[t] += u, sum2 += u;
    scanf("%d", &cas1);
    while (cas1--) {
      scanf("%d%d%s%d", &u, &v, c, &d);
      f1 = t1 = u, f2 = t2 = v;
      if (u == 0) f1 = 1, t1 = n;
      if (v == 0) f2 = 1, t2 = m;
      for (i = f1; i <= t1; i++)
        for (j = f2; j <= t2; j++) {
          if (c[0] == '=') {
            low[i][j] = max(d, low[i][j]), up[i][j] = min(d, up[i][j]);
          } else if (c[0] == '>') {
            low[i][j] = max(d + 1, low[i][j]);
          } else if (c[0] == '<') {
            up[i][j] = min(d - 1, up[i][j]);
          }
        }
    }
    if (sum1 == sum2 && buit(n, m))
      limitflow(s, t, n, m);
    else
      printf("IMPOSSIBLE\n\n");
  }
  return 0;
}
