/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 2000000 + 20;

int N, L;
struct players {
  int tid, v, pos;

  bool operator < (const players& rhs) const {
    return pos < rhs.pos;
  }
} ;
struct INFO {
  int x, y;
  double t;

  bool operator < (const INFO& rhs) const {
    return t > rhs.t;
  }
} ;
double calc_time(players& x, players& y) {
  double dx = (y.pos - x.pos + L) % L;
  double dv = x.v - y.v;
  if (dv < 0) {
    dv = -dv;
    dx = L - dx;
  }
  return dx / dv;
}
bool vis[maxn];
int lef[maxn], rig[maxn];
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

int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  // ios::sync_with_stdio(false);
  // cin.tie(0);

  int T;
  // cin >> T;
  in(T);
  for (int cas = 1; cas <= T; ++cas) {
    // cin >> N >> L;
    in(N); in(L);
    vector<players> gays(N);
    for (int i = 0; i < N; ++i) {
      int d;
      // cin >> d;
      in(d);
      gays[i].tid = i;
      gays[i].pos = d;
    }
    for (int i = 0; i < N; ++i) {
      int v;
      // cin >> v;
      in(v);
      gays[i].v = v;
    }
    sort(gays.begin(), gays.end());

    // memset(lef, -1, sizeof(lef));
    // memset(rig, -1, sizeof(rig));
    priority_queue<INFO> Q;
    for (int i = 0; i < N; ++i) {
      double t = calc_time(gays[i], gays[(i + 1) % N]);
      Q.push({i, ((i + 1) % N), t});
      lef[i] = (i - 1 + N) % N;
      rig[i] = (i + 1) % N;
    }

    memset(vis, 0, sizeof(vis));
    while (!Q.empty()) {
      INFO now = Q.top(); Q.pop();
      int x = now.x;
      int y = now.y;
      if (vis[x] || vis[y]) continue;
      if (lef[x] == y && rig[x] == y) break;

      if (gays[x].tid> gays[y].tid) {
        vis[y] = true;
        rig[x] = rig[y];
        lef[rig[y]] = x;
        Q.push({x, rig[x], calc_time(gays[x], gays[rig[x]])});
      } else {
        vis[x] = true;
        lef[y] = lef[x];
        rig[lef[x]] = y;
        Q.push({lef[y], y, calc_time(gays[lef[y]], gays[y])});
      }
    }

    INFO ret = Q.top();
    int x = ret.x;
    int y = ret.y;

    int dx = (gays[y].pos - gays[x].pos + L) % L;
    int dv = gays[x].v - gays[y].v;
    if (dv < 0) {
      dv = -dv;
      dx = L - dx;
    }
    int g = __gcd(dx, dv);
    dx /= g;
    dv /= g;
    // cout << dx << "/" << dv << endl;
    out_int(dx); out_char('/'); out_int(dv); out_char('\n');
  }
  write();
  return 0;
}
