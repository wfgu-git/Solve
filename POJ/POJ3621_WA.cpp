#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 1000 + 20;
int w[maxn];
double mid;
struct Edge {
  int from, to, cost;
  Edge() {}
  Edge(int u, int v, int d) : from(u), to(v), cost(d) {}
} ;
struct DFS_SPFA {
  int m, n;
  vector<Edge> edges;
  vector<int> g[maxn];
  bool flag;
  bool used[maxn];
  double dist[maxn];
  void init(int n) {
    this->n = n;
    for (int i = 0; i <= n; ++i) {
      g[i].clear();
    }
    edges.clear();
  }
  void add_edge(int u, int v, int d) {
    edges.push_back(Edge(u, v, d));
    m = edges.size();
    g[u].push_back(m - 1);
  }
  void spfa(int u) {
    used[u] = true;
    for (int i = 0; i < g[u].size(); ++i) {
      const Edge& e = edges[g[u][i]];
      int v = e.to;
      double C = 1.0 * w[u] - mid * (double)e.cost;
      if (dist[u] + C > dist[v]) {
        if (used[v]) {
          flag = true;
          return;
        } else {
          dist[v] = dist[u] + C;
          spfa(v);
        }
      }
    }
    used[u] = false;
  }
  void run(int start) {
    memset(used, 0, sizeof(used));
    memset(dist, 0, sizeof(dist));
    flag = false;
    spfa(1);
  }
} spfa;
int N, M;
bool check() {
  spfa.run(1);
  if (spfa.flag) return true;
  else return false;
}
inline void work() {
  spfa.init(N);
  for (int i = 1; i <= N; ++i) {
    scanf("%d", w + i);
  }
  for (int i = 0; i < M; ++i) {
    static int u, v, d;
    scanf("%d%d%d", &u, &v, &d);
    spfa.add_edge(u, v, d);
  }
  double lb = 0.0, ub = 10000;
  for (int i = 0; i < 100; ++i) {
    mid = (lb + ub) / 2.0;
    if (check()) {
      lb = mid;
    } else {
      ub = mid;
    }
  }
  printf("%.2f\n", lb);
}
int main() {
  // freopen("data.in", "r", stdin);
  while (scanf("%d%d", &N, &M) != EOF) {
    work();
  }
  return 0;
}
