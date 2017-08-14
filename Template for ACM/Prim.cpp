#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 500;
struct Naive_Prim {
  int cost[maxn][maxn];
  int mincost[maxn];
  bool used[maxn];
  int V;

  void init(int n) {
    this->V = n;
    // memset(cost, 0, sizeof(cost));
  }
  int run() {
    for (int i = 1; i <= V; ++i) {
      mincost[i] = inf;
      used[i] = false;
    }
    mincost[1] = 0;
    int ret = 0;

    while (true) {
      int v = -1;
      for (int u = 1; u <= V; ++u) {
        if (!used[u] && (v == -1 || mincost[u] < mincost[v])) {
          v = u;
        }
      }
      if (v == -1) break;
      used[v] = true;
      ret += mincost[v];
      for (int u = 1; u <= V; ++u) {
        mincost[u] = min(mincost[u], cost[v][u]);
      }
    }
    return ret;
  }
} prim;

struct Edge {
  int to, dist;
  bool operator < (const Edge & rhs) const {
    return dist > rhs.dist;
  }
} ;
struct STL_Prim {
  bool used[maxn];
  int V;
  vector<Edge> G[maxn];
  void add_edge(int u, int v, int d) {
    G[u].push_back({v, d});
    G[v].push_back({u, d});
  }
  void init(int n) {
    this->V = n;
    for (int i = 1; i <= n; ++i) {
      G[i].clear();
      used[i] = false;
    }
  }
  int run() {
    priority_queue<Edge> Q;
    for (int i = 0; i < (int)G[1].size(); ++i) {
      Q.push(G[1][i]);
    }
    used[1] = true;
    int ret = 0;
    int cont = V - 1;
    while (!Q.empty() && cont) {
      Edge now = Q.top(); Q.pop();
      if (used[now.to]) continue;
      used[now.to] = true;
      ret += now.dist;
      --cont;
      for (int i = 0; i < (int)G[now.to].size(); ++i) {
        Edge tmp = G[now.to][i];
        if (!used[tmp.to]) {
          Q.push(tmp);
        }
      }
    }
    return ret;
  }
} ;
