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

const int maxn = 100000 + 20;
vector<int> G[maxn];
int fa[maxn], sz[maxn], depth[maxn];
void add_edge(int u, int v) {
  G[u].push_back(v);
  G[v].push_back(u);
}
int N;
double ans;
void dfs1(int u, int Fa, int d) {
  sz[u] = 0;
  fa[u] = Fa;
  depth[u] = d;
  for (const int& v : G[u]) {
    if (v == Fa) continue;
    dfs1(v, u, d + 1);
    sz[u]++;
  }
}
void dfs2(int u, double p) {
  if (sz[u] == 0) {
    ans += (1.0 * depth[u] * p);
    return;
  }
  for (const int &v : G[u]) {
    if (v == fa[u]) continue;
    dfs2(v, p * (1.0 / sz[u]));
  }
}
inline void work() {
  ans = 0L;
  for (int i = 1; i < N; ++i) {
    static int u, v;
    // scanf("%d%d", &u, &v);
    in(u); in(v);
    add_edge(u, v);
  }
  dfs1(1, 1, 0); dfs2(1, 1);
  printf("%.9f\n", ans);
}
int main() {
  in(N);
  work();
  return 0;
}
