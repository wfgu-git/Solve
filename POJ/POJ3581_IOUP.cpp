/*
教练我要打ACM!
*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
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

const int inf = 0x3f3f3f3f;
const int maxn = 500000 + 20;

int n, k;
int tmp[maxn];
int rnk[maxn];
bool comp(int i, int j) {
  if (rnk[i] != rnk[j]) {
    return rnk[i] < rnk[j];
  } else {
    int ri = i + k <= n ? rnk[i + k] : -1;
    int rj = j + k <= n ? rnk[j + k] : -1;
    return ri < rj;
  }
}
// void build(const string& S, int *sa) {
void build(int *S, int n, int* sa) {
  for (int i = 0; i <= n; ++i) {
    sa[i] = i;
    rnk[i] = i < n ? S[i] : -1;
  }
  for (k = 1; k <= n; k *= 2) {
    sort(sa, sa + n + 1, comp);
    tmp[sa[0]] = 0;
    for (int i = 1; i <= n; ++i) {
      tmp[sa[i]] = tmp[sa[i - 1]] + (comp(sa[i - 1], sa[i]) ? 1 : 0);
    }
    for (int i = 0; i <= n; ++i) {
      rnk[i] = tmp[i];
    }
  }
}
int str[maxn];
int rev[maxn];
int sa[maxn];
int main() {
  in(n);
  for (int i = 0; i < n; ++i) {
    in(str[i]);
  }
  reverse_copy(str, str + n, rev);
  build(rev, n, sa);
  int p1;
  for (int i = 0; i < n; ++i) {
    p1 = n - sa[i];
    if (p1 >= 1 && n - p1 >= 2) {
      break;
    }
  }
  int m = n - p1;
  for (int i = 0, j = m; j < n; ++j, ++i) {
    rev[i] = str[j];
    rev[i + n - m + 1] = str[j];
  }
  reverse_copy(str + p1, str + n, rev);
  reverse_copy(str + p1, str + n, rev + m);
  build(rev, m * 2, sa);
  int p2;
  for (int i = 0; i <= 2 * m; ++i) {
    p2 = p1 + m -sa[i];
    if (p2 - p1 >= 1 && n - p2 >= 1) {
      break;
    }
  }
  reverse(str, str + p1);
  reverse(str + p1, str + p2);
  reverse(str + p2, str + n);
  for (int i = 0; i < n; ++i) {
    out_int(str[i]);
    out_char('\n');
  }
  write();
  return 0;
}
