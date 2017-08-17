#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1000 * 2 + 20;
struct Edge {
  int from, to, cap, flow;
  long long cost;
} ;
struct MCMF {
  int N, m, S, T;
  vector<Edge> edges;
  vector<int> G[maxn];
  int inq[maxn];
  long long d[maxn];
  int p[maxn];
  int a[maxn];

  void init(int N) {
    this->N = N;
    for (int i = 0; i < N; ++i) G[i].clear();
    edges.clear();
  }

  void add_edge(int from, int to, int cap, int cost) {
    edges.push_back((Edge) {from, to, cap, 0, cost});
    edges.push_back((Edge) {to, from, 0, 0, -cost});
    m = edges.size();
    G[from].push_back(m - 2);
    G[to].push_back(m - 1);
  }

  bool SPFA(int S, int T, int& flow, long long& cost) {
    for (int i = 0; i < N; ++i) d[i] = inf;
    memset(inq, 0, sizeof(inq));
    d[S] = 0; inq[S] = 1; p[S] = 0; a[S] = inf;

    queue<int> Q;
    Q.push(S);
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

    // if (d[T] == inf) return false;
    if (d[T] >= 0) return false;

    // add flow
    flow += a[T];
    cost += d[T] * a[T];
    int u = T;
    while (u != S) {
      edges[p[u]].flow += a[T];
      edges[p[u] ^ 1].flow -= a[T];
      u = edges[p[u]].from;
    }

    return true;
  }

  long long run(int s, int t) {
    long long cost = 0;
    int flow = 0;
    while (SPFA(s, t, flow, cost));
    return cost;
  }

} mcmf;
int N, M;
int a[maxn], b[maxn], c[maxn], d[maxn];
void work() {
  mcmf.init(N * 5 + 5);
  for (int i = 1; i <= N; ++i) {
    scanf("%d%d%d%d", a + i, b + i, c + i, d + i);
  }
  for (int i = 0; i < M; ++i) {
    int u, v, k;
    scanf("%d%d%d", &u, &v, &k);

    mcmf.add_edge(u, v + N, inf, k);
    mcmf.add_edge(v, u + N, inf, k);
  }
  for (int i = 1; i <= N; ++i) {
    mcmf.add_edge(i, i + N, inf, 0);
    mcmf.add_edge(i + N, i, inf, 0);

    mcmf.add_edge(0, i, b[i], a[i]);
    mcmf.add_edge(i + N, N + N + 3, d[i], -c[i]);
  }
  printf("%lld\n", -mcmf.run(0, N + N + 3));
}
int main() {
  // freopen("data.in", "r", stdin);
  while (scanf("%d%d", &N, &M) != EOF) {
    work();
  }
  return 0;
}
