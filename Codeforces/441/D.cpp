/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 300000 + 20;

#define lson o << 1
#define rson o << 1 | 1

int n;
int pos[maxn];
vector<int> ans;
string now;
struct SegTree {
  struct node {
    int l, r, sum;
    bool ok;
  } a[maxn << 2];
  void push_up(int o) {
    a[o].sum = a[lson].sum + a[rson].sum;
    if (a[o].sum == a[o].r - a[o].l) {
      a[o].ok = true;
    }
  }
  void build(int l, int r, int o = 1) {
    a[o] = {l, r, 0, false};
    if (l + 1 == r) {
      return;
    }
    int m = (l + r) / 2;
    build(l, m, lson);
    build(m, r, rson);
    push_up(o);
  }
  void update(int p, int o = 1) {
    if (p == a[o].l && a[o].l + 1 == a[o].r) {
      a[o].sum = 1;
      a[o].ok = true;
      return;
    }
    int m = (a[o].l + a[o].r) / 2;
    if (p < m) {
      update(p, lson);
    } else {
      update(p, rson);
    }
    push_up(o);
  }
  bool query(int l, int r, int o = 1) {
    if (l <= a[o].l && a[o].r <= r) {
      return a[o].ok;
    }
    int m = (a[o].l + a[o].r) / 2;
    int ret = 1;
    if (l < m) {
      ret &= query(l, r, lson);
    }
    if (r > m) {
      ret &= query(l, r, rson);
    }
    return ret;
  }
} seg;
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
#ifndef ONLINE_JUDGE
  freopen("/home/wfgu/Documents/solve/data.in", "r", stdin);
  freopen("/home/wfgu/Documents/solve/data.out", "w", stdout);
#endif
  // ios::sync_with_stdio(false);
  // cin.tie(0);

  // cin >> n;
  in(n);
  for (int i = 1; i <= n; ++i) {
    // cin >> pos[i];
    in(pos[i]);
  }
  seg.build(1, n + 1);
  ans.push_back(1);
  bool flag = 0;
  for (int i = 1; i < n; ++i) {
    seg.update(pos[i]);
    if (pos[i] == n) {
      flag = 1;
    }
    if (!flag) {
      ans.push_back(i + 1);
      continue;
    }
    int l = inf, r = n;
    int lb = 1, ub = n;
    while (lb <= ub) {
      int mid = (lb + ub) / 2;
      if (seg.query(mid, r + 1)) {
        l = mid;
        ub = mid - 1;
      } else {
        lb = mid + 1;
      }
    }
    if (l == inf) {
      ans.push_back(i + 1);
    } else {
      int tmp = r - l + 1;
      ans.push_back(i - tmp + 1);
    }
  }
  ans.push_back(1);
  for (int x : ans) {
    // cout << x << " ";
    out_int(x); out_char(' ');
  }
  write();
}
