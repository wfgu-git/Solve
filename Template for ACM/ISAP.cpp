#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;
typedef long double ld;

const int maxn = 5000;
const int inf = 0x3f3f3f3f;

struct Edge {
  int from, to, cap, flow;
};
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
    G[from].push_back(m - 2);
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
