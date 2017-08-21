#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
const int MAXN = 505;
const int MAXM = 440020;
const int INF = 0x3f3f3f;
const int maxx = 0x3f3f3f3f;
using namespace std;
struct Edge {
  int to, cap, flow, next;
} edge[MAXM];
int head[MAXN], tot, gap[MAXN], d[MAXN], cur[MAXN], que[MAXN], p[MAXN];

void init() {
  tot = 0;
  memset(head, -1, sizeof(head));
}

int isap(int source, int sink, int N) {
  memset(gap, 0, sizeof(gap));
  memset(d, 0, sizeof(d));
  memcpy(cur, head, sizeof(head));
  int top = 0, x = source, flow = 0;
  while (d[source] < N) {
    if (x == sink) {
      int Min = maxx, inser = 0;
      for (int i = 0; i < top; ++i) {
        if (Min > edge[p[i]].cap - edge[p[i]].flow) {
          Min = edge[p[i]].cap - edge[p[i]].flow;
          inser = i;
        }
      }
      for (int i = 0; i < top; ++i) {
        edge[p[i]].flow += Min;
        edge[p[i] ^ 1].flow -= Min;
      }
      if (Min != INF) flow += Min;
      top = inser;
      x = edge[p[top] ^ 1].to;
      continue;
    }
    int ok = 0;
    for (int i = cur[x]; i != -1; i = edge[i].next) {
      int v = edge[i].to;
      if (edge[i].cap > edge[i].flow && d[v] + 1 == d[x]) {
        ok = 1;
        cur[x] = i;
        p[top++] = i;
        x = edge[i].to;
        break;
      }
    }
    if (!ok) {
      int Min = N;
      for (int i = head[x]; i != -1; i = edge[i].next) {
        if (edge[i].cap > edge[i].flow && d[edge[i].to] < Min) {
          Min = d[edge[i].to];
          cur[x] = i;
        }
      }
      if (--gap[d[x]] == 0) break;
      gap[d[x] = Min + 1]++;
      if (x != source) x = edge[p[--top] ^ 1].to;
    }
  }
  return flow;
}

int b[205][25], h[205][25];
int sumr[205], sumc[205];
int id[205][25];  //用来保存[i][j]在邻接表的边的编号
int s, t;
int n, m;
int sum;
int flag;

void addedge(int u, int v, int c, int x, int y) {
  edge[tot] = (Edge){v, c, 0, head[u]};
  id[x][y] = head[u] = tot++;
  edge[tot] = (Edge){u, c, c, head[v]};
  head[v] = tot++;
}

void set_(int x, int y, char ch, int v) {
  if (ch == '=') {
    if (b[x][y] > v) flag = 1;
    if (h[x][y] < v) flag = 1;
    b[x][y] = h[x][y] = v;
  } else if (ch == '>') {
    if (h[x][y] <= v) flag = 1;
    b[x][y] = max(b[x][y], v + 1);
  } else {
    if (b[x][y] >= v) flag = 1;
    h[x][y] = min(h[x][y], v - 1);
  }
}

void build() {
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) addedge(i, n + j, h[i][j] - b[i][j], i, j);
  for (int i = 1; i <= n + m; i++) {
    int f = i <= n ? sumr[i] : -sumc[i - n];
    if (i <= n)
      for (int j = 1; j <= m; j++) f -= b[i][j];
    else
      for (int j = 1; j <= n; j++) f += b[j][i - n];
    if (f > 0) {
      addedge(s, i, f, 0, 0);
      sum += f;
    } else
      addedge(i, t, -f, 0, 0);
  }
}

int main() {
  freopen("/home/wfgu/solve/data.in", "r", stdin);
  int T;
  int nn, a, bb, c;
  char ch;
  scanf("%d", &T);
  for (int Case = 1; Case <= T; Case++) {
    if (Case != 1) printf("\n");
    scanf("%d%d", &n, &m);
    init();
    s = 0, t = n + m + 1;
    sum = 0;
    flag = 0;

    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)  //初始上下界
      {
        b[i][j] = 0;
        h[i][j] = INF;
      }
    for (int i = 1; i <= n; i++) scanf("%d", &sumr[i]);
    for (int j = 1; j <= m; j++) scanf("%d", &sumc[j]);
    scanf("%d", &nn);
    while (nn--)  //限定上下界
    {
      cin >> a >> bb >> ch >> c;
      if (!a && !bb) {
        for (int i = 1; i <= n; i++)
          for (int j = 1; j <= m; j++) set_(i, j, ch, c);
      } else if (!a && bb) {
        for (int i = 1; i <= n; i++) set_(i, bb, ch, c);
      } else if (a && !bb) {
        for (int i = 1; i <= m; i++) set_(a, i, ch, c);
      } else
        set_(a, bb, ch, c);
    }
    if (flag == 1) {  //约束条件矛盾
      printf("IMPOSSIBLE\n");
      continue;
    }
    build();
    int ans = isap(s, t, t + 1);

    if (sum != ans)  //源流==汇流
      printf("IMPOSSIBLE\n");
    else {
      for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
          if (j == m)
            printf("%d\n", b[i][j] + edge[id[i][j]].flow);
          else
            printf("%d ", b[i][j] + edge[id[i][j]].flow);
    }
  }
  return 0;
}
