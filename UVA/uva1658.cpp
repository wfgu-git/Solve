#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1000 * 2 + 20;
struct Edge {
  int from, to, cap, flow, cost;
} ;
struct MCMF {
  int n, m, s, t;
  vector<Edge> edges;
  vector<int> G[maxn];
  int inq[maxn];
  int d[maxn];
  int p[maxn];
  int a[maxn];

  void init(int n) {
    this->n = n;
    for (int i = 0; i < n; ++i) G[i].clear();
    edges.clear();
  }

  void add_edge(int from, int to, int cap, int cost) {
    edges.push_back((Edge) {from, to, cap, 0, cost});
    edges.push_back((Edge) {to, from, 0, 0, -cost});
    m = edges.size();
    G[from].push_back(m - 2);
    G[to].push_back(m - 1);
  }

  bool SPFA(int s, int t, int& flow, int& cost) {
    for (int i = 0; i < n; ++i) d[i] = inf;
    memset(inq, 0, sizeof(inq));
    d[s] = 0; inq[s] = 1; p[s] = 0; a[s] = inf;

    queue<int> Q;
    Q.push(s);
    while (!Q.empty()) {
      int u = Q.front(); Q.pop();
      inq[u] = 0;
      for (int i = 0; i < (int)G[u].size(); ++i) {
        Edge& e = edges[G[u][i]];
        if (e.cap > e.flow && d[e.to]  > d[u] + e.cost) {
          d[e.to] = d[u] + e.cost;
          p[e.to] = G[u][i];
          a[e.to] = min(a[u], e.cap - e.flow);
          if (!inq[e.to]) { Q.push(e.to); inq[e.to] = 1; }
        }
      }
    }

    if (d[t] == inf) return false;
    // if (d[t] >= 0) return false;

    // add flow
    flow += a[t];
    cost += d[t] * a[t];
    int u = t;
    while (u != s) {
      edges[p[u]].flow += a[t];
      edges[p[u] ^ 1].flow -= a[t];
      u = edges[p[u]].from;
    }

    return true;
  }

  int run(int s, int t) {
    int flow = 0, cost = 0;
    while (SPFA(s, t, flow, cost));
    return cost;
  }

} mcmf;
int N, M;
void work() {
  mcmf.init(2 * N + 5);
  for (int i = 0; i < M; ++i) {
    int u, v, c;
    scanf("%d%d%d", &u, &v, &c);
    mcmf.add_edge(u + N, v, 1, c);
  }
  for (int i = 2; i <= N; ++i) {
    mcmf.add_edge(i, i + N, 1, 0);
  }
  mcmf.add_edge(1, 1 + N, 2, 0);
  mcmf.add_edge(N, N + N, 2, 0);
  printf("%d\n", mcmf.run(1, N + N));
}
int main() {
  while (scanf("%d%d", &N, &M) != EOF) {
    work();
  }
  return 0;
}
