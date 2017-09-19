/*
教练我想打ACM！
*/
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <vector>
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
const int maxn = 1000000 + 20;

int a[maxn];
struct Deque {
  int val, idx;
  Deque(int v = 0, int x = 0) : val(v), idx(x) {}
} Q[maxn];
int head, tail;
vector<int> Max, Min;
int n, k;
void solve_min() {
  Min.clear();
  head = 1;
  tail = 0;
  for (int i = 1; i < k; ++i) {
    while (head <= tail && Q[tail].val >= a[i]) {
      --tail;
    }
    ++tail;
    Q[tail].val = a[i];
    Q[tail].idx = i;
  }
  for (int i = k; i <= n; ++i) {
    while (head <= tail && Q[tail].val >= a[i]) {
      --tail;
    }
    ++tail;
    Q[tail].val = a[i];
    Q[tail].idx = i;
    while (head <= tail && Q[head].idx < i - k + 1) {
      ++head;
    }
    Min.push_back(Q[head].val);
  }
}
void solve_max() {
  Max.clear();
  head = 1;
  tail = 0;
  for (int i = 1; i < k; ++i) {
    while (head <= tail && Q[tail].val <= a[i]) {
      --tail;
    }
    ++tail;
    Q[tail].val = a[i];
    Q[tail].idx = i;
  }
  for (int i = k; i <= n; ++i) {
    while (head <= tail && Q[tail].val <= a[i]) {
      --tail;
    }
    ++tail;
    Q[tail].val = a[i];
    Q[tail].idx = i;
    while (head <= tail && Q[head].idx < i - k + 1) {
      ++head;
    }
    Max.push_back(Q[head].val);
  }
}
int main() {
  freopen("/home/wfgu/Documents/solve/data.in", "r", stdin);
  // while (scanf("%d%d", &n, &k) != EOF) {
  while (in(n)) {
    in(k);
    for (int i = 1; i <= n; ++i) {
      // scanf("%d", a + i);
      in(a[i]);
    }
    solve_max();
    solve_min();
    for (int i = 0; i < Min.size(); ++i) {
      // printf("%d%c", Min[i], i < Min.size() - 1 ? ' ' : '\n');
      if (i) {
        out_char(' ');
        out_int(Min[i]);
      } else {
        out_int(Min[i]);
      }
    }
    out_char('\n');
    for (int i = 0; i < Max.size(); ++i) {
      // printf("%d%c", Max[i], i < Max.size() - 1 ? ' ' : '\n');
      if (i) {
        out_char(' ');
        out_int(Max[i]);
      } else {
        out_int(Max[i]);
      }
    }
    out_char('\n');
  }
  write();
}
