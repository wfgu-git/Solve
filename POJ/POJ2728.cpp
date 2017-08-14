#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>
using namespace std;
const double inf = 0x3f3f3f3f;
const int maxn = 1000 + 20;


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

struct Prim {
  double cost[maxn][maxn];
  double mincost[maxn];
  bool used[maxn];
  int V;

  void init(int n) {
    this->V = n;
    // memset(cost, 0, sizeof(cost));
  }
  double run() {
    for (int i = 1; i <= V; ++i) {
      mincost[i] = inf;
      used[i] = false;
    }
    mincost[1] = 0;
    double ret = 0;

    while (true) {
      int v = -1;
      for (int u = 1; u <= V; ++u) {
        if (!used[u] && (v == -1 || mincost[u] < mincost[v])) {
          v = u;
        }
      }
      if (v == -1) break;
      used[v] = true;
      ret += mincost[v];
      for (int u = 1; u <= V; ++u) {
        mincost[u] = min(mincost[u], cost[v][u]);
      }
    }
    return ret;
  }
} prim;
int N;
int xx[maxn], yy[maxn], hh[maxn];
double pre_dist[maxn][maxn];
double mid;
inline double square(const double& x) {return x * x;}
inline double get_dis(int x, int y) {
  return sqrt(square(xx[x] - xx[y]) + square(yy[x] - yy[y]));
}
bool check() {
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= N; ++j) {
      prim.cost[i][j] = fabs(hh[i] - hh[j]) - mid * pre_dist[i][j];
    }
  }
  return prim.run() <= 0;
}
inline void work() {
  prim.init(N);
  for (int i = 1; i <= N; ++i) {
    // scanf("%d%d%d", xx + i, yy + i, hh + i);
    in(xx[i]); in(yy[i]); in(hh[i]);
  }
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= N; ++j) {
      pre_dist[i][j] = get_dis(i, j);
    }
  }
  double l = 0.0, r = 0x3f3f3f3f;
  for (int i = 0; i < 50; ++i) {
    mid = (l + r) / 2.0;
    if (check()) {
      r = mid;
    } else {
      l = mid;
    }
  }
  printf("%.3f\n", (double)r);
}
int main() {
  // freopen("data.in", "r", stdin);
  while (in(N) && N) {
    work();
  }
  return 0;
}
