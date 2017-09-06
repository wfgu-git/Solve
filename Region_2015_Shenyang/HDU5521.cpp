/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 20;

// 加强版
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
inline void out_str(char *s) {
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

struct Edge {
  int from, to;
  ll dist;
} ;
struct HeapNode {
  ll d;
  int u;
  bool operator < (const HeapNode& rhs) const {
    return d > rhs.d;
  }
} ;
struct Dijkstra {
  int n, m;
  vector<Edge> edges;
  vector<int> G[maxn];
  bool done[maxn];
  ll d[maxn];
  int p[maxn];
  void init(int n) {
    this->n = n;
    for (int i = 1; i <= n; ++i) G[i].clear();
    edges.clear();
  }
  void add_edge(int from, int to, int dist) {
    edges.push_back((Edge){from, to, dist});
    m = edges.size();
    G[from].push_back(m - 1);
  }
  void run(int s) {
    priority_queue<HeapNode> Q;
    for (int i = 1; i <= n; ++i) d[i] = inf;
    d[s] = 0;
    memset(done, 0, sizeof(done));
    Q.push((HeapNode){0, s});
    while (!Q.empty()) {
      HeapNode x = Q.top(); Q.pop();
      int u = x.u;
      if (done[u]) continue;
      done[u] = true;
      for (int i = 0; i < G[u].size(); ++i) {
        Edge& e = edges[G[u][i]];
        if (d[e.to] > d[u] + e.dist) {
          d[e.to] = d[u] + e.dist;
          p[e.to] = G[u][i];
          Q.push((HeapNode){d[e.to], e.to});
        }
      }
    }
  }
} ;
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  int T;
  in(T);
  Dijkstra B, E;
  for (int cas = 1; cas <= T; ++cas) {
    int n, m;
    in(n); in(m);
    B.init(n + m);
    E.init(n + m);
    for (int i = 1; i <= m; ++i) {
      int k, t;
      in(t); in(k);
      for (int v, j = 0; j < k; ++j) {
        in(v);
        B.add_edge(v, n + i, t);
        B.add_edge(n + i, v, 0);
        E.add_edge(v, n + i, t);
        E.add_edge(n + i, v, 0);
      }
    }
    B.run(1);
    E.run(n);
    ll ret = 0xffffffffL;
    for (int i = 1; i <= n; ++i) {
      ret = min(ret, max(E.d[i], B.d[i]));
    }
    if (ret == inf) {
      cout << "Case #" << cas << ": " << "Evil John" << endl;
      continue;
    }

    bool fi = true;
    cout << "Case #" << cas << ": " << ret << endl;
    for (int i = 1; i <= n; ++i) {
      if (max(B.d[i], E.d[i]) == ret) {
        if (fi) {
          cout << i;
          fi = false;
        } else {
          cout << " " << i;
        }
      }
      if (i == n) cout << endl;
    }
  }
  return 0;
}
