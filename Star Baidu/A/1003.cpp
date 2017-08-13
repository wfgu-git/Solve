#include <bits/stdc++.h>
using namespace std;

const int MAXBUF = 100000;
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
const int MAXOUT = 100000;
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



#define lson o << 1
#define rson o << 1 | 1
typedef pair<int, long long> pii;
const int maxn = 500000 + 20;
const int mxlg = 30;
vector<pii> G[maxn];
int root;
int fa[mxlg][maxn];
int depth[maxn];
long long dist[maxn];
void add_edge(int u, int v, int d) {
  G[u].push_back({v, d});
  G[v].push_back({u, d});
}

void dfs(int u, int p, int d) {
  fa[0][u] = p;
  depth[u] = d;
  for (const pii& x : G[u]) {
    int v = x.first;
    long long w = x.second;
    if (v != p) {
      dist[v] = dist[u] + w;
      dfs(v, u, d + 1);
    }
  }
}
void LCA_init(int V) {
  root = 1;
  dist[root] = 0;
  dfs(root, -1, 0);
  for (int k = 0; k + 1 < mxlg; ++k) {
    for (int v = 1; v <= V; ++v) {
      if (fa[k][v] < 0) fa[k + 1][v] = -1;
      else fa[k + 1][v] = fa[k][fa[k][v]];
    }
  }
}
int lca(int u, int v) {
  if (depth[u] > depth[v]) swap(u, v);
  for (int k = 0; k < mxlg; k++) {
    if ((depth[v] - depth[u]) >> k & 1) {
      v = fa[k][v];
    }
  }
  if (v == u) return u;
  for (int k = mxlg - 1; k >= 0; k--) {
    if (fa[k][u] != fa[k][v]) {
      u = fa[k][u];
      v = fa[k][v];
    }
  }
  return fa[0][u];
}

struct Path {int u, v, lca;} path[maxn];
bool comp(int x, int y) {return depth[x] < depth[y];}
Path Merge(Path x, Path y) {
  static int tmp[10];
  if (x.lca == -1 || y.lca == -1) return (Path){0, 0, 0};
  tmp[0] = lca(x.u, y.u);
  tmp[1] = lca(x.u, y.v);
  tmp[2] = lca(x.v, y.u);
  tmp[3] = lca(x.v, y.v);
  sort(tmp, tmp + 4, comp);
  int upper = max(depth[x.lca], depth[y.lca]);
  int lower = min(depth[x.lca], depth[y.lca]);
  if(depth[tmp[0]] < lower || depth[tmp[2]] < upper) return (Path){0, 0, 0};
  else return (Path){tmp[2], tmp[3], lca(tmp[2], tmp[3])};
}
int nn;
struct Segtree {
  struct node {
    int l, r;
    Path p;
  } a[maxn << 2];
  void push_up(int o) {
    a[o].p = Merge(a[lson].p, a[rson].p);
  }
  void build(int l = 1, int r = nn + 1, int o = 1) {
    a[o].l = l; a[o].r = r;
    if (l + 1 == r) {
      a[o].p = path[l];
      return;
    }
    int m = (l + r) / 2;
    build(l, m, lson);
    build(m, r, rson);
    push_up(o);
  }
  Path query(int l, int r, int o = 1) {
    if (l <= a[o].l && a[o].r <= r) {
      return a[o].p;
    }
    int m = (l + r) / 2;
    Path ret = {0, 0, 0};
    bool flag = false;
    if (l < m) {
      flag = true;
      ret = query(l, r, lson);
    }
    if (r > m) {
      if (flag) ret = Merge(ret, query(l, r, rson));
      else ret = query(l, r, rson);
    }
    return ret;
  }
} st;
int N, M, Q;
inline void work() {
  for (int i = 1; i <= N; ++i) G[i].clear();
  for (int i = 1; i < N; ++i) {
    static int x, y, z;
    in(x); in(y); in(z);
    add_edge(x, y, z);
  }
  LCA_init(N);
  in(M);
  for (int i = 1; i <= M; ++i) {
    static int u, v, t;
    in(u); in(v);
    t = lca(u, v);
    path[i] = {u, v, t};
  }
  nn = M;
  st.build();
  in(Q);
  for (int i = 0; i < Q; ++i) {
    static int l, r;
    in(l); in(r);
    Path ret = st.query(l, r + 1);
    long long ans = dist[ret.u] + dist[ret.v] - 2 * dist[ret.lca];
    // printf("%lld\n", dist[ret.u] + dist[ret.v] - 2 * dist[ret.lca]);
    out_int(ans); out_char('\n');
  }
}
int main() {
  freopen("data.in", "r", stdin);
  while (in(N)) {
    work();
  }
  write();
  return 0;
}
