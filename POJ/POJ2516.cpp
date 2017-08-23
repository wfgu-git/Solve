/*
教练我要打ACM!
*/
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 200;
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

} min_cost;

int n, m, k;
int need[maxn][maxn], need_sum[maxn];
int supply[maxn][maxn], supply_sum[maxn];
void work() {
  memset(need_sum, 0, sizeof(need_sum));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= k; ++j) {
      scanf("%d", &need[i][j]);
      need_sum[j] += need[i][j];
    }
  }
  memset(supply_sum, 0, sizeof(supply_sum));
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= k; ++j) {
      scanf("%d", &supply[i][j]);
      supply_sum[j] += supply[i][j];
    }
  }
  int s = 0;
  int t = n + m + 1;
  bool flag = true;
  int ans = 0;
  for (int g = 1; g <= k; ++g) {
    min_cost.init(n + m + 5);
    if (need_sum[g] > supply_sum[g]) flag = false;
    for (int i = 1; i <= n; ++i) {
      min_cost.add_edge(s, i, need[i][g], 0);
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        int x;
        scanf("%d", &x);
        min_cost.add_edge(i, j + n, inf, x);
      }
    }
    for (int i = 1; i <= m; ++i) {
      min_cost.add_edge(i + n, t, supply[i][g], 0);
    }
    if (flag) {
      ans += min_cost.run(s, t);
    }
  }

  printf("%d\n", flag ? ans : -1);
}
int main() {
  freopen("/home/wfgu/solve/data.in", "r", stdin);
  while (scanf("%d%d%d", &n, &m, &k) != EOF && (n + m + k)) {
    work();
  }
  return 0;
}
