/*
教练我要打ACM!
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <map>
using namespace std;

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

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;

const int inf = 0x3f3f3f3f;
const int maxn = 3000 + 20;

int n, m;
int G[maxn][maxn];
int dist[maxn];
int vis[maxn];
int del[maxn];

int Stoer_Wagner() {
  int minCut = inf;
  int tmp;
  int pre;
  int s = 1;  // 源点
  memset(del, 0, sizeof(del));

  for (int T = 1; T < n; ++T) { // n - 1次最大生成树
    for (int i = 1; i <= n; ++i) if (!del[i]) {
      dist[i] = G[s][i];
    }
    memset(vis, 0, sizeof(vis));
    vis[s] = 1;
    int t = s;
    for (int i = 1; i <= n - T; ++i) { // 每次剩下 n - T + 1 个结点
      tmp = -inf;
      pre = t;
      t = 0;
      for (int j = 1; j <= n; ++j) {
        if (!del[j] && !vis[j] && dist[j] > tmp) {
          t = j;
          tmp = dist[j];
        }
      }

      if (!t) return 0;  // 不连通

      vis[t] = 1;
      for (int j = 1; j <= n; ++j) {
        if (!del[j] && !vis[j]) {
          dist[j] += G[t][j];
        }
      }
    }

    minCut = min(minCut, dist[t]);
    del[t] = 1; // 删除t点

    // 合并t点和源点
    for (int i = 1; i <= n; ++i) {
      if (!del[i] && i != pre) {
        G[pre][i] += G[t][i];
        G[i][pre] = G[pre][i];
      }
    }
  }
  return minCut;
}
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);

  while (in(n)) {
    in(m);
  // while (cin >> n >> m) {
    memset(G, 0, sizeof(G));
    for (int i = 0; i < m; ++i) {
      static int u, v, c;
      in(u); in(v); in(c);
      // cin >> u >> v >> c;
      if (u == v) continue;
      G[u + 1][v + 1] += c;
      G[v + 1][u + 1] += c;
    }
    int ans = Stoer_Wagner();
    // cout << ans << endl;
    out_int(ans); out_char('\n');
  }
  write();
  return 0;
}
