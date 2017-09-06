#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int, int> pii;
const int inf = 0x3f3f3f3f;
const int maxn = 50000;
struct Edge {
  int from, to, dist;
  Edge(int u, int v, int d) : from(u), to(v), dist(d) {}
} ;
struct HeapNode {
  int d, u;
  bool operator  < (const HeapNode & rhs) const {
    return d > rhs.d;
  }
};

struct Dijkstra {
  int n, m;
  vector<Edge> edges;
  vector<int> G[maxn];
  bool done[maxn];
  int d[maxn];
  int p[maxn];

  void init(int n) {
    this -> n = n;
    for (int i = 0; i < n; i++) G[i].clear();
    edges.clear();
  }
  void add_edge(int from, int to, int dist) {
    edges.push_back(Edge{from, to, dist});
    m = edges.size();
    G[from].push_back(m-1);
  }
  void run(int s) {
    priority_queue<HeapNode> Q;
    for (int i = 0; i < n; i++) d[i] = inf;
    d[s] = 0;
    memset(done, 0, sizeof(done));
    Q.push((HeapNode){0, s});
    while (!Q.empty()) {
      HeapNode x = Q.top(); Q.pop();
      int u = x.u;
      if (done[u]) continue;
      done[u] = true;
      for (int i = 0; i < (int)G[u].size(); i++) {
        Edge &e = edges[G[u][i]];
        if (d[e.to] > d[u] + e.dist /* && d[u] + e.dist <= c */) {
          d[e.to] = d[u] + e.dist;
          // if (p[e.to]) d[e.to] = 0;
          p[e.to] = G[u][i];
          Q.push((HeapNode){d[e.to], e.to});
        }
      }
    }
  }
} ;
