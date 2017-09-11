/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

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
const int maxn = 10000 + 20;
const int mxlg = 20 + 2;

int N, Q;
vector<int> G[maxn];
int depth[maxn];
int fa[mxlg][maxn];
int L[maxn];
int R[maxn];
int arc[maxn];
int dfs_clock;
set<pii> edges;
set<int> Qs[maxn];
vector<int> lcas;
void dfs_init(int u,int p, int d) {
  L[u] = ++dfs_clock;
  arc[L[u]] = u;
  fa[0][u] = p;
  depth[u] = d;
  for (int v : G[u]) {
    if (v != p) {
      dfs_init(v, u, d + 1);
    }
  }
  R[u] = dfs_clock;
}
void LCA_init() {
  dfs_clock = 0;
  dfs_init(0, -1, 0);
  for (int k = 0; k + 1 < mxlg; ++k) {
    for (int v = 0; v <= N; ++v) {
      if (fa[k][v] < 0) {
        fa[k + 1][v] = -1;
      } else {
        fa[k + 1][v] = fa[k][fa[k][v]];
      }
    }
  }
}
int LCA(int u, int v) {
  if (depth[u] > depth[v]) {
    swap(u, v);
  }
  for (int k = mxlg - 1; k >= 0; --k) {
    if ((depth[v] - depth[u]) >> k & 1) {
      v = fa[k][v];
    }
  }
  if (v == u) return u;
  for (int k = mxlg - 1; k >= 0; --k) {
    if (fa[k][v] != fa[k][u]) {
      v = fa[k][v];
      u = fa[k][u];
    }
  }
  return fa[0][u];
}
void add_edge(int from, int to) {
  G[from].push_back(to);
  G[to].push_back(from);
}
void init() {
  for (int i = 0; i <= N; ++i) {
    Qs[i].clear();
    G[i].clear();
  }
  edges.clear();
  lcas.clear();
}
bool comp(int x, int y) {
  return depth[x] > depth[y];
}
int solve() {
  set<int> tmp({lcas.begin(), lcas.end()});
  int ret = 0;
  for (int x : tmp) {
    int flag = 0;
    for (int i = L[x]; i <= R[x]; ++i) {
      if (Qs[arc[i]].size()) {
        flag = 1;
        for (int y : Qs[arc[i]]) {
          Qs[y].erase(arc[i]);
        }
        Qs[arc[i]].clear();
      }
    }
    ret += flag;
  }
  return ret;
}
int main() {
  // freopen("/home/wfgu/Documents/solve/data.in", "r", stdin);
  // ios::sync_with_stdio(false);
  // cin.tie(0);

  while (in(N)) {
    init();
    int u, v;
    for (int i = 0; i < N; ++i) {
      in(u); in(v);
      add_edge(u, v);
    }
    LCA_init();
    in(Q);
    for (int i = 0; i < Q; ++i) {
      in(u); in(v);
      // edges.insert({u, v});
      Qs[u].insert(v);
      Qs[v].insert(u);
      lcas.push_back(LCA(u, v));
    }
    sort(lcas.begin(), lcas.end(), comp);
    out_int(solve()); out_char('\n');
  }
  write();
}
