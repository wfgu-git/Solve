/*
教练我要打ACM!
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

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
const int maxn = 1000000 + 20;

int n;
int a[maxn * 2];
int b[maxn * 2];
int main() {
  // freopen("/home/wfgu/solve/data.in", "r", stdin);
  // ios::sync_with_stdio(false);
  // cin.tie(0);

  while (in(n)) {
    for (int i = 0; i < n; ++i) {
      // cin >> a[i];
      in(a[i]);
    }
    for (int i = 0; i < n; ++i) {
      // cin >> b[i];
      in(b[i]);
    }
    for (int i = 0; i < n; ++i) {
      a[i + n] = a[i];
      b[i + n] = b[i];
    }

    int L = 0;
    int l = 0, r = 0, tlen = 0, mxlen = inf;
    ll sum, add, sub;
    sum = add = sub = 0;

    while (r <= 2 * n && l <= r) {
      if (tlen == n) {
        if (sum < add || (sum == add && tlen < mxlen))
          sum = add, mxlen = tlen, L = l;
        tlen--;
        add -= a[l];
        sub -= b[l];
        l++;
      } else if (add >= sub) {
        add += a[r];
        sub += b[r];
        tlen++;
        r++;
      } else {
        if (sum < add || (sum == add && tlen < mxlen))
          sum = add, mxlen = tlen, L = l;
        if (l == r) {
          l++, r++;
          add = 0, sub = 0, tlen = 0;
          continue;
        }
        tlen--;
        add -= a[l];
        sub -= b[l];
        l++;
      }
    }
    out_int(L); out_str("\n");
  }
  write();
  return 0;
}
