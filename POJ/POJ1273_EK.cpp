#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 50000;
struct Edge {
  int from, to, cap, flow;
  Edge(int u, int v, int c, int f) : from(u), to(v), cap(c), flow(f) {}
} ;
struct EdmondsKarp {
  int n, m;
  vector<Edge> edges;  // 边数的两倍
  vector<int> G[maxn];
  int a[maxn];  // 当前起点到i的可改进量
  int p[maxn];  // 最短路树上p的入弧编号

  void init(int n) {
    for (int i = 0; i < n; ++i)  G[i].clear();
    edges.clear();
  }

  void add_edge(int from, int to, int cap) {
    edges.push_back(Edge(from, to, cap, 0));
    edges.push_back(Edge(to, from, 0, 0));
    m = edges.size();
    G[from].push_back(m - 2);
    G[to].push_back(m - 1);
  }

  int run(int s, int t) {
    int flow = 0;
    for (;;) {
      memset(a, 0, sizeof(a));
      queue<int> Q;
      Q.push(s);
      a[s] = inf;
      while (!Q.empty()) {
        int x = Q.front(); Q.pop();
        for (int i = 0; i < (int)G[x].size(); i++) {
          Edge& e = edges[G[x][i]];
          if (!a[e.to] && e.cap > e.flow) {
            p[e.to] = G[x][i];
            a[e.to] = min(a[x], e.cap - e.flow);
            Q.push(e.to);
          }
        }
        if (a[t]) break;
      }
      if (!a[t]) break;
      for (int u = t; u != s; u = edges[p[u]].from) {
        edges[p[u]].flow += a[t];
        edges[p[u] ^ 1].flow -= a[t];
      }
      flow += a[t];
    }
    return flow;
  }

} max_flow;

int N, M;
void work() {
  max_flow.init(N);
  for (int i = 0; i < M; ++i) {
    int u, v, c;
    scanf("%d%d%d", &u, &v, &c);
    max_flow.add_edge(u, v, c);
  }
  printf("%d\n", max_flow.run(1, N));
}
int main() {
  freopen("/home/wfgu/solve/data.in", "r", stdin);
  while (scanf("%d%d", &M, &N) != EOF) {
    work();
  }
}
