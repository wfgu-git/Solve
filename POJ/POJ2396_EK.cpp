/*
教练我要打ACM!
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 500;
int arc[maxn][30];
struct Edge {
  int from, to, cap, flow;
  // Edge(int u, int v, int c, int f) : from(u), to(v), cap(c), flow(f) {}
} ;


struct EdmondsKarp {
  int n, m;
  vector<Edge> edges;  // 边数的两倍
  vector<int> G[maxn];
  int a[maxn];  // 当前起点到i的可改进量
  int p[maxn];  // 最短路树上p的入弧编号

  void init(int n) {
    for (int i = 0; i <= n; ++i)  G[i].clear();
    edges.clear();
  }

  void add_edge(int from, int to, int cap) {
    edges.push_back((Edge){from, to, cap, 0});
    edges.push_back((Edge){to, from, 0, 0});
    m = edges.size();
    G[from].push_back(m - 2); arc[from][to] = m - 2;
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

int n, m;
int sum_row[maxn], sumr;
int sum_col[maxn], sumc;
int lb[maxn][30];
int ub[maxn][30];
string No = "IMPOSSIBLE";
void work(int kase) {
  if (kase > 1)  cout << endl;
  sumr = sumc = 0;
  cin >> n >> m;

  max_flow.init(n + m);
  int s = n + m + 1;
  int t = s + 1;
  int S = t + 1;
  int T = S + 1;

  for (int i = 1; i <= n; ++i) {
    cin >> sum_row[i];
  }
  for (int i = 1; i <= m; ++i) {
    cin >> sum_col[i];
  }
  int limit_tot;
  cin >> limit_tot;
  memset(lb, 0, sizeof(lb));
  memset(ub, 0x3f, sizeof(ub));
  bool flag = true;
  for (int i = 0; i < limit_tot; ++i) {
    int xs, xt, ys, yt;
    int a, b, lim;
    char tag;
    cin >> a >> b >> tag >> lim;
    xs = xt = a;
    ys = yt = b;
    if (!a) {xs = 1; xt = n;}
    if (!b) {ys = 1; yt = m;}
    for (int r = xs; r <= xt; ++r) {
      for (int c = ys; c <= yt; ++c) {
        if (tag == '=') {
          if (lb[r][c] > lim || ub[r][c] < lim) flag = false;
          lb[r][c] = ub[r][c] = lim;
        } else if (tag == '>') {
          if (ub[r][c] <= lim) flag = false;
          lb[r][c] = max(lim + 1, lb[r][c]);
        } else if (tag == '<') {
          if (lb[r][c] >= lim) flag = false;
          ub[r][c] = min(lim - 1, ub[r][c]);
        }
      }
    }
  }
  if (!flag) {
    cout << No << endl;
    return;
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      max_flow.add_edge(i, j + n, ub[i][j] - lb[i][j]);
    }
  }
  int sumf = 0;
  for (int i = 1; i <= n + m; ++i) {
    int f = (i <= n ? sum_row[i] : -sum_col[i - n]);
    if (i <= n) {
      for (int j = 1; j <= m; ++j) f -= lb[i][j];
    } else {
      for (int j = 1; j <= n; ++j) f += lb[j][i - n];
    }
    if (f > 0) max_flow.add_edge(s, i, f), sumf += f;
    else max_flow.add_edge(i, t, -f);
  }
  int ans = max_flow.run(s, t);
  if (ans != sumf) {
    cout << No << endl;
    return;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cout << (lb[i][j] + max_flow.edges[arc[i][j]].flow) << (j == m ? '\n' : ' ');
    }
  }
}
int main() {
  freopen("/home/wfgu/solve/data.in", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  for (int cas = 1; cas <= T; ++cas) {
    work(cas);
  }
  return 0;
}
