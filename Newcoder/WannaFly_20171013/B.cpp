/*
教练我想打ACM！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;

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

int a[maxn];
int pxor[maxn];
vector<pair<int, int> > vxor[(1 << 17) + 1];
set<int> val;
int main() {
#ifndef ONLINE_JUDGE
  freopen("/home/wfgu/Documents/solve/data.in", "r", stdin);
  freopen("/home/wfgu/Documents/solve/data.out", "w", stdout);
#endif

  int n;
  in(n);
  pxor[0] = 0;
  for (int i = 1; i <= n; ++i) {
    in(a[i]);
    pxor[i] = pxor[i - 1] ^ a[i];
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = i; j <= n; ++j) {
      int tmp = pxor[j] ^ pxor[i - 1];
      vxor[tmp].push_back({i, j});
      val.insert(tmp);
    }
  }
  ll ans = 0;
  for (int x : val) {
    sort(vxor[x].begin(), vxor[x].end());
    for (pair<int, int> & v : vxor[x]) {
      int cont = vxor[x].end() - upper_bound(vxor[x].begin(), vxor[x].end(), make_pair(v.second, inf));
      ans += cont;
    }
  }
  out_str(to_string(ans).c_str());
  out_char('\n');
  write();
}