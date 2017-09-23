/*
教练我要打ACM!
*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxm = 100000 + 20;
const int maxn = 1000 + 20;

struct Edge {
  int from, to, dist, next;
} edge[maxm], redge[maxm];
struct node {
  int u, g, h;
  bool operator < (const node& rhs) const {
    if (g + h == rhs.g + rhs.h) {
      return g > rhs.g;
    }
    return g + h > rhs.g + rhs.h;
  }
} ;
bool vis[maxn];
int dist[maxn];
int head[maxn], tot;
int rhead[maxn], rtot;
void add_edge(int u, int v, int d) {
  edge[tot] = {u, v, d, head[u]};
  head[u] = tot++;
}
void add_redge(int u, int v, int d) {
  redge[rtot] = {u, v, d, rhead[u]};
  rhead[u] = rtot++;
}
void dijkstra(int s, int n) {
  memset(vis, 0, sizeof(vis));
  for (int i = 1; i <= n; ++i) {
    dist[i] = inf;
  }
  for (int i = rhead[s]; i != -1; i = redge[i].next) {
    dist[redge[i].to] = redge[i].dist;
  }
  dist[s] = 0;
  while (true) {
    int v = -1;
    int Min = inf;
    for (int i = 1; i <= n; ++i) {
      if (!vis[i] && dist[i] < Min) {
        v = i;
        Min = dist[i];
      }
    }
    if (v == -1) break;
    vis[v] = 1;
    for (int i = rhead[v]; i != -1; i = redge[i].next) {
      if (!vis[redge[i].to] && dist[redge[i].to] > dist[v] + redge[i].dist) {
        dist[redge[i].to] = dist[v] + redge[i].dist;
      }
    }
  }
}
int kth_path(int s, int t, int k) {
  if (dist[s] == inf) return -1;
  if (s == t) k++;
  priority_queue<node> Q;
  Q.push({s, 0, dist[s]});
  int cont = 0;
  while (!Q.empty()) {
    node now = Q.top(); Q.pop();
    if (now.u == t) cont++;
    if (cont == k) return now.g;
    for (int i = head[now.u]; i != -1; i = edge[i].next) {
      Q.push({edge[i].to, edge[i].dist + now.g, dist[edge[i].to]});
    }
  }
  return -1;
}
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  int n, m;
  while (~scanf("%d%d", &n, &m)) { // n 个点 m 条边 (边是有向边)
    memset(head, -1, sizeof(head));
    memset(rhead, -1, sizeof(rhead));
    tot = rtot = 0;
    int u, v, d;
    for (int i = 0; i < m; i++) {
      scanf("%d%d%d", &u, &v, &d);
      add_edge(u, v, d);
      add_redge(v, u, d);
    }
    int s, t, k;
    scanf("%d%d%d", &s, &t, &k);  //读入起点 s 终点 t 以及要求的第 v 短路中的 v
    dijkstra(t, n);
    int ans = kth_path(s, t, k);
    printf("%d\n", ans);
  }
  return 0;
}
