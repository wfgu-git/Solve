// ...naive version
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 1010;
struct Edge {
  int from, to, cost;
  Edge() {}
  Edge(int u, int v, int d) : from(u), to(v), cost(d) {}
} ;
struct DFS_SPFA {
  int m;
  vector<Edge> edges;
  vector<int> g[maxn];
  bool flag;
  bool used[maxn];
  int dist[maxn];
  void init(int n) {
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
      Edge& e = edges[g[u][i]];
      int v = e.to;
      int d = e.cost;
      if (dist[u] + d < dist[v]) {
        if (used[v]) {
          flag = true;
          return;
        } else {
          dist[v] = dist[u] + d;
          spfa(v);
        }
      }
    }
    used[u] = false;
  }
  void run(int start) {
    memset(used, 0, sizeof(used));
    memset(dist, 0x3f, sizeof(dist));
    flag = false;
    dist[1] = 0;
    spfa(1);
  }
} spfa;
