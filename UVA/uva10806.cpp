#include <bits/stdc++.h>
using namespace std;


const int MAXBUF = 10000;
char buf[MAXBUF], *ps = buf, *pe = buf + 1;
inline void rnext() {
  if (++ps == pe)
    pe = (ps = buf) +
         fread(buf, sizeof(char), sizeof(buf) / sizeof(char), stdin);
}

template <class T>
inline bool in(T &ans) {
  ans = 0;
  T f = 1;
  if (ps == pe) return false;  // EOF
  do {
    rnext();
    if ('-' == *ps) f = -1;
  } while (!isdigit(*ps) && ps != pe);
  if (ps == pe) return false;  // EOF
  do {
    ans = (ans << 1) + (ans << 3) + *ps - 48;
    rnext();
  } while (isdigit(*ps) && ps != pe);
  ans *= f;
  return true;
}

const int MAXOUT = 10000;
char bufout[MAXOUT], outtmp[50], *pout = bufout, *pend = bufout + MAXOUT;
inline void write() {
  fwrite(bufout, sizeof(char), pout - bufout, stdout);
  pout = bufout;
}
inline void out_char(char c) {
  *(pout++) = c;
  if (pout == pend) write();
}
inline void out_str(const char *s) {
  while (*s) {
    *(pout++) = *(s++);
    if (pout == pend) write();
  }
}
template <class T>
inline void out_int(T x) {
  if (!x) {
    out_char('0');
    return;
  }
  if (x < 0) x = -x, out_char('-');
  int len = 0;
  while (x) {
    outtmp[len++] = x % 10 + 48;
    x /= 10;
  }
  outtmp[len] = 0;
  for (int i = 0, j = len - 1; i < j; i++, j--) swap(outtmp[i], outtmp[j]);
  out_str(outtmp);
}

const int inf = 0x3f3f3f3f;
const int maxn = 200 + 20;

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
  bool flag;
  void init(int n) {
    this->n = n;
    flag = false;
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
    if (flow == 2) flag = true;
    return cost;
  }

} mcmf;
int N, M;
void work() {
  mcmf.init(N * 2 + 2);
  int s = N + 1;
  int t = N + 2;
  // scanf("%d", &M);
  in(M);
  for (int i = 0; i < M; ++i) {
    int from, to, cost;
    // scanf("%d%d%d", &from, &to, &cost);
    in(from); in(to); in(cost);
    mcmf.add_edge(from - 1, to - 1, 1, cost);
    mcmf.add_edge(to - 1, from - 1, 1, cost);
  }
  mcmf.add_edge(s, 0, 2, 0);
  mcmf.add_edge(N - 1, t, 2, 0);
  int ans = mcmf.run(s, t);
  if (mcmf.flag) {
    // printf("%d\n", ans);
    out_int(ans); out_str("\n");
  } else {
    // printf("%s\n", "Back to jail");
    out_str("Back to jail\n");
  }
}
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  while (in(N)) {
    if (!N) break;
    work();
  }
  write();
  return 0;
}
