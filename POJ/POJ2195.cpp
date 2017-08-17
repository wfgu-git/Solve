#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
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
char grid[maxn][maxn];
inline int get_dist(const pair<int, int>&p, const pair<int, int>& q) {
  return abs(p.first - q.first) + abs(p.second - q.second);
}
vector<pair<int, int> > man, house;
void work() {
  int tot_man, tot_house;
  for (int i = 0; i < N; ++i) {
    scanf("%s", grid[i]);
  }

  int tot = 0;
  man.clear(); house.clear();
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (grid[i][j] == 'm') {
        ++tot;
        man.push_back(make_pair(i, j));
      } else if (grid[i][j] == 'H') {
        ++tot;
        house.push_back(make_pair(i, j));
      }
    }
  }

  mcmf.init(tot * 5);
  int tmp = man.size();
  for (int i = 0; i < (int)man.size(); ++i) {
    mcmf.add_edge(0, i + 1, 1, 0);
    for (int j = 0; j < (int)house.size(); ++j) {
      mcmf.add_edge(i + 1, j + 1 + tmp, 1, get_dist(man[i], house[j]));
    }
  }
  for (int i = 0; i < (int)house.size(); ++i) {
    mcmf.add_edge(i + 1 + tmp, tot + 1, 1, 0);
  }
  printf("%d\n", mcmf.run(0, tot + 1));
}
int main() {
  // freopen("data.in", "r", stdin);
  while (scanf("%d%d", &N, &M) != EOF && (N + M)) {
    work();
  }
  return 0;
}
