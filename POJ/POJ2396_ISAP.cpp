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
const int maxn = 300 + 20;
int arc[maxn][30];
struct Edge {
  int from, to, cap, flow;
  // Edge(int u, int v, int c, int f) : from(u), to(v), cap(c), flow(f) {}
} ;

struct ISAP {
  int n, m, s, t;            //结点 边数
  vector<Edge> edges;  //边表
  vector<int> G[maxn];  //邻接表 G[i][j] 结点i的第j条边在e数组中的序号
  bool vis[maxn];  // bfs使用
  int d[maxn];     // 从起点到i的距离
  int cur[maxn];   //当前弧下标
  int p[maxn];     //可增广路上的一条弧
  int num[maxn];   //距离标号计数

  void init(int n) {
    this->n = n;
    for (int i = 0; i <= n; ++i) G[i].clear();
    edges.clear();
  }

  void add_edge(int from, int to, int cap) {
    edges.push_back((Edge){from, to, cap, 0});
    edges.push_back((Edge){to, from, 0, 0});
    m = edges.size();
    G[from].push_back(m - 2); arc[from][to] = m - 2;
    G[to].push_back(m - 1);
  }

  int Augment() {
    int x = t, a = inf;
    while (x != s) {
      Edge& e = edges[p[x]];
      a = min(a, e.cap - e.flow);
      x = edges[p[x]].from;
    }
    x = t;
    while (x != s) {
      edges[p[x]].flow += a;
      edges[p[x] ^ 1].flow -= a;
      x = edges[p[x]].from;
    }
    return a;
  }
  void bfs() {
    for (int i = 0; i <= n; ++i) d[i] = n;
    // memset(vis, 0, sizeof(vis));
    queue<int> Q;
    Q.push(t);
    d[t] = 0;
    // vis[t] = true;
    while (!Q.empty()) {
      int x = Q.front(); Q.pop();
      for (int i = 0; i < G[x].size(); i++) {
        Edge& e = edges[G[x][i]];
        if (!e.cap && d[e.to] == n) {
          // vis[e.to] = true;
          d[e.to] = d[x] + 1;
          Q.push(e.to);
        }
      }
    }
  }

  int run(int s, int t) {
    this->s = s; this->t = t;
    int flow = 0;
    bfs();
    //  met (num, 0); met (d, 0); // 或者bfs
    /*初始标号可以统一设置为0 或者用bfs
    单次运行时效率相差不大 多次求解小规模网络流
    速度会有明显提升*/
    for (int i = 0; i <= n; i++) num[d[i]]++;
    int x = s;
    memset(cur, 0, sizeof(cur));
    while (d[s] < n) {
      if (x == t) {
        flow += Augment();
        x = s;
      }
      bool ok = false;
      for (int i = cur[x]; i < G[x].size(); i++) {
        Edge &e = edges[G[x][i]];
        if (e.cap > e.flow && d[x] == d[e.to] + 1) {
          ok = true;
          p[e.to] = G[x][i];
          cur[x] = i;
          x = e.to;
          break;
        }
      }
      if (!ok) {
        int m = n - 1;
        for (int i = 0; i < G[x].size(); i++) {
          Edge &e = edges[G[x][i]];
          if (e.cap > e.flow) m = min(m, d[e.to]);
        }
        if (--num[d[x]] == 0) break;  // gap优化
        num[d[x] = m + 1]++;
        cur[x] = 0;
        if (x != s) x = edges[p[x]].from;
      }
    }
    return flow;
  }
} max_flow;

int n, m;
int sum_row[maxn];
int sum_col[maxn];
int lb[maxn][30];
int ub[maxn][30];
string No = "IMPOSSIBLE";
void work(int kase) {
  if (kase > 1)  cout << endl;
  cin >> n >> m;

  max_flow.init(n + m);
  int s = 0, t = n + m + 1;
  // int s = n + m + 1;
  // int t = s + 1;
  // int S = t + 1;
  // int T = S + 1;

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
