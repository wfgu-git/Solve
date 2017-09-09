/*
教练我想打ACM！
*/
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


typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 20;
const int moder = 1e9 + 7;

int vis[maxn], mu[maxn], prime[maxn], tot;
void Mobius () {
  memset(vis, 0, sizeof(vis));
  mu[1] = 1;
  tot = 0;
  for (int i = 2; i < maxn; ++i) {
    if (!vis[i]) {
      prime[tot++] = i;
      mu[i] = -1;
    }
    for (int j = 0; j < tot && i * prime[j] < maxn; ++j) {
      vis[i * prime[j]] = 1;
      if (i % prime[j] == 0) {
        mu[i * prime[j]] = 0;
        break;
      } else {
        mu[i * prime[j]] = -mu[i];
      }
    }
  }
}
ll mod_pow(ll x, ll n) {
  ll base = x, ret = 1;
  while (n) {
    if (n & 1) {
      ret = ret * base % moder;
    }
    base = base * base % moder;
    n >>= 1;
  }
  return ret;
}
int n;
int cont[maxn * 2 + 5];
int g[maxn];
int main() {
  // freopen("/home/wfgu/Documents/solve/data.in", "r", stdin);
  Mobius();
  int T;
  in(T);
  for (int cas = 1; cas <= T; ++cas) {
    in(n);
    memset(cont, 0, sizeof(cont));
    int up = 0x3f3f3f3f;
    for (int i = 1; i <= n; ++i) {
      int x;
      in(x);
      up = min(up, x);
      ++cont[x];
    }
    for (int i = 1; i < maxn * 2; ++i) {
      cont[i] += cont[i - 1];
    }
    for (int i = 2; i <= up; ++i) {
      ll num = 1;
      for (int j = 1; j * i <= maxn; ++j) {
        num *= mod_pow(j, cont[(j + 1) * i - 1] - cont[j * i - 1]);
        num %= moder;
      }
      g[i] = num;
    }
    ll ans = 0;
    for (int i = 2; i <= up; ++i) {
      for (int j = 1; j * i < maxn; ++j) {
        ans += mu[j] * g[i * j];
        ans %= moder;
      }
    }

    out_str("Case #"); out_int(cas); out_str(": "); out_str(to_string(ans).c_str()); out_str("\n");
  }
  write();
}
