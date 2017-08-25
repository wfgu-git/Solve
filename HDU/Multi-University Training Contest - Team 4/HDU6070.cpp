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


#define lson o << 1
#define rson o << 1 | 1
const int maxn = 60000 + 20;
int N;
struct Segtree {
  struct node {
    int l, r;
    double v, lazy;
  } a[maxn << 2];

  inline void push_down(int o) {
    if (a[o].lazy) {
      a[lson].lazy += a[o].lazy;
      a[rson].lazy += a[o].lazy;
      a[lson].v += a[o].lazy;
      a[rson].v += a[o].lazy;
      a[o].lazy = 0;
    }
  }

  inline void push_up(int o) {
    a[o].v = min(a[lson].v, a[rson].v);
  }

  void build(int l = 1, int r = N + 1, int o = 1) {
    a[o].l = l; a[o].r = r; a[o].lazy = 0; a[o].v = 0;
    if (l + 1 == r) {
      return;
    }
    int m = (l + r) / 2;
    build(l, m, lson);
    build(m, r, rson);
    push_up(o);
  }

  void update(int l, int r, double k, int o = 1) {
    if (l <= a[o].l && a[o].r <= r) {
      a[o].lazy += k;
      a[o].v += k;
      return;
    }
    push_down(o);
    int m = (a[o].l + a[o].r) / 2;
    if (l < m) update(l, r, k, lson);
    if (r > m) update(l, r, k, rson);
    push_up(o);
  }

  double query(int l, int r, int o = 1) {
    if (l <= a[o].l && a[o].r <= r) {
      return a[o].v;
    }
    push_down(o);
    int m = (a[o].l + a[o].r) / 2;
    double ret = 0x3f3f3f3f;
    if (l < m) ret = query(l, r, lson);
    if (r > m) ret = min(ret, query(l, r, rson));
    push_up(o);
    return ret;
  }
} st;
int pre[maxn], last[maxn];
bool check(double x) {
  st.build(x);
  for (int i = 1; i <= N; ++i) {
    st.update(pre[i] + 1, i + 1, 1);
    st.update(1, i + 1, -x);
    if (st.query(1, i + 1) <= 0) return true;
  }
  return false;
}
void work() {
  in(N);
  memset(pre, 0, sizeof(pre));
  memset(last, 0, sizeof(last));
  for (int i = 1; i <= N; ++i) {
    int x;
    in(x);
    pre[i] = last[x];
    last[x] = i;
  }
  double l = 0, r = 1;
  for (int i = 0; i < 20; ++i) {
    double mid = (l + r) / 2.0;
    if (check(mid)) {
      r = mid;
    } else {
      l = mid;
    }
  }
  out_str(to_string(r).c_str());
  out_char('\n');
}
int main() {
  // freopen("data.in", "r", stdin);
  int T;
  in(T);
  for (int cas = 1; cas <= T; ++cas) {
    work();
  }
  write();
  return 0;
}
